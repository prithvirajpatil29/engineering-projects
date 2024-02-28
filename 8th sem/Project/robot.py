import RPi.GPIO as GPIO
import serial

temp = serial.Serial("/dev/ttyS0",9600, timeout = 0.1)

m1a = 5
m1b = 6

m2a = 13
m2b = 19

data = ""

fr = "f"
bc = "b"
lt = "l"
rt = "r"
st = "s"

def forward():
  
    GPIO.output(m1a, True) # 
    GPIO.output(m1b, False) #
    
    GPIO.output(m2a, True) # 
    GPIO.output(m2b, False) #

def backward():
  
    GPIO.output(m1a, False) # 
    GPIO.output(m1b, True) #
    
    GPIO.output(m2a, False) # 
    GPIO.output(m2b, True) #

def left():
  
    GPIO.output(m1a, False) # 
    GPIO.output(m1b, True) #
    
    GPIO.output(m2a, True) # 
    GPIO.output(m2b, False) #

def right():
  
    
    GPIO.output(m1a, True) # 
    GPIO.output(m1b, False) #
    
    GPIO.output(m2a, False) # 
    GPIO.output(m2b, True) #

def stop():
  
    GPIO.output(m1a, False) # 
    GPIO.output(m1b, False) #
    
    GPIO.output(m2a, False) # 
    GPIO.output(m2b, False) #

    
 
def main():
  # Main program block
  
  mon = 0
  
  print ("Welcome to project...")

  GPIO.setmode(GPIO.BCM)       # Use BCM GPIO numbers
  GPIO.setup(m1a, GPIO.OUT) # motor pin1
  GPIO.setup(m1b, GPIO.OUT) # motor pin1
  GPIO.setup(m2a, GPIO.OUT) # motor pin1
  GPIO.setup(m2b, GPIO.OUT) # motor pin1
  
  stop();

  time.sleep(1) # 3 second delay

  while True: 
    data = temp.read()
    #print(data)

    if data.rfind(fr) > -1:
        print ("Forward")
        forward();

    elif data.rfind(bc) > -1:
        print ("Backward")
        backward();

    elif data.rfind(lt) > -1:
        print ("left")
        left();

    elif data.rfind(rt) > -1:
        print ("right")
        right();

    elif data.rfind(st) > -1:
        print ("stop")
        stop();      
            

if __name__ == '__main__':
 
  try:
    main()
  except KeyboardInterrupt:
    pass
  finally:
    GPIO.cleanup()
