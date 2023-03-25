void setup() {
  pinMode(8, INPUT); //input pin from soil sensor
  pinMode(9, OUTPUT); //output pin for red LED
  pinMode(10, OUTPUT); //output pin for green LED
}

void loop() {
  int water = digitalRead(8);
  digitalWrite(9, water == LOW ? HIGH : LOW);
  digitalWrite(10, water == LOW ? HIGH : HIGH);
  delay(250);
}
