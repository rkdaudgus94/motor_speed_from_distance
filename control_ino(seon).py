# 파이썬 -> 아두이노 (모터 구동)..

import serial

baudrate = 115200
arduino = serial.Serial('com3', 115200, timeout = None)

while True :
    setha = input("각도(setha)를 입력하시오 : ")

    setha1 = setha.encode('utf-8')
    arduino.write(setha1)
    data = arduino.readline()
    data = data.decode()

    print("setha : ", setha)
    print(data)