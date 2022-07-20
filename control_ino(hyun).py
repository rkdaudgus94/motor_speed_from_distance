import serial
import time
import matplotlib as plot
import numpy as np


port = 'COM5'
brate = 9600
ard = serial.Serial(port, brate)
dis = []
spd = []
t = []
print('1을 입력하면 작동')
num= input()
try : 
    while True :
        num1 = num.encode('utf-8')
        ard.write(num1) # num 의 값을 아두이노에 전송
        while num == '1' :
            data = ard.readline()
            distance = data.decode()[:-6]
            speed = data.decode()[-4:-2]
            distance = float(distance)
            speed = float(speed)
            print(distance,"cm",speed,'(pwm)')
            t= t.append(0.5)
            print(t)
            # dis = int(distance)

except KeyboardInterrupt :
    num = 0
    ard.write(num)
    print('end')
    exit()
    
    
    # speed = ard.readline()
    # speed = speed[:-2].decode()
    # print(speed)1
    # spd = int(speed)