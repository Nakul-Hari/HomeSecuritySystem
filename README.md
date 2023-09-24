# Motion-Activated Camera with UART Communication

This project demonstrates a motion-activated camera system using a PIR (Passive Infrared) sensor to detect motion and a microcontroller (MKL25Z4) to trigger the camera when motion is detected. UART communication is used to trigger the camera capture.

## Table of Contents
- [Overview](#overview)
- [Hardware Setup](#hardware-setup)
- [Software Setup](#software-setup)
- [Usage](#usage)
- [License](#license)

## Overview

This project combines hardware and software components to create a motion-activated camera system. When motion is detected by the PIR sensor, the microcontroller sends a command ('Y') through UART communication to trigger the camera to capture an image. The captured image is saved on the computer running the code.

## Hardware Setup

### Components Used
- MKL25Z4 Microcontroller
- PIR Sensor (Passive Infrared Sensor)
- RGB LEDs (Red, Green, Blue)
- Webcam (Camera)
- UART Communication

### Wiring
- Connect the PIR sensor to the designated pin on the microcontroller (refer to the code for pin configurations).
- Connect the RGB LEDs to the microcontroller pins (as specified in the code) to indicate the system's status.
- Ensure the webcam is connected to the computer running the code.

## Software Setup

### Prerequisites
- Python (with OpenCV library)
- C/C++ Compiler for the MKL25Z4 microcontroller

### Code Structure
- The Python script (`main.py`) captures images from the webcam when a UART command ('Y') is received.
- The C/C++ code (`main.c`) runs on the MKL25Z4 microcontroller and is responsible for motion detection using the PIR sensor and UART communication with the computer.

## Usage

1. Compile and flash the microcontroller code (`main.c`) onto the MKL25Z4 microcontroller.
2. Ensure that the hardware is set up correctly, including the PIR sensor, RGB LEDs, and webcam.
3. Run the Python script (`main.py`) on your computer. This script listens for UART commands from the microcontroller.
4. When motion is detected by the PIR sensor, the microcontroller sends a UART command ('Y') to the computer, triggering the Python script to capture an image from the webcam and save it.
5. The RGB LEDs indicate the system's status: 
   - Red LED on: Motion detected
   - Green LED on: Idle (no motion)
   - Blue LED on: System off


