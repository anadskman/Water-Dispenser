const int WATER_PUMP = 25;
const int SYRUP_PUMP = 26;
const int BUTTON_PIN = 27;
const int POT_PIN = 34;
const int LED_PIN = 33;

// PWM settings
const int PWM_FREQ = 1000;
const int PWM_RESOLUTION = 8;

const int WATER_CHANNEL = 0;
const int SYRUP_CHANNEL = 1;

// Dispense time in milliseconds
const int DISPENSE_TIME = 3000;

void setup() {

  pinMode(BUTTON_PIN, INPUT_PULLUP);
  pinMode(LED_PIN, OUTPUT);

  // ESP32 PWM setup
  ledcSetup(WATER_CHANNEL, PWM_FREQ, PWM_RESOLUTION);
  ledcAttachPin(WATER_PUMP, WATER_CHANNEL);

  ledcSetup(SYRUP_CHANNEL, PWM_FREQ, PWM_RESOLUTION);
  ledcAttachPin(SYRUP_PUMP, SYRUP_CHANNEL);

  digitalWrite(LED_PIN, LOW);

  // Make sure pumps start off
  ledcWrite(WATER_CHANNEL, 0);
  ledcWrite(SYRUP_CHANNEL, 0);
}

void loop() {

  if (digitalRead(BUTTON_PIN) == LOW) {

    digitalWrite(LED_PIN, HIGH);

    int potValue = analogRead(POT_PIN);

    // Map pot to syrup pump speed
    // 25 = weak drink
    // 128 = strong drink
    int syrupPWM = map(potValue, 0, 4095, 25, 128);

    // Water pump full speed
    ledcWrite(WATER_CHANNEL, 255);

    // Syrup pump adjustable speed
    ledcWrite(SYRUP_CHANNEL, syrupPWM);

    delay(DISPENSE_TIME);

    // Stop pumps
    ledcWrite(WATER_CHANNEL, 0);
    ledcWrite(SYRUP_CHANNEL, 0);

    digitalWrite(LED_PIN, LOW);

    delay(300);
  }
}