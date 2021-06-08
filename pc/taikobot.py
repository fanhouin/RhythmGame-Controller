import cv2
import serial
import numpy as np 
from PIL import ImageGrab 
import time
import pyautogui

ser = serial.Serial('COM6', 9600)
pyautogui.PAUSE = 0.0001

keyboard = Controller()

lasttime_red = time.time()
lasttime_blue = time.time()
lasttime_yellow = time.time()

while(1):
    screen = np.array(ImageGrab.grab(bbox=(960,600,980,660)))
    
    thescreen =  cv2.cvtColor(screen,cv2.COLOR_BGR2RGB)
    maskframe = cv2.cvtColor(thescreen,cv2.COLOR_BGR2HSV)

    low_red = np.array([5,194,232])
    high_red= np.array([15,255,255])
    mask_red = cv2.inRange(maskframe,low_red,high_red)

    low_blue = np.array([87,98,189])
    high_blue= np.array([91,255,255])
    mask_blue = cv2.inRange(maskframe,low_blue,high_blue)

    low_yellow = np.array([20,230,230])
    high_yellow = np.array([30,255,255])
    mask_yellow = cv2.inRange(maskframe,low_yellow,high_yellow)


    if time.time() - lasttime_blue >= 0.1 and mask_blue.sum():
        #pyautogui.press('D')
        ser.write(b'J\n')
        lasttime_blue = time.time()

    if time.time() - lasttime_red >= 0.1 and mask_red.sum():
        #pyautogui.press('F')
        ser.write(b'K\n')
        lasttime_red = time.time()
        
    if(time.time() - lasttime_yellow >= 0.1 and mask_yellow.sum()):
        ser.write(b'J\n')
        ser.write(b'K\n')
        lasttime_yellow = time.time()

    #cv2.imshow('window',cv2.cvtColor(screen,cv2.COLOR_BGR2RGB))
    #cv2.imshow('redframe',mask_red)
    #cv2.imshow('blueframe',mask_blue)
    #cv2.imshow('mask_yellow',mask_yellow)
    #cv2.imshow('maskframe',thescreen)
    # print(mask_red[15][75])
    # if(cv2.waitKey(25) & 0xFF == ord('q')):
    #     cv2.destroyAllWindows()
    #     break