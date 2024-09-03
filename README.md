# IoT LED Control with ARM Cortex-M STM32F401CC and ESP8266

## Overview

This project showcases a basic IoT application that allows users to control an LED remotely via a web interface. Utilizing the ARM Cortex-M STM32F401CC microcontroller and ESP8266 Wi-Fi module, 
this project demonstrates how to efficiently manage device states over the internet, making it a perfect starting point for those interested in embedded systems and IoT technology.

## Features

- **Remote Control:** Control the LED state (ON/OFF) using a web page.
- **Wi-Fi Connectivity:** ESP8266 provides wireless connectivity to the local network.
- **Simple Interface:** User-friendly web page to interact with the LED.
- **Efficient Communication:** Uses HTTP protocol for fast and reliable control commands.

## Components

- **ARM Cortex-M STM32F401CC Microcontroller:** Core processor handling all logic and control operations.
- **ESP8266 Wi-Fi Module:** Connects the microcontroller to a Wi-Fi network, allowing for remote communication.
- **LED:** Output device controlled by the microcontroller via web commands.

## How It Works

1. **Web Interface:** A simple HTML page allows users to send commands to the microcontroller.
2. **Wi-Fi Communication:** The ESP8266 connects to the local Wi-Fi network and listens for incoming HTTP requests from the web page.
3. **LED Control:** Upon receiving an HTTP request, the microcontroller processes the command and toggles the LED state accordingly.

## Getting Started

### Prerequisites

- ARM Cortex-M STM32F401CC Microcontroller
- ESP8266 Wi-Fi Module
- LED and basic electronic components (resistors, breadboard, etc.)
- USB to Serial adapter for programming
- STM32CubeIDE or any compatible IDE
- ARM GCC Toolchain (`arm-none-eabi-gcc`)
- Arduino IDE for ESP8266 setup

### Installation

1. **Setup ESP8266:**
   - Flash the AT Command firmware onto the ESP8266 using the Arduino IDE.
   - Configure the Wi-Fi credentials in the ESP8266 to match your local network.

2. **Program STM32F401CC:**
   - Open the project in STM32CubeIDE.
   - Adjust the Wi-Fi credentials in the code if necessary.
   - Compile and upload the firmware to the STM32F401CC using the ARM GCC Toolchain.

3. **Hardware Connections:**
   - Connect the LED to the designated GPIO pin on the STM32F401CC.
   - Connect the ESP8266 to the STM32F401CC using UART communication.

### Usage

1. **Power Up the System:** Ensure all components are connected and powered.
2. **Connect to Wi-Fi:** The ESP8266 will automatically connect to the configured Wi-Fi network.
3. **Access Web Interface:** Open the provided HTML page in a web browser on any device connected to the same network.
4. **Control the LED:** Use the interface to send commands to the microcontroller and control the LED state.

## Files Included

- **`ARM_WIFIProject.hex`**: Compiled firmware for the STM32F401CC.
- **`/src`**: Source code files for the project.
- **`/include`**: Header files for the project.
- **`/web`**: Web interface files (HTML, PHP ).

## Acknowledgments

Special thanks to the team for their contributions and collaboration on this project.

## Contact

For questions or feedback, feel free to reach out via [LinkedIn](linkedin.com/in/marwan-aboulfath).

