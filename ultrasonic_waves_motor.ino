#define TRIG 4
#define ECHO 5

#define driverIn3 9
#define driverIn4 10
#define driverPwmR 11

int distance;
int data;
void setup() {
   
    Serial.begin(115200);
    pinMode(TRIG, OUTPUT);
    pinMode(ECHO, INPUT);
    pinMode(driverIn3, OUTPUT);
    pinMode(driverIn4, OUTPUT);
    pinMode(driverPwmR, OUTPUT);
    pinMode(A0, INPUT);
  }

  void loop() {
    while (Serial.available()) {
    data = Serial.read(); // 데이터를 읽어서 'data'를 저장
    }
    if (data == 'a') {
      digitalWrite(TRIG, LOW);
      delay(500);
      digitalWrite(TRIG, HIGH);
      delay(500);
      digitalWrite(TRIG, LOW);

      long distance = pulseIn(ECHO, HIGH) / 58.2;
      Serial.println(distance); // 데이터를 시리얼 통신으로 전송

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
      Serial.println(driverPwmR);
      Serial.print(distance);
   

      delay(100);
}
}