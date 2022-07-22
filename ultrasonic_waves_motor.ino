#define TRIG 4
#define ECHO 5

#define driverIn3 9
#define driverIn4 10
#define driverPwmR 11

int data;
int pwm;
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
    distance_motor();
    if (Serial.available()) {
      data = Serial.read();

      if (data == '0') {
        Serial.println("END");
        break;
      }
    }
  }
  digitalWrite(driverIn3, LOW);
  digitalWrite(driverIn4, LOW);
  analogWrite(driverPwmR, 0); // 100% Duty Cycle
}

void distance_motor() {
  digitalWrite(TRIG, LOW);
  delay(10);
  digitalWrite(TRIG, HIGH);
  delay(10);
  digitalWrite(TRIG, LOW);

  distance = pulseIn(ECHO, HIGH) / 58.8;
  if (distance >= 50) {
    distance = 50;
  }

  if (distance < 10) {
    digitalWrite(driverIn3, HIGH);
    digitalWrite(driverIn4, LOW);
    analogWrite(driverPwmR, 0); // 0% Duty Cycle
    pwm = 0;
    Serial.print("   ");
    Serial.print(distance);
    Serial.print("cm");
    Serial.print("   ");
    Serial.println(pwm);
  }
  else if (distance < 20) {
    digitalWrite(driverIn3, HIGH);
    digitalWrite(driverIn4, LOW);
    analogWrite(driverPwmR, 64); // 25% Duty Cycle
    pwm = 25;
    Serial.print("  ");
    Serial.print(distance);
    Serial.print("cm");
    Serial.print("  ");
    Serial.println(pwm);
  }
  else if (distance < 30) {
    digitalWrite(driverIn3, HIGH);
    digitalWrite(driverIn4, LOW);
    analogWrite(driverPwmR, 127); // 50% Duty Cycle
    pwm = 50 ;
    Serial.print("  ");
    Serial.print(distance);
    Serial.print("cm");
    Serial.print("  ");
    Serial.println(pwm);
  }
  else                   {
    digitalWrite(driverIn3, HIGH);
    digitalWrite(driverIn4, LOW);
    analogWrite(driverPwmR, 255); // 100% Duty Cycle
    pwm = 100;
    Serial.print("  ");
    Serial.print(distance);
    Serial.print("cm");
    Serial.print(" ");
    Serial.println(pwm);
  }

  // else if (distance < 1000) {
  //   digitalWrite(driverIn3, HIGH);
  //   digitalWrite(driverIn4, LOW);
  //   analogWrite(driverPwmR, 255); // 100% Duty Cycle
  //   pwm = 100;
  //   Serial.print(" ");
  //   Serial.print(distance);
  //   Serial.print("cm");
  //   Serial.print(" ");
  //   Serial.println(pwm);
  // }
  // else if (distance < 10000) {
  //   digitalWrite(driverIn3, HIGH);
  //   digitalWrite(driverIn4, LOW);
  //   analogWrite(driverPwmR, 255); // 100% Duty Cycle
  //   pwm = 100;
  //   Serial.print(distance);
  //   Serial.print("cm");
  //   Serial.print(" ");
  //   Serial.println(pwm);
  // }

  // else if (distance > 10000) {
  //   distance = pulseIn(ECHO, LOW);
  //   digitalWrite(driverIn3, LOW);
  //   digitalWrite(driverIn4, LOW);
  //   analogWrite(driverPwmR, 0); // 100% Duty Cycle
  //   pwm = 0;
  //   Serial.print("   ");
  //   Serial.print(distance);
  //   Serial.print("cm");
  //   Serial.print("   ");
  //   Serial.println(pwm);
  // }
  delay(1000);
}