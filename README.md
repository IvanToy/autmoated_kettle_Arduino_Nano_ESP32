# autmoated_kettle_Arduino_Nano_ESP32


## Overview

This project utilizes an Ovente kettle and various electronic components to create a smart kettle controller. The controller is powered by an Arduino Nano ESP32 microcontroller, enabling users to control the kettle remotely through a web interface. Additionally, the system includes a temperature monitoring feature, ensuring that the kettle turns off automatically when the desired temperature is reached. Two RGB LEDs provide visual feedback by changing colors based on the current temperature status.

## Hardware Components

- **Ovente Kettle:** The primary kettle used for this project.
- **Arduino Nano ESP32:** The microcontroller responsible for controlling the kettle and handling web interactions.
- **Logic Level Converter (3.3V to 5V):** Facilitates communication between components operating at different voltage levels.
- **2 RGB LEDs:** Provide visual indications of the temperature status.
- **NTC 10K 3950 Thermistor:** Monitors the temperature inside the kettle.

## Software Platform

- **PlatformIO with Arduino Framework:** The project is developed using PlatformIO as the development platform, utilizing the Arduino framework for the ESP32 microcontroller.

## System Operation

The smart kettle controller operates as follows:

1. **Web Interface:** The Arduino Nano ESP32 is programmed to host a web interface accessible from a browser. Users can interact with the kettle by accessing this web page.

2. **Relay Connection:** The microcontroller is connected to the kettle's relay through a logic level converter. This connection allows the microcontroller to turn the kettle on and off remotely.

3. **Temperature Monitoring:** The NTC 10K 3950 Thermistor is placed inside the kettle to monitor the temperature. When the temperature reaches the user-set threshold, the microcontroller automatically turns off the kettle, ensuring it doesn't overheat.

4. **RGB LEDs Feedback:** Two RGB LEDs provide visual feedback on the current temperature status. The color changes based on the temperature, creating a user-friendly interface for monitoring the kettle's condition.

video proof: https://www.youtube.com/watch?v=W3cw922_kPw&t=20s
