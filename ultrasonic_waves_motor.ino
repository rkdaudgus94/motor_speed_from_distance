#define encoderPinA  2
#define encoderPinB 3

#define TRIG 4
#define ECHO 5

#define driverIn3 9
#define driverIn4 10
#define driverPwmR 11

int data;
int pwm;
float rpm;
float distance;
float encoderPosRight = 0;

void distance_motor();
void cal_rpm();

void doEncoderA() {
  encoderPosRight  += (digitalRead(encoderPinA) == digitalRead(encoderPinB)) ? 1 : -1;
}
void doEncoderB() {
  encoderPosRight  += (digitalRead(encoderPinA) == digitalRead(encoderPinB)) ? -1 : 1;
}

void interruptInit() {
  attachInterrupt(0, doEncoderA, CHANGE);   //uno pin 2
  attachInterrupt(1, doEncoderB, CHANGE);   //uno pin 3
}

void setup() {
  Serial.begin(115200);
  pinMode(TRIG, OUTPUT);
  pinMode(ECHO, INPUT);
  pinMode(driverIn3, OUTPUT);
  pinMode(driverIn4, OUTPUT);
  pinMode(driverPwmR, OUTPUT);
  pinMode(encoderPinA, INPUT_PULLUP);
  pinMode(encoderPinB, INPUT_PULLUP);
  interruptInit();
  digitalWrite(driverIn3, LOW);
  digitalWrite(driverIn4, LOW);
  analogWrite(driverPwmR, 0);
}

void loop() {
  if (Serial.available()) {
    data = Serial.read(); // 데이터를 읽어서 'data'를 저장
  }
  while (data == '1') {
    cal_rpm();
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

  if (distance < 10) {
    digitalWrite(driverIn3, HIGH);
    digitalWrite(driverIn4, LOW);
    analogWrite(driverPwmR, 0); // 0% Duty Cycle
    Serial.print(" ");
    Serial.print(distance);
    Serial.print("cm");
    Serial.println(rpm);
  }
  else if (distance < 20) {
    digitalWrite(driverIn3, HIGH);
    digitalWrite(driverIn4, LOW);
    analogWrite(driverPwmR, 64); // 25% Duty Cycle
    Serial.print(distance);
    Serial.print("cm");
    Serial.println(rpm);
  }
  else if (distance < 30) {
    digitalWrite(driverIn3, HIGH);
    digitalWrite(driverIn4, LOW);
    analogWrite(driverPwmR, 127); // 50% Duty Cycle
    Serial.print(distance);
    Serial.print("cm");
    Serial.println(rpm);
  }
  else if (distance < 50) {
    digitalWrite(driverIn3, HIGH);
    digitalWrite(driverIn4, LOW);
    analogWrite(driverPwmR, 255); // 100% Duty Cycle
    Serial.print(distance);
    Serial.print("cm");
    Serial.println(rpm);
  }

  else if (distance > 50) {
    distance = 50;
    digitalWrite(driverIn3, HIGH);
    digitalWrite(driverIn4, LOW);
    analogWrite(driverPwmR, 255); // 100% Duty Cycle
    Serial.print(distance);
    Serial.print("cm");
    Serial.println(rpm);
  }
  delay(1000);
}

void cal_rpm() {
  rpm = encoderPosRight / 57;
  rpm *= 60;
  rpm /= -90;
  encoderPosRight = 0;
}