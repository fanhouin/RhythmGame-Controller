import cv2
import serial
import numpy as np 
from PIL import ImageGrab 
import time
from pynput.keyboard import Key,Controller
import pyautogui

ser = serial.Serial('COM3', 9600)
pyautogui.PAUSE = 0.0001

trackcolor1 = np.uint8([[[43,74,232]]])
realcolor1 = cv2.cvtColor(trackcolor1,cv2.COLOR_BGR2HSV)
trackcolor2 = np.uint8([[[187,189,116]]])
realcolor2 = cv2.cvtColor(trackcolor2,cv2.COLOR_BGR2HSV)
trackcolor3 = np.uint8([[[180,255,255]]])
realcolor3 = cv2.cvtColor(trackcolor3,cv2.COLOR_HSV2BGR)

print(realcolor1,realcolor2,realcolor3)
keyboard = Controller()

lasttime_red = time.time()
lasttime_blue = time.time()

while(1):
    this_time = time.time()
    press_red = False
    press_blue = False
    # image = pyautogui.screenshot()
    # screen = np.array(ImageGrab.grab(bbox=(450,480,600,510)))
    screen = np.array(ImageGrab.grab(bbox=(660,600,800,660)))
    
    thescreen =  cv2.cvtColor(screen,cv2.COLOR_BGR2RGB)
    maskframe = cv2.cvtColor(thescreen,cv2.COLOR_BGR2HSV)

    low_red = np.array([5,208,232])
    high_red= np.array([5,255,255])
    mask_red = cv2.inRange(maskframe,low_red,high_red)

    low_blue = np.array([87,98,189])
    high_blue= np.array([91,255,255])
    mask_blue = cv2.inRange(maskframe,low_blue,high_blue)


    # cv2.imshow('window',cv2.cvtColor(screen,cv2.COLOR_BGR2RGB))
    # cv2.imshow('redframe',mask_red)
    # cv2.imshow('blueframe',mask_blue)
    # cv2.imshow('maskframe',thescreen)
    # print(mask_red[15][75])
    if(mask_red.sum() > 1000):
        press_red = True
    if(mask_blue.sum() > 1000):
        press_blue = True

    if time.time() - lasttime_blue >= 0.08 and mask_blue.sum():
        # keyboard.press('D')
        # keyboard.release('D')
        pyautogui.press('D')
        ser.write(b'D\n')
        press_blue = False
        lasttime_blue = time.time()

    if time.time() - lasttime_red >= 0.08 and mask_red.sum():
        # keyboard.press('F')
        # keyboard.release('F')
        pyautogui.press('F')
        ser.write(b'F\n')
        press_reF = False
        lasttime_red = time.time()
        

    # if(cv2.waitKey(25) & 0xFF == ord('q')):
    #     cv2.destroyAllWindows()
    #     break


    #print(time.time() - this_time)