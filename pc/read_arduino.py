import serial
import pyautogui

pyautogui.PAUSE = 0.0001

keyboard = Controller()
ser = serial.Serial('COM3', 9600)
key = ['S','D','F','J','K','L']
press_state = [0] * 6 #0: release   1:press

while True:
    while ser.in_waiting:
        data = ser.readline().decode()

        data_arr = data.split(',')
        for i in range(0,6):
            if(data_arr[i] == '1' and press_state[i] == 0):
                press_state[i] = 1
                pyautogui.keyDown(key[i])

            elif(data_arr[i] == '0' and press_state[i] == 1):
                press_state[i] = 0
                pyautogui.keyUp(key[i])