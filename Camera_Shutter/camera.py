import serial
import pyautogui

# pip install pyserial
# pip install pyautogui

port = serial.Serial("COM5", 9600)
while True:
    line = port.readline()  # read data line by line
    if line:
        try:
            string = line.decode('utf-8', errors='ignore')
            num = int(string)  # convert the Unicode string to an int
            if num == 1:
                print("hi")
                pyautogui.press('space')  # it will press the space key!
        except UnicodeDecodeError as e:
            print(f"Error decoding line: {e}")
