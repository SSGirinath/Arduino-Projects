#RAIN ALERT SYSTEM

#Overview

The Rain Alert System is an Arduino-based embedded project that detects the presence of rain or water using an analog rain sensor and 
triggers an audible buzzer alert when moisture is detected. The system continuously monitors the sensor and responds automatically when 
water comes into contact with the sensor surface.

#How It Works

The rain sensor consists of exposed conductive tracks. When the sensor is dry, the resistance between the tracks is relatively high. When 
water comes into contact with the tracks, it creates a conductive path between them and changes the electrical signal produced by the sensor.


The Arduino continuously reads this analog signal through analog pin A0 using analogRead(). The sensor value is compared with a threshold 
value of 500.

If the sensor reading falls below 500, the Arduino considers water to be detected and activates the buzzer connected to digital pin 8. 
When the reading rises above the threshold, the buzzer is switched off automatically.

The sensor value is also sent to the Serial Monitor, allowing the readings to be observed during testing and calibration.

#Hardware Used

Arduino Uno
Rain/water sensor module
Buzzer
Breadboard
Jumper wires

#Circuit Connections

Rain Sensor Analog Output → A0
Buzzer → Digital Pin 8
Sensor VCC → 5V
Sensor GND → GND

#Key Concepts Demonstrated

Analog sensor reading
analogRead()
Threshold-based decision making
Digital output control
Buzzer control
Serial Monitor debugging
Basic embedded-system programming

#Project Background

This project was originally developed as a team project in Grade 6 for an inter-school science competition hosted by MIT, where it 
secured 3rd Prize among participating schools.

It was one of my early hands-on projects involving sensors, circuits, and microcontroller programming and served as an introduction to 
embedded systems and Arduino-based development.

