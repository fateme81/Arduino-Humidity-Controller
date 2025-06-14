const int sensorPin = A5;
const int greenLEDPin = 5;
const int redLEDPin = 4;
const int blueLEDPin = 3;
const int delayMilliSeconds = 1000;

int minHumidity;

void turnRed()
{
  digitalWrite(redLEDPin, HIGH);
  digitalWrite(greenLEDPin, LOW);
  digitalWrite(blueLEDPin, LOW);
}

void turnGreen()
{
  digitalWrite(greenLEDPin, HIGH);
  digitalWrite(blueLEDPin, LOW);
  digitalWrite(redLEDPin, LOW);
}

void turnWhite()
{
  digitalWrite(greenLEDPin, HIGH);
  digitalWrite(blueLEDPin, HIGH);
  digitalWrite(redLEDPin, HIGH);
}

void setup() {

  Serial.begin(9600);

  // Set pin modes
  pinMode(redLEDPin, OUTPUT);
  pinMode(greenLEDPin, OUTPUT);
  pinMode(blueLEDPin, OUTPUT);

  if (Serial.available() > 0)
  {
    Serial.println("Enter your minimum desired humidity : ");

    minHumidity = Serial.read();

  }

}


void loop() {

  int currentHumidity = analogRead(sensorPin);

  if (currentHumidity < minHumidity)
  {
    turnRed();
  } else
  {
    turnGreen();
  }

  delay(delayMilliSeconds);

}
