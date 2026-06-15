# 🚦 TrafficSafe

## 📚 Project Resources

Additional resources related to the TrafficSafe project are available in the Google Drive folder below:

🔗 https://drive.google.com/drive/folders/15VWB2hD3arSu58_NBIdnYgBwRWFJJP_y?usp=sharing

The folder includes project reports, presentation materials, circuit schematics, hardware setup documentation, implementation details, testing results, and demonstration videos developed throughout the project.

### Arduino-Based Smart Pedestrian Safety Barrier System

TrafficSafe is an Arduino-based smart pedestrian safety system designed to prevent accidents at pedestrian crossings. The system detects approaching vehicles from a distance and automatically controls a safety barrier to protect pedestrians from crossing when it is unsafe.

When a vehicle is detected approaching the crosswalk, the barrier lowers to block pedestrians from entering the road. Once the vehicle has safely passed the crossing area, the barrier rises again, allowing pedestrians to cross safely.

---

## 📌 Project Overview

Pedestrian accidents frequently occur because people attempt to cross roads without noticing oncoming vehicles or underestimate their speed. Traditional pedestrian crossings rely heavily on traffic lights and individual awareness, which may not always provide sufficient protection.

TrafficSafe introduces an intelligent safety mechanism that actively prevents dangerous crossing situations by automatically controlling a physical barrier based on real-time vehicle detection.

The goal of this project is to enhance pedestrian safety and reduce the risk of traffic accidents through affordable and practical embedded technology.

---

## 🎯 Objectives

- Improve pedestrian safety at crosswalks.
- Prevent unsafe road crossing situations.
- Automatically detect approaching vehicles.
- Provide a low-cost solution using Arduino.
- Demonstrate the practical application of embedded systems in smart transportation.

---

## ⚙️ System Workflow

1. The sensor continuously monitors the road for approaching vehicles.
2. When a vehicle is detected within a predefined safety distance:
   - The system identifies a potential danger.
   - The barrier automatically lowers.
   - Pedestrians are prevented from crossing.
3. The system keeps monitoring the vehicle's movement.
4. After the vehicle passes the crossing area:
   - The danger condition is cleared.
   - The barrier rises automatically.
   - Pedestrians can safely cross the road.

---

## ✨ Key Features

- 🚗 Real-time vehicle detection.
- 🚧 Automatic pedestrian barrier control.
- 🔄 Fully automated operation.
- ⚡ Fast response to approaching vehicles.
- 🛡️ Reduces the possibility of pedestrian accidents.
- 🔋 Low-cost implementation using Arduino components.
- 🏙️ Suitable for smart city and intelligent transportation applications.

---

## 🛠️ Hardware Components

| Component                   | Description                                   |
| --------------------------- | --------------------------------------------- |
| Arduino Uno                 | Main microcontroller                          |
| Ultrasonic Sensor (HC-SR04) | Detects approaching vehicles                  |
| Servo Motor                 | Controls the barrier movement                 |
| LED Indicators              | Indicates safe and unsafe crossing conditions |
| Breadboard                  | Circuit assembly                              |
| Jumper Wires                | Hardware connections                          |
| Power Supply                | Powers the system                             |

---

## 💻 Software and Development Environment

- Programming Language: Arduino C/C++
- Development Environment: Arduino IDE
- Microcontroller: Arduino Uno
- Version Control: Git & GitHub

---

## 🔧 System Architecture

Approaching Vehicle ↓ Ultrasonic Sensor ↓ Arduino Uno ↓ Decision Processing ↓ ┌───────────────┐ │ Vehicle Near? │ └───────┬───────┘ │ Yes │ No │ ↓ Lower Barrier (Block Crossing) │ Vehicle Passes │ ↓ Raise Barrier (Allow Crossing)

---

## 🚀 How to Run

### 1. Assemble the Hardware

- Connect the HC-SR04 ultrasonic sensor to the Arduino Uno.
- Connect the servo motor to the designated PWM pin.
- Connect LEDs and power supply according to the circuit design.

### 2. Upload the Program

- Open the Arduino IDE.
- Load the TrafficSafe.ino file.
- Select the correct board and COM port.
- Upload the code to the Arduino Uno.

### 3. Test the System

- Place an object or vehicle within the detection range.
- Observe the servo motor lowering the barrier.
- After the object moves away, verify that the barrier rises automatically.

---

## 📊 Expected Results

The TrafficSafe system is expected to:

- Successfully detect approaching vehicles.
- Lower the barrier before pedestrians enter dangerous areas.
- Raise the barrier after vehicles pass.
- Operate reliably with minimal delay.
- Demonstrate the feasibility of smart pedestrian protection systems using embedded technology.

---

## 🌍 Future Improvements

- Integrate multiple sensors for improved accuracy.
- Add warning sounds and voice announcements.
- Use cameras and computer vision for advanced vehicle detection.
- Connect to IoT platforms for remote monitoring.
- Implement solar-powered operation.
- Apply machine learning techniques to predict traffic patterns.

---

## 👨‍💻 Contributors

- Developed by:

OnlyDev

TrafficSafe

---

## 📄 License

This project was developed for educational and research purposes.

> 본 프로젝트는 김영종 교수님의 「창의적공학설계」 수업의 일환으로 수행되었습니다.
