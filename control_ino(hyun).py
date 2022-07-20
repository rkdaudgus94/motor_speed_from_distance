import serial
import time
import matplotlib.pyplot as plt
import numpy as np
from drawnow import *


port = 'COM5'
brate = 9600
ard = serial.Serial(port, brate)
dis = []
spd = []
t = []

def show_plot() :
    plt.subplot(211)
    plt.plot(t,dis,label='distance')
    plt.legend('distance(cm)')
    plt.grid()
    plt.xlabel('t(sec)')
    plt.ylabel('distance(cm)')

    plt.subplot(212)
    plt.plot(t,spd,label='speed')
    plt.legend('speed(%)')
    plt.grid()
    plt.xlabel('t(sec)')
    plt.ylabel('speed(%)')
    


print('1을 입력하면 작동')
num= input()


try : 
    while True :
        num1 = num.encode('utf-8')
        ard.write(num1) # num 의 값을 아두이노에 전송
        while num == '1' :
            data = ard.readline()
            distance = data.decode()[:-7]
            speed = data.decode()[-4:-2]
            distance = float(distance)
            speed = float(speed)
            print(distance,"cm",speed,'(pwm)')
            dis = np.append(dis,distance)
            spd = np.append(spd,speed)
            t = np.append(t,0.5)
            
            # dis = int(distance)
            drawnow(show_plot)
except KeyboardInterrupt :
    num = 0
    ard.write(num)
    print('end')
    exit()
    
    
    # speed = ard.readline()
    # speed = speed[:-2].decode()
    # print(speed)1
    # spd = int(speed)