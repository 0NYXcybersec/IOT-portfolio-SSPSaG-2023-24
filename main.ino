// Define the pins for the ultrasonic sensor
const int trigPin = 5;
const int echoPin = 6;

// Define the pins for the LEDs
const int greenPin = 2;
const int yellowPin = 3;
const int redPin = 4;

// Define the threshold distances for the LEDs
const int greenDist = 20;
const int yellowDist = 10;

void setup() {
  // Set the LED pins as outputs
  pinMode(greenPin, OUTPUT);
  pinMode(yellowPin, OUTPUT);
  pinMode(redPin, OUTPUT);

  // Set the trig pin as an output and the echo pin as an input
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

  // Start serial communication
  Serial.begin(9600);
}

void loop() {
  // Send a 10us pulse to the ultrasonic sensor
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // Measure the time it takes for the pulse to bounce back
  long duration = pulseIn(echoPin, HIGH);

  // Calculate the distance in centimeters
  int distance = duration / 58;

  // Print the distance to the serial monitor
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");

  // Check the distance and light up the appropriate LED
  if (distance >= greenDist) {
    digitalWrite(greenPin, HIGH);
    digitalWrite(yellowPin, LOW);
    digitalWrite(redPin, LOW);
  } else if (distance >= yellowDist && distance < greenDist) {
    digitalWrite(greenPin, LOW);
    digitalWrite(yellowPin, HIGH);
    digitalWrite(redPin, LOW);
  } else {
    digitalWrite(greenPin, LOW);
    digitalWrite(yellowPin, LOW);
    digitalWrite(redPin, HIGH);
  }

  // Wait a short period before taking the next measurement
  delay(100);
}
