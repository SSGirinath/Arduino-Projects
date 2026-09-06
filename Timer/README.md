#DIGITAL TIMER

#Overview

The Digital Timer is an Arduino-based countdown timer that allows the user to set a time, start or stop the countdown, and reset the timer using physical push buttons.
The remaining time is displayed on a 16x2 LCD, and a buzzer provides an audible alert when the countdown reaches zero.
The project demonstrates how an Arduino can combine buttons, an LCD, timing functions, and a buzzer to create a simple standalone embedded system.

#How It Works

The timer uses three push buttons to control its operation.
The Start/Stop button is connected to digital pin 6. A short press starts or stops the countdown. Holding the button for approximately one second resets the timer back to zero.
The Increase button is connected to digital pin 7. Each press adds one minute to the timer.
The Decrease button is connected to digital pin 8. Each press removes one minute from the timer, as long as at least one minute is currently set.
The Arduino stores the total time in seconds. The millis() function is used to measure one-second intervals while the timer is running.
When one second has passed, the timer decreases by one second. The remaining time is then separated into minutes and seconds and displayed on the LCD.
When the countdown reaches zero, the timer stops and the buzzer connected to digital pin 9 is activated for one second.

#Hardware Used

Arduino Uno
16x2 LCD
Three push buttons
Buzzer
Breadboard
Jumper wires

#Circuit Connections

LCD RS → Digital Pin 12
LCD E → Digital Pin 11
LCD D4 → Digital Pin 5
LCD D5 → Digital Pin 4
LCD D6 → Digital Pin 3
LCD D7 → Digital Pin 2

Start/Stop Button → Digital Pin 6
Increase Button → Digital Pin 7
Decrease Button → Digital Pin 8
Buzzer → Digital Pin 9

The buttons use the Arduino's internal pull-up resistors through INPUT_PULLUP.

#Controls

Start/Stop button → Starts or stops the countdown
Holding the Start/Stop button → Resets the timer to zero.
Increase button → Adds one minute.
Decrease button → Removes one minute.

#Key Concepts Demonstrated

Digital input
Push-button interfacing
INPUT_PULLUP
LCD interfacing
millis() for timing
Countdown logic
Conditional statements
Functions
Digital output control
Buzzer control
Basic embedded-system programming

#Program Logic

The Arduino continuously checks the state of the control buttons.
When the timer is stopped, the Increase and Decrease buttons can be used to set the required time.
When the Start/Stop button is pressed briefly, the timer starts or stops.
While the timer is running, millis() is used to determine when one second has passed. The remaining time is then reduced by one second.
The current time is continuously displayed on the LCD.
When the timer reaches zero, the Arduino stops the countdown and activates the buzzer for one second.

#Project Purpose

The Digital Timer demonstrates how an Arduino can receive input from multiple physical buttons, process timing information, display data on an LCD, and control an output device.

The project provides practical experience with embedded programming, user input, timing logic, LCD interfacing, and actuator control.


