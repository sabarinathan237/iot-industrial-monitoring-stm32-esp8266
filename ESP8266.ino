#define BLYNK_TEMPLATE_ID "TMPL3HSZu8zbr"
#define BLYNK_TEMPLATE_NAME "stm32f407vgt6"
#define BLYNK_AUTH_TOKEN "FV9-6b1GB3Kh80B0wc6fU76g8v6DtdGl"

#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
#include <SoftwareSerial.h>

/* WiFi */
char ssid[] = "pi";
char pass[] = "raspberry";

/* STM32 UART (RX, TX) */
SoftwareSerial stmSerial(D5, D6); // RX, TX

String serialLine = "";

/* Parsed values */
float tempValue = 0.0;
float humValue = 0.0;
int gasValue = 0;
int ldrValue = 0;
int flameValue = 0;
int distValue = 0;

BlynkTimer timer;

/* ================= PARSER ================= */
void parseSTM32Data(String line)
{
  line.trim();

  float t = 0.0, h = 0.0;
  int g = 0, l = 0, f = 0, d = 0;

  int parsed = sscanf(line.c_str(),
                      "T:%f,H:%f,G:%d,L:%d,F:%d,D:%d",
                      &t, &h, &g, &l, &f, &d);

  if (parsed == 6)
  {
    tempValue = t;
    humValue = h;
    gasValue = g;
    ldrValue = l;
    flameValue = f;
    distValue = d;

    Serial.println("==== DATA RECEIVED ====");
    Serial.println(line);
  }
  else
  {
    Serial.print("Parse Error: ");
    Serial.println(line);
  }
}

/* ================= BLYNK SEND ================= */
void sendToBlynk()
{
  if (!Blynk.connected())
  {
    Serial.println("Blynk not connected!");
    return;
  }

  Blynk.virtualWrite(V0, tempValue);
  Blynk.virtualWrite(V1, humValue);
  Blynk.virtualWrite(V2, gasValue);
  Blynk.virtualWrite(V3, ldrValue);
  Blynk.virtualWrite(V4, flameValue);
  Blynk.virtualWrite(V5, distValue);

  /* Status Logic */
  String status = "NORMAL";

  if (flameValue == 0 || distValue < 10)
  {
    status = "EMERGENCY";
  }
  else if (gasValue > 2000)
  {
    status = "WARNING";
  }

  Blynk.virtualWrite(V6, status);
}

/* ================= SETUP ================= */
void setup()
{
  Serial.begin(115200);      // Debug
  stmSerial.begin(115200);   // STM32 communication

  Serial.println("ESP8266 Starting...");

  Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass);

  timer.setInterval(2000L, sendToBlynk);

  Serial.println("ESP8266 Ready");
}

/* ================= LOOP ================= */
void loop()
{
  Blynk.run();
  timer.run();

  while (stmSerial.available())
  {
    char c = stmSerial.read();

    if (c == '\n')
    {
      parseSTM32Data(serialLine);
      serialLine = "";
    }
    else if (c != '\r')
    {
      serialLine += c;
    }
  }
}
