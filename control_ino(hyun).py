import serial


port = ''
brate = 115200
ard = serial.Serial(port, brate, timeout=None)

print('1을 입력하면 작동')

while True :
    num = input()

    if (num == '1'):
        num = num.encode('utf-8')
        ard.write(num)
