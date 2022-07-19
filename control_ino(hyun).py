import serial



port = ''
brate = 115200
ard = serial.Serial(port, brate, timeout=None)
dis = []
spd = []
print('1을 입력하면 작동')

while True :
    num = input()

    if (num == '1'):
        num = num.encode('utf-8')
        ard.write(num) # num 의 값을 아두이노에 전송
        time.sleep(0.1)

    
    distance = ard.readline()
    distance = distance[:-2].decode()
    print(distance)
    dis = int(distance)
    

    # speed = ard.readline()
    # speed = speed[:-2].decode()
    # print(speed)
    # spd = int(speed)