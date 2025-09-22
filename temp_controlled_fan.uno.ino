#include <LiquidCrystal.h>
#include <DHT.h>

// ===== LCD Setup =====
LiquidCrystal lcd(7, 8, 9, 10, 11, 12);

// ===== DHT Setup =====
#define DHTPIN 2
#define DHTTYPE DHT22   // change to DHT11 if using that sensor
DHT dht(DHTPIN, DHTTYPE);

// ===== L293D Motor Setup =====
#define ENABLE 5   // PWM pin
#define DIRA 3     // Motor direction pin A
#define DIRB 4     // Motor direction pin B

// ===== Threshold & Speed =====
const float TEMP_THRESHOLD = 28.0;  // Fan turns on above this temp (°C)
const int FAN_SPEED = 180;          // PWM speed (0–255) ~70% duty cycle

void setup() {
  // LCD + DHT
  lcd.begin(16, 2);
  dht.begin();
  lcd.print("System Ready!");
  delay(2000);

  // Motor pins
  pinMode(ENABLE, OUTPUT);
  pinMode(DIRA, OUTPUT);
  pinMode(DIRB, OUTPUT);

  // Start motor OFF
  digitalWrite(DIRA, LOW);
  digitalWrite(DIRB, LOW);
  analogWrite(ENABLE, 0);

  Serial.begin(9600);
}

void loop() {
  delay(2000); // DHT needs ~2s between reads

  float h = dht.readHumidity();
  float t = dht.readTemperature(); // Celsius

  if (isnan(h) || isnan(t)) {
    lcd.clear();
    lcd.print("Sensor error!");
    Serial.println("Sensor error!");
    return;
  }

  // === LCD Output ===
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Temp: ");
  lcd.print(t, 1);
  lcd.print("C");

  lcd.setCursor(0, 1);
  lcd.print("Hum: ");
  lcd.print(h, 1);
  lcd.print("%");

  // === Motor Control ===
  if (t > TEMP_THRESHOLD) {
    // Run fan forward
    digitalWrite(DIRA, HIGH);
    digitalWrite(DIRB, LOW);
    analogWrite(ENABLE, FAN_SPEED);

    Serial.println("Fan ON");
  } else {
    // Stop fan
    digitalWrite(DIRA, LOW);
    digitalWrite(DIRB, LOW);
    analogWrite(ENABLE, 0);

    Serial.println("Fan OFF");
  }
}
