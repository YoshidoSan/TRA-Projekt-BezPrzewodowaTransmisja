import datetime

import serial
import threading
import time
from datetime import datetime
import pandas as pd


class ArduinoConnection:
    received_history = pd.DataFrame(columns=['time', 'value'])
    send_history = pd.DataFrame(columns=['time', 'value', 'full_msg'])
    run = True

    def __init__(self, role: str, port: str, baud_rate: int):
        self.role = role
        self.ser = serial.Serial(port, baud_rate)

    def save_data(self, path):
        name = f"{path}/{self.role}"
        self.received_history.to_csv(name+"_received.csv", index=False)
        self.send_history.to_csv(name + "_send.csv", index=False)

    def send(self, msg):
        print(f"Send: {msg}")
        self.ser.write((msg + "\n").encode())

    def listen_thread(self):
        while self.run:
            line = self.ser.readline().strip()
            new_row = {'time': time.time_ns(), 'value': line}
            self.received_history = pd.concat([self.received_history, pd.DataFrame([new_row])], ignore_index=True)
            # print(f"{self.role}: {line}")
            # try:
            #     data = int(line)
            #     new_row = {'time': time.time(), 'value': data, 'full_msg': line}
            #     self.received_history = pd.concat([self.received_history, pd.DataFrame([new_row])], ignore_index=True)
            # except Exception:
            #     new_row = {'time': time.time(), 'value': None, 'full_msg': line}
            #     self.received_history = pd.concat([self.received_history, pd.DataFrame([new_row])], ignore_index=True)

            # if self.role == "Receiver" and line != "" and line != "Received":
            #     try:
            #         data = line
            #
            #         new_row = {'time': time.time(), 'value': int(data), 'full_msg': line}
            #
            #         self.received_history = pd.concat([self.received_history, pd.DataFrame([new_row])], ignore_index=True)
            #
            #     except Exception as e:
            #         print(e)
            #         raise e

    def start(self):
        listen_thread = threading.Thread(target=self.listen_thread)
        listen_thread.start()
