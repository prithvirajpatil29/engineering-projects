import socket, traceback
import serial
from time import sleep

import RPi.GPIO as GPIO
import time

GPIO.setmode(GPIO.BCM)
GPIO.setup(17,GPIO.OUT)
GPIO.setup(27,GPIO.OUT)

p=GPIO.PWM(17,50)
p1=GPIO.PWM(27,50)

p.start(4) 
p1.start(4.5) 


while 1:
    try:
        s = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
        s.setsockopt(socket.SOL_SOCKET, socket.SO_REUSEADDR, 1)
        s.setsockopt(socket.SOL_SOCKET, socket.SO_BROADCAST, 1)
        s.bind(('0.0.0.0', 5555))

        print "Listening for broadcasts..."
        time.sleep(0.1)               
        message, address = s.recvfrom(8192)
        no1,no2,x1,y1,z1,no4,x3,y3,z3,no3,x2,y2,z2=message.split(',')
        
        print(message)         #whole message signal
        print(z1 ,z2)
        a1=float(z1)
        b1=float(z2)
        s.close();
        
        pos = mapFromTo(a1,-9,9,1,9)
        print pos
        
        pos1 = mapFromTo(b1,40,-40,1,9)
        print pos1
        
        p1.ChangeDutyCycle(pos1)
        time.sleep(0.1)
        p.ChangeDutyCycle(pos)
        time.sleep(0.1)
        
    except (KeyboardInterrupt, SystemExit):
        raise
    except:
        traceback.print_exc()






