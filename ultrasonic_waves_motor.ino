#define TRIG 4
#define ECHO 5

#define driverIn3 9
#define driverIn4 10
#define driverPwmR 11


void setup() {
  Serial.begin(115200);
  pinMode(TRIG, OUTPUT);
  pinMode(ECHO, INPUT);
  pinMode(driverIn3, OUTPUT);
  pinMode(driverIn4, OUTPUT);
  pinMode(driverPwmR, OUTPUT);
}

void loop() {
  digitalWrite(TRIG, LOW);
  delay(500);
  digitalWrite(TRIG, HIGH);
  delay(500);
  digitalWrite(TRIG, LOW);
  
  long distance = pulseIn(ECHO, HIGH) / 58.2;

  if (distance < 10) {
    digitalWrite(driverIn3, HIGH);
    digitalWrite(driverIn4, LOW);
    analogWrite(driverPwmR, 0);
  }
  else if (distance < 20) {
    digitalWrite(driverIn3, HIGH);
    digitalWrite(driverIn4, LOW);
    analogWrite(driverPwmR, 50);
  }
  else if (distance < 30) {
    digitalWrite(driverIn3, HIGH);
    digitalWrite(driverIn4, LOW);
    analogWrite(driverPwmR, 100);
  }
  else if (distance > 30) {
    digitalWrite(driverIn3, HIGH);
    digitalWrite(driverIn4, LOW);
    analogWrite(driverPwmR, 200);
  }

  Serial.print(distance);
  Serial.print("cm");

  delay(100);
}
