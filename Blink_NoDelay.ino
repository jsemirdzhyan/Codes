#define LEDGreen 2
#define LEDRed 3

int lastState = LOW;
unsigned long previousMillis = 0;
const long interval = 1000;

void setup() {
  pinMode(LEDGreen, OUTPUT);
  pinMode(LEDRed, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  unsigned long currentMillis = millis();
  if (currentMillis - previousMillis >= interval) {
    previousMillis = currentMillis;
    LEDBlink();

  }
}

void LEDBlink() {
  if (lastState == HIGH) {
    lastState = LOW;
  }
  else {
    lastState = HIGH;
  }
  digitalWrite(LEDGreen, lastState);
  digitalWrite(LEDRed, LOW);

  if (lastState == HIGH) {
    Serial.println("LED On");
  }
  else {
    Serial.println("LED Off");
  }
}

