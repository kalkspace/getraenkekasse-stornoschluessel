int stornoPin = 2;
int value;
int state;

void setup() {
  state = LOW;
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(stornoPin, INPUT_PULLUP);
  pinMode(LED_BUILTIN, OUTPUT);
}

void loop() {
  value = digitalRead(stornoPin);
  if (value != state) {
    if (value == LOW) {
      digitalWrite(LED_BUILTIN, HIGH);
      Serial.write("storno\n");
    } else {
      digitalWrite(LED_BUILTIN, LOW);
      Serial.write("stornoend\n");
    }
    
    state = value;
  }
}
