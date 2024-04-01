import time

from ArduinoConnection import ArduinoConnection


def word_to_binary(word):
    binary_repr = ' '.join(format(ord(letter), 'b') for letter in word)
    return binary_repr


def binary_to_word(binary_str):
    word = ''.join(chr(int(binary, 2)) for binary in binary_str.split())
    return word


if __name__ == "__main__":
    sender = ArduinoConnection("Sender", "COM7", 9600)
    receiver = ArduinoConnection("Receiver", "COM5", 9600)
    jammer = ArduinoConnection("Jammer", "COM6", 9600)

    sender.start()
    receiver.start()
    jammer.start()

    time.sleep(5)
    time.sleep(30)
    print("Time out")
    sender.save_data("Data")
    sender.run = False
    receiver.save_data("Data")
    receiver.run = False
    jammer.save_data("Data")
    jammer.run = False
