# Simulated-Temperature-Sensor-with-ESP32-and-Web-Server
This project demonstrates how to use an ESP32 to simulate a temperature sensor and serve the data through a simple web server. The ESP32 connects to a WiFi network and hosts a local web server that displays the simulated temperature on a web page. The temperature is generated randomly between 20.0°C and 30.0°C.


**Overview**
This project demonstrates how to use an ESP32 to simulate a temperature sensor and serve the data through a simple web server. The ESP32 connects to a WiFi network and hosts a local web server that displays the simulated temperature on a web page. The temperature is generated randomly between 20.0°C and 30.0°C.

**Features**
Simulated Temperature Sensor: The temperature is simulated with random values between 20.0°C and 30.0°C.
Web Server: A basic web server is set up on the ESP32 that serves the current temperature data when the root URL (/) is accessed.
WiFi Connectivity: The ESP32 connects to a WiFi network using user-provided credentials.
User Interface: A simple HTML page is displayed with the current temperature data.
Requirements

**Hardware:**
ESP32 Development Board
Software:
Arduino IDE with ESP32 support
WiFi library
WebServer library
Setup Instructions
Install Arduino IDE: If you don't already have it, download and install the Arduino IDE.

**Install ESP32 Board**:
Open Arduino IDE and go to File > Preferences.
In the "Additional Boards Manager URLs" field, add the following URL: https://dl.espressif.com/dl/package_esp32_index.json.
Go to Tools > Board > Boards Manager, search for esp32, and install the latest version.
