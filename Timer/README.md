#SEISMOGRAPH BASED ON EMF CHANGE

#Overview

This Seismograph is an Arduino-based embedded project designed to detect and display vibrations in real time. The project uses a 
suspended magnet and coil arrangement to detect movement and generate a small electrical signal.
The signal from the coil is amplified using an LM358 operational amplifier before being connected to the Arduino. The Arduino reads the 
amplified signal through analog pin A0 and converts the reading into a simple seismic activity level from 1 to 10
The activity level is displayed on a 16x2 LCD, while the raw sensor value is also sent to the Serial Monitor for testing and calibration.

#How It Works

The project uses a magnet suspended near a fixed coil. When the setup experiences vibration, the magnet moves relative to the coil. 
This movement changes the magnetic field around the coil and produces a small electrical signal through electromagnetic induction.
Since the signal produced by the coil is small, it is amplified using an LM358 operational amplifier. The amplified output is connected to 
analog pin A0 of the Arduino.
The Arduino uses analogRead() to measure the amplified signal. The analog reading can range from 0 to 1023.

The program uses a minimum and maximum expected sensor value to represent the normal operating range of the system. The Arduino then uses 
the map() function to convert this range into a seismic activity level from 1 to 10.
A noise threshold is also used to ignore very small fluctuations that may occur when there is no significant vibration.
The calculated activity level is displayed on the LCD and the raw sensor value is sent to the Serial Monitor.

#Hardware Used

Arduino Uno
Magnet
Copper coil
LM358 operational amplifier
16x2 LCD
Suspension thread
Breadboard
Jumper wires

#Circuit Connections

LM358 Amplifier Output → A0

LCD RS → Digital Pin 12
LCD E → Digital Pin 11
LCD D4 → Digital Pin 5
LCD D5 → Digital Pin 4
LCD D6 → Digital Pin 3
LCD D7 → Digital Pin 2

#Calibration

The initial program uses a minimum sensor value of 400 and a maximum sensor value of 900.
A noise threshold of 20 is also used to reduce the effect of small sensor fluctuations.
These values are based on the expected readings from the setup and can be adjusted after testing the actual sensor. The calibration values 
depend on factors such as the magnet movement, coil construction, amplifier output, and surrounding vibrations.

#Important Note

The 1–10 scale used in this project is a simple project-specific seismic activity scale. It is not the Richter scale and does not 
represent the actual magnitude of an earthquake.
The purpose of the project is to demonstrate vibration detection, analog signal reading, signal amplification, calibration, and 
embedded-system programming.

#Key Concepts Demonstrated

Electromagnetic induction
Vibration detection
Analog signal reading
LM358 signal amplification
Sensor calibration
Noise threshold
analogRead()
map()
LCD interfacing
Serial Monitor debugging
Real-time embedded-system processing

#Project Purpose

The Seismograph Mark II demonstrates how physical vibration can be detected using a magnet and coil, converted into an electrical signal, 
amplified, measured by a microcontroller, and displayed as useful information.

The project combines concepts from physics, electronics, sensors, signal processing, and Arduino programming into a practical 
embedded-system project.

