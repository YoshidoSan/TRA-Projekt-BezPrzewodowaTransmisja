import datetime

import serial
import threading
import time
from datetime import datetime
import pandas as pd


class ArduinoConnection:
    received_history = pd.DataFrame(columns=['time', 'value', 'full_msg'])
    send_history = pd.DataFrame(columns=['time', 'value', 'full_msg'])
    run = True

    def __init__(self, role: str, port: str, baud_rate: int):
        self.role = role
        self.ser = serial.Serial(port, baud_rate)

    def save_data(self, path):
        time_now = datetime.now()
        name = f"{path}/{self.role}_{time_now.year}_{time_now.month}_{time_now.day}_" \
               f"{time_now.hour}_{time_now.minute}"
        self.received_history.to_csv(name+"_received.csv", index=False)
        self.send_history.to_csv(name + "send.csv", index=False)

    def send(self, msg):
        print(f"Send: {msg}")
        self.ser.write((msg + "\n").encode())

    def listen_thread(self):
        while self.run:
            line = self.ser.readline().decode('utf-8').strip()
            print(f"{self.role}, received: {line}")
            data = line.split("_")
            msg_type = data[0]
            msg_value = float(data[1])
            sample = {'time': datetime.now(), 'msg': 'line', 'value': msg_value}
            if msg_type == "R":
                self.received_history = self.received_history.append(sample, ignore_index=True)
            elif msg_type == "S":
                self.send_history = self.send_history.append(sample, ignore_index=True)

    def start(self):
        listen_thread = threading.Thread(target=self.listen_thread)
        listen_thread.start()
