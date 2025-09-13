const int LED_PIN = 12;     // LED on pin 12
const int BUTTON_PIN = 2;   // Button on pin 2

bool ledState = LOW;        // start with LED off
bool lastButton = HIGH;     // last button reading

void setup() {
  pinMode(LED_PIN, OUTPUT);
  pinMode(BUTTON_PIN, INPUT_PULLUP);  // internal pull-up
  digitalWrite(LED_PIN, ledState);
  Serial.begin(9600);
}

void loop() {
  bool reading = digitalRead(BUTTON_PIN);

  // detect button press (goes from HIGH -> LOW)
  if (lastButton == HIGH && reading == LOW) {
    ledState = !ledState;                // toggle LED
    digitalWrite(LED_PIN, ledState);
    Serial.println(ledState ? "LED ON" : "LED OFF");
    delay(200);                          // basic debounce
  }

  lastButton = reading;
}
