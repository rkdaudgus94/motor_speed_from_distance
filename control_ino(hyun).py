import serial
import time


port = 'COM5'
brate = 9600
ard = serial.Serial(port, brate)
dis = []
spd = []
print('1을 입력하면 작동')
num= input()
try : 
    while True :
        num1 = num.encode('utf-8')
        ard.write(num1) # num 의 값을 아두이노에 전송
        while num == '1' :
            distance = ard.readline()
            distance = distance.decode()
            print(distance)
            # dis = int(distance)

except KeyboardInterrupt :
    num = 0
    ard.write(num)
    print('end')
    sys.exit()
    
    
    # speed = ard.readline()
    # speed = speed[:-2].decode()
    # print(speed)1
    # spd = int(speed)