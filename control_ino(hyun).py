import serial
import time


port = 'COM3'
brate = 115200
ard = serial.Serial(port, brate)
dis = []
spd = []
print('1을 입력하면 작동')
num= input()
try : 
    while True :
        num = num.encode('utf-8')
        ard.write(num) # num 의 값을 아두이노에 전송
        while num == 1 :
            distance = ard.readline()
            distance = distance[:-2].decode()
            print(distance)
            dis = int(distance)

except KeyboardInterrupt :
    num = 0
    ard.write(num)
    print('end')
    sys.exit()
    
    
    # speed = ard.readline()
    # speed = speed[:-2].decode()
    # print(speed)1
    # spd = int(speed)