#define TRIG 4
#define ECHO 5

#define driverIn3 9
#define driverIn4 10
#define driverPwmR 11

int data;

void setup() {
   
    Serial.begin(9600);
    pinMode(TRIG, OUTPUT);
    pinMode(ECHO, INPUT);
    pinMode(driverIn3, OUTPUT);
    pinMode(driverIn4, OUTPUT);
    analogRead(driverPwmR);
  }

void loop() {
    while (Serial.available()) {
      data = Serial.read(); // 데이터를 읽어서 'data'를 저장
    }
    while (data == '1') {
      digitalWrite(TRIG, LOW);
      delay(10);
      digitalWrite(TRIG, HIGH);
      delay(10);
      digitalWrite(TRIG, LOW);
    
      float distance = pulseIn(ECHO, HIGH) / 58.8;
     

      if (distance < 10) {
        digitalWrite(driverIn3, HIGH);
        digitalWrite(driverIn4, LOW);
        analogWrite(driverPwmR, 0);
        // pwm = 0;
        
      }
      else if (distance < 20) {
        digitalWrite(driverIn3, HIGH);
        digitalWrite(driverIn4, LOW);
        analogWrite(driverPwmR, 50); // pwm = 50;
      }
      else if (distance < 30) {
        digitalWrite(driverIn3, HIGH);
        digitalWrite(driverIn4, LOW);
        analogWrite(driverPwmR, 125); // pwm = 125;
      }
      else if (distance > 30) {
        digitalWrite(driverIn3, HIGH);
        digitalWrite(driverIn4, LOW);
        analogWrite(driverPwmR, 255); //pwm = 255;
      }
       else if (data == '0') {
        digitalWrite(driverIn3, LOW);
        digitalWrite(driverIn4, LOW);
        analogWrite(driverPwmR, 0); //pwm = 0
        break;
      }
      Serial.print(distance);
      Serial.print(" ");
      Serial.println(driverPwmR);

      delay(100);
    }
}