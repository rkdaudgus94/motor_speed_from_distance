#define TRIG 4
#define ECHO 5

#define driverIn3 9
#define driverIn4 10
#define driverPwmR 11

int distance;
int data;
int pwm;
int dis;
void setup() {
   
    Serial.begin(9600);
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
    
      digitalWrite(TRIG, HIGH);
      delay(10);
      digitalWrite(TRIG, LOW);
    
      float distance = pulseIn(ECHO, HIGH)/58.8;
     

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
        analogWrite(driverPwmR, 125);
        
      }
      else if (distance > 30) {
        digitalWrite(driverIn3, HIGH);
        digitalWrite(driverIn4, LOW);
        analogWrite(driverPwmR, 255);
       
      }
      dis = analogRead(distance);
      pwm = analogRead(driverPwmR);
      Serial.println(dis);
      Serial.println(pwm);

      delay(100);

}