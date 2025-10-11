# 💧 Water Level Detector

An Arduino project that measures water levels using the **Water Sensor Module** from the Elegoo kit.  
It lights up LEDs (green, yellow, red) based on detected level, and activates a buzzer when the level exceeds a threshold.

---

## ⚙️ Files Included

| File | Description |
|------|--------------|
| `waterleveldetector.ino` | Main Arduino code controlling LEDs and buzzer |
| `waterleveldetector_fritzing` | Fritzing circuit diagram |
| `waterlevelimage.JPG` | Photo of the assembled circuit |
| `waterleveldetector.MOV` | Demo video showing the working system |

---

## 🔧 Components Used

- Arduino Uno / Mega 2560  
- Water Level Sensor Module  
- 3 LEDs (Green, Yellow, Red)  
- 1 Buzzer  
- Breadboard + Jumper Wires  

---

## 🖼️ Circuit Diagram

![Circuit Diagram](waterleveldetector_fritzing)

---

## 📸 Project Image

![Assembled Project](waterlevelimage.JPG)

---

## 💻 Code

```cpp
const int analogInPin = A0;
int sensorValue = 0;

// LED pins
const int greenLED = 2;
const int yellowLED = 3;
const int redLED = 4;
const int buzzer = 5; // Buzzer pin

// Ranges
const int GREEN_MIN = 50;
const int GREEN_MAX = 200;
const int YELLOW_MIN = 200;
const int YELLOW_MAX = 340;
const int RED_MIN = 340;

void setup() {
  Serial.begin(9600);
  pinMode(greenLED, OUTPUT);
  pinMode(yellowLED, OUTPUT);
  pinMode(redLED, OUTPUT);
  pinMode(buzzer, OUTPUT);
}

void loop() {
  sensorValue = analogRead(analogInPin);
  Serial.print("Sensor = ");
  Serial.println(sensorValue);

  // Turn everything OFF first
  digitalWrite(greenLED, LOW);
  digitalWrite(yellowLED, LOW);
  digitalWrite(redLED, LOW);
  digitalWrite(buzzer, LOW);

  if (sensorValue >= GREEN_MIN && sensorValue < GREEN_MAX) {
    digitalWrite(greenLED, HIGH);
  } 
  else if (sensorValue >= YELLOW_MIN && sensorValue < YELLOW_MAX) {
    digitalWrite(yellowLED, HIGH);
  } 
  else if (sensorValue >= RED_MIN) {
    digitalWrite(redLED, HIGH);
    digitalWrite(buzzer, HIGH);
  }

  delay(100);
}
