import serial
import time
import matplotlib.pyplot as plt
import numpy as np
from drawnow import *


port = 'COM3'
brate = 115200
ard = serial.Serial(port, brate)
dis = []
rpm = []
t = []
t0 = 0
def show_plot() :
    plt.subplot(211)
    plt.plot(t,dis,label='distance')
    plt.legend('distance(cm)')
    plt.grid()
    plt.xlabel('t(sec)')
    plt.ylabel('distance(cm)')
    plt.ylim(0,40)


    plt.subplot(212)
    plt.plot(t,rpm,label='speed')
    plt.legend('speed(%)')
    plt.grid()
    plt.xlabel('t(sec)')
    plt.ylabel('rpm(rpm)')
    plt.ylim(0,100)
    


print('1을 입력하면 작동')
num= input()


try : 
    while True :
        num1 = num.encode('utf-8')
        ard.write(num1) # num 의 값을 아두이노에 전송
        while num == '1' :
            data = ard.readline()
            distance = data.decode()[:-9] #30.00cm72.00
            speed = data.decode()[7:-2]
            distance = float(distance)
            speed = float(speed)
            print(distance,"cm",speed,'(pwm)')
            dis = np.append(dis,distance)
            rpm = np.append(rpm,speed)
            t0 = t0 + 1
            t = np.append(t, t0)
            
            drawnow(show_plot)
except KeyboardInterrupt :
    num = '0'
    num1 = num.encode('utf-8')
    ard.write(num1)
    print('end')
    exit()
    
    
    # speed = ard.readline()
    # speed = speed[:-2].decode()
    # print(speed)1
    # spd = int(speed)