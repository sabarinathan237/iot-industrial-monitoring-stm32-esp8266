# iot-industrial-monitoring-stm32-esp8266
IoT-Based Industrial Machine Monitoring and Safety System using STM32F407 and ESP8266 with real-time sensor data, hazard detection, and Blynk cloud integration.


# 🌐 **IoT-Based Industrial Machine Monitoring and Safety System**

## Using STM32F407 and ESP8266 (WiFi IoT)

---

## 📌 Abstract

This project presents the design and implementation of an **IoT-Based Industrial Machine Monitoring and Safety System** using the **STM32F407 microcontroller** and the **ESP8266 Wi-Fi module**. The system is developed to provide **real-time monitoring, safety assurance, and remote access** to critical industrial parameters.

The system integrates multiple sensors, including a **DHT11 sensor** for temperature and humidity monitoring, a **gas sensor** for detecting hazardous gases, a **flame sensor** for fire detection, and an **ultrasonic sensor** for distance measurement. The STM32F407 acts as the central processing unit, continuously acquiring and analyzing sensor data to detect abnormal conditions.

For IoT connectivity, the ESP8266 module communicates with the STM32 via USART and transmits real-time data to the **Blynk IoT Cloud platform**. This enables users to monitor system parameters remotely through a mobile or web dashboard.

To ensure safety, the system includes **LED indicators and a buzzer alert mechanism**, which are triggered during critical conditions such as gas leakage, fire detection, or unsafe proximity. The system provides both **local alerts and remote notifications**, enhancing industrial safety and reducing risks.

This solution is **cost-effective, scalable, and industry-relevant**, demonstrating the integration of embedded systems with IoT technology for smart industrial monitoring.

---

## 🏗️ System Architecture

The system consists of the following modules:

* **STM32F407 Controller** → Central processing unit for sensor data acquisition
* **ESP8266 WiFi Module** → IoT communication and cloud connectivity
* **Sensor Module** → DHT11, Gas Sensor, Flame Sensor, Ultrasonic Sensor
* **Alert System** → LED and Buzzer for safety indication
* **IoT Cloud (Blynk)** → Remote monitoring and control dashboard

---

## ⚙️ Key Features

* Real-time industrial monitoring system
* Multi-sensor integration (Temperature, Gas, Flame, Distance)
* WiFi-based IoT communication using ESP8266
* Remote monitoring via Blynk Cloud
* Safety alert system (LED + Buzzer)
* Automatic hazard detection
* Low-cost and scalable design
* Industrial safety enhancement

---

## 🔌 Hardware Requirements

* STM32F407 Microcontroller
* ESP8266 WiFi Module
* DHT11 Temperature & Humidity Sensor
* MQ-Series Gas Sensor
* Flame Sensor Module
* Ultrasonic Sensor (HC-SR04)
* Buzzer
* LED Indicator
* Power Supply (5V/3.3V regulated)

---

## 📡 IoT Data Mapping (Blynk)

| Virtual Pin | Parameter         |
| ----------- | ----------------- |
| V0          | Temperature       |
| V1          | Humidity          |
| V2          | Gas Sensor Value  |
| V3          | LDR / Light Value |
| V4          | Flame Detection   |
| V5          | Distance (cm)     |

---

## 🧠 Safety Logic

* **Gas Leakage Detected** → Buzzer ON + LED ON
* **Flame Detected** → Immediate Alert
* **Distance < Threshold** → Obstacle Warning
* **Normal Condition** → System Idle

---

## 🚀 Execution Steps

1. Open project in **STM32CubeIDE**
2. Configure peripherals using **STM32CubeMX**
3. Build and generate `.hex` file
4. Flash code to STM32F407 board
5. Connect ESP8266 via UART (USART1)
6. Configure WiFi credentials and Blynk token
7. Power ON the system
8. Monitor data using **Blynk App**

---

## 📸 Demonstration

<img width="981" height="652" alt="image" src="https://github.com/user-attachments/assets/0260eab9-a6ab-403a-bf3c-950e0c0fdcec" />


---

## 🎯 Applications

* Industrial Machine Monitoring
* Factory Safety Systems
* Smart Manufacturing
* IoT-Based Automation Systems
* Hazard Detection Systems

---

## 🛠️ Tools & Technologies

* Embedded C Programming
* STM32F407 (ARM Cortex-M4)
* ESP8266 WiFi Module
* UART Communication (USART)
* ADC, GPIO, Timers
* Blynk IoT Platform
* STM32CubeIDE 

---

## 🧪 Advantages

* Real-time monitoring
* Remote access via IoT
* Improved industrial safety
* Low-cost implementation
* Scalable and modular design
* Easy integration with cloud platforms

---

## 🔮 Future Scope

* Integration with **FreeRTOS**
* AI-based anomaly detection
* Mobile app with advanced UI
* Industrial protocol support (MODBUS/CAN)
* Data logging and analytics dashboard

---

## 📜 License

This project is licensed under the **MIT License**.

---

## 👨‍💻 Author

**SABARINATHAN S**
Embedded Systems & IoT Developer

* 🔗 LinkedIn: [https://www.linkedin.com/in/sabarinathans23](https://www.linkedin.com/in/sabarinathans23)
* 📧 Email: [sabarinathansja23@gmail.com](mailto:sabarinathansja23@gmail.com)

---

## ⭐ Acknowledgment

If you find this project useful, please ⭐ star the repository.

---

