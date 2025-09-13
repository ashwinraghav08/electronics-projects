# Electronics Projects Portfolio ⚡🔬  

## Overview  
This repository is a collection of my Arduino/Elegoo Mega 2560 projects.  
Each project includes the concept, components, wiring, demo, and reflections.  

These projects highlight my exploration of:  
- Digital inputs & outputs  
- Analog sensors & voltage dividers  
- PWM (pulse-width modulation) for control  
- Renewable energy & feedback systems  

---

## 1️⃣ Button-Controlled LED 💡  

### Overview  
A pushbutton toggles an LED on and off with each press.  
This project introduces **digital inputs**, **digital outputs**, and **internal pull-up resistors**.  

### Components  
- Arduino Mega 2560 (Elegoo)  
- 1× Pushbutton  
- 1× LED  
- 1× 220 Ω resistor  
- Jumper wires + breadboard  

### Wiring  
- Button leg 1 → Pin 2  
- Button leg 2 → GND  
- LED anode (long leg) → resistor → Pin 12  
- LED cathode (short leg) → GND  

### Code  
[button_led.ino](button-led/code/button_led.ino)  

### Demo  
![Button LED Demo](button-led/media/button_led_circuit.jpg)  

### Reflection  
This was my first interactive project.  
I learned how microcontrollers interpret **digital signals**,  
how to avoid floating pins using `INPUT_PULLUP`,  
and how to add a simple **debounce** for reliable toggling.  

---

## 2️⃣ Solar-Powered Fan/LED 🌞🌀  

### Overview  
A solar panel powers an LED or DC motor.  
Arduino monitors the panel voltage with a **voltage divider**  
and only activates the load when there is enough sunlight.  

### Components  
- Arduino Mega 2560  
- 1× Small solar panel (5V, ~1W)  
- 1× Diode (1N4007 or 1N5819)  
- 1× LED + 220 Ω resistor **or** 1× DC motor + NPN transistor  
- 2× Resistors (100kΩ + 33kΩ for divider)  
- Jumper wires + breadboard  

### Wiring  
- Solar + → diode → + rail  
- Solar – → GND rail  
- Voltage divider → A0  
- Load (motor/LED) controlled via D9 or transistor switch  

### Code  
[solar_fan.ino](solar-fan/code/solar_fan.ino)  

### Demo  
![Solar Demo](solar-fan/media/solar_demo.jpg)  

### Reflection  
This project showed me how **renewable energy** interacts with electronics.  
I practiced using **voltage dividers** to safely read higher voltages,  
and implemented **threshold-based control** (e.g., load on above 3.8 V).  
It connected real-world **power electronics** with hands-on prototyping.  

---

## 3️⃣ Temperature Logger 🌡️  

### Overview  
A thermistor measures ambient temperature.  
Arduino logs readings to the Serial Monitor and turns on an LED if it exceeds a threshold.  

### Components  
- Arduino Mega 2560  
- 1× Thermistor  
- 1× 10kΩ resistor (divider)  
- 1× LED + 220 Ω resistor  
- Jumper wires + breadboard  

### Wiring  
- Thermistor divider → A0  
- LED anode → resistor → Pin 11  
- LED cathode → GND  

### Code  
[temp_logger.ino](temp-logger/code/temp_logger.ino)  

### Demo  
![Temperature Logger](temp-logger/media/temp_logger.jpg)  

### Reflection  
This was my first **sensor-driven** project.  
I learned how to read **analog values**, convert them to °C, and  
trigger actions based on thresholds.  
Pressing my finger on the thermistor and seeing values rise live  
was a clear example of **feedback loops** in embedded systems.  

---

## 4️⃣ Light-Sensitive Lamp (LDR) 💡🌙  

### Overview  
A photoresistor detects room brightness.  
Arduino fades an LED using **PWM** — brighter in the dark, dimmer in light.  

### Components  
- Arduino Mega 2560  
- 1× Photoresistor (LDR)  
- 1× 10kΩ resistor (divider)  
- 1× LED + 220 Ω resistor  
- Jumper wires + breadboard  

### Wiring  
- LDR divider → A0  
- LED anode → resistor → Pin 9 (PWM)  
- LED cathode → GND  

### Code  
[light_lamp.ino](light-lamp/code/light_lamp.ino)  

### Demo  
![Light Lamp](light-lamp/media/light_demo.jpg)  

### Reflection  
This project taught me about **analog sensing** and **PWM outputs**.  
I built a lamp that adapts automatically to its environment —  
a mini example of an **IoT smart home device**.  

---

## 🔹 How to Run These Projects  
1. Open `.ino` file in Arduino IDE.  
2. Select **Board:** Arduino Mega 2560.  
3. Select the correct **Port**.  
4. Wire circuit as described.  
5. Upload sketch & open Serial Monitor if needed.  

---

## 🔹 Why These Projects Matter  
- **Button LED** → interactive inputs/outputs.  
- **Solar Project** → renewable energy + electronics.  
- **Temperature Logger** → sensor input + feedback control.  
- **Light Lamp** → analog sensing + PWM output.  

Together, they represent my first steps in **Electrical & Computer Engineering** —  
combining hardware, coding, and system design into real prototypes.  
