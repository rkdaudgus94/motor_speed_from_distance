#define TRIG 4
#define ECHO 5

#define driverIn3 9
#define driverIn4 10
#define driverPwmR 11

int data;
int data1;
float pwm;
float distance;

void distance_motor();

void setup() {
  Serial.begin(9600);
  pinMode(TRIG, OUTPUT);
  pinMode(ECHO, INPUT);
  pinMode(driverIn3, OUTPUT);
  pinMode(driverIn4, OUTPUT);
  pinMode(driverPwmR, OUTPUT);
}

void loop() {
  if (Serial.available()) {
    data = Serial.read(); // 데이터를 읽어서 'data'를 저장
  }
  while (data == '1') {
    Serial.available();
    data1 = Serial.read();
    distance_motor();

    if (data1 == '0') {
      Serial.print("break");
      break;
    }
  }
}

void distance_motor() {
  digitalWrite(TRIG, LOW);
  delay(10);
  digitalWrite(TRIG, HIGH);
  delay(10);
  digitalWrite(TRIG, LOW);

  distance = pulseIn(ECHO, HIGH) / 58.8;

  if (distance < 10) {
    digitalWrite(driverIn3, HIGH);
    digitalWrite(driverIn4, LOW);
    analogWrite(driverPwmR, 0); // 0% Duty Cycle
    pwm = 0/2.5500;
  }
  else if (distance < 20) {
    digitalWrite(driverIn3, HIGH);
    digitalWrite(driverIn4, LOW);
    analogWrite(driverPwmR, 64); // 25% Duty Cycle
    pwm = 64/2.55;
  }
  else if (distance < 30) {
    digitalWrite(driverIn3, HIGH);
    digitalWrite(driverIn4, LOW);
    analogWrite(driverPwmR, 127); // 50% Duty Cycle
    pwm = 127/2.55 ;
  }
  else  {
    digitalWrite(driverIn3, HIGH);
    digitalWrite(driverIn4, LOW);
    analogWrite(driverPwmR, 255); // 100% Duty Cycle
    pwm = 255/2.55;
  }

  Serial.print(distance);
  Serial.print("cm");
  Serial.println(pwm);

  delay(1000);
}

