# Smart Device with Antares IoT Platform

This project demonstrates a smart device setup for monitoring environmental parameters using sensors and controlling LEDs based on threshold values. The device communicates with the Antares IoT platform to send and retrieve data, enabling remote monitoring and control.

---

## Features
1. **Environmental Monitoring:**
   - **DHT11 Sensor**: Measures temperature and humidity.
   - **LDR Sensor**: Measures light intensity.
   - **Soil Moisture Sensor**: Measures soil moisture level.
2. **LED Actuation:**
   - **Grow Light (LED_Grow_Light)**: Activates based on light intensity.
   - **Fan (LED_Fan)**: Activates based on temperature.
   - **Drip Irrigation (LED_Drip_Irrigation)**: Activates based on soil moisture.
3. **Cloud Integration:**
   - Sends sensor data to the **Antares IoT Platform**.
   - Retrieves the latest data from the platform for actuation control.

---

## Hardware Requirements
- **ESP32 Development Board**
- **DHT11 Sensor** (Temperature and Humidity)
- **LDR Sensor** (Light Detection)
- **Soil Moisture Sensor**
- **LEDs** for:
  - Grow Light
  - Fan Indicator
  - Drip Irrigation Indicator
- **Resistors** (if needed for sensors/LEDs)
- **Power Source**

---

## Pin Configuration
### Sensor Inputs
| **Component**       | **Pin** |
|----------------------|---------|
| DHT11               | 14      |
| LDR                 | A0      |
| Soil Moisture Sensor| A3      |

### LED Outputs
| **Component**        | **Pin** |
|-----------------------|---------|
| Grow Light LED       | 12      |
| Fan LED              | 13      |
| Drip Irrigation LED  | 36      |

---

## Software Requirements
1. **Arduino IDE** with the following libraries:
   - [AntaresESP32HTTP](https://github.com/antaresdocumentation/AntaresESP32HTTP)
   - [DHTesp](https://github.com/beegee-tokyo/DHTesp)
2. **Antares IoT Platform**:
   - Create an application and device on the Antares platform.
   - Note the **ACCESSKEY**, **Application Name**, and **Device Name**.

---

## Setup Instructions
1. Clone the repository and open the project in Arduino IDE.
2. Install the required libraries via the Library Manager in Arduino IDE.
3. Replace placeholders in the code with your credentials:
   - **ACCESSKEY**: Antares access key.
   - **WIFISSID**: WiFi SSID.
   - **PASSWORD**: WiFi password.
   - **Application Name** and **Device Name**: Correspond to the Antares setup.
4. Upload the code to the ESP32 board.

---

## Usage
### Sensor Data Upload
1. The device reads data from the DHT11, LDR, and moisture sensors.
2. Data is sent to the Antares IoT platform in JSON format every 20 seconds.

### Actuator Control
1. The device retrieves data from Antares.
2. LED actuation logic:
   - **Grow Light LED**: Activated if LDR value exceeds `LDRthreshold`.
   - **Fan LED**: Activated if temperature exceeds `Tempthreshold`.
   - **Drip Irrigation LED**: Activated if moisture level exceeds `Moistthreshold`.

---

## Threshold Values
| **Parameter**   | **Threshold** |
|------------------|---------------|
| LDR             | 2400          |
| Temperature     | 20°C          |
| Soil Moisture   | 2800          |

---

## Serial Monitor Output
The device logs sensor readings, actuator statuses, and threshold comparisons for debugging. 

Example:
=================== 
LDR: 2300 Temperature: 21 Humidity: 55 Moisture: 2900
Lamp is activated Fan is activated Drip irrigation is deactivated


---

## License
This project is open-source. Feel free to use, modify, and distribute.

---

## Contributing
Contributions are welcome! Feel free to submit pull requests or issues to enhance the functionality of this project.  

---

## Acknowledgments
- [Antares IoT Platform](https://antares.id) for cloud integration.
- Libraries: [AntaresESP32HTTP](https://github.com/antaresdocumentation/AntaresESP32HTTP) and [DHTesp](https://github.com/beegee-tokyo/DHTesp).
