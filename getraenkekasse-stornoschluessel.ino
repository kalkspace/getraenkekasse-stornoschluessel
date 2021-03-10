int stornoPin = 10;
int value;
int state;

void setup() {
  state = LOW;
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(stornoPin, INPUT_PULLUP);
}

void loop() {
  value = digitalRead(stornoPin);
  if (value != state) {
    if (value == LOW) {
      Serial.write("storno\n");
    } else {
      Serial.write("stornoend\n");
    }
    
    state = value;
  }
}
