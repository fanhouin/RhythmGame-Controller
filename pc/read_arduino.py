import serial
import time
import pyautogui
from pynput.keyboard import Key,Controller

pyautogui.PAUSE = 0.0001

keyboard = Controller()
ser = serial.Serial('COM5', 9600)
key = ['D','F','J','K','J','K']
press_state = [0,0,0,0,0,0] #0: release   1:press

while True:
    while ser.in_waiting:
        data = ser.readline().decode()
        print(data)
        data_arr = data.split(',')
        for i in range(0,6):
            if(data_arr[i] == '1' and press_state[i] == 0):
                press_state[i] = 1
                pyautogui.keyDown(key[i])

            elif(data_arr[i] == '0' and press_state[i] == 1):
                #passDDDDDDD
                press_state[i] = 0
                pyautogui.keyUp(key[i])