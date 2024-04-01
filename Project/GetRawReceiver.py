import time

from ArduinoConnection import ArduinoConnection


def word_to_binary(word):
    binary_repr = ' '.join(format(ord(letter), 'b') for letter in word)
    return binary_repr


def binary_to_word(binary_str):
    word = ''.join(chr(int(binary, 2)) for binary in binary_str.split())
    return word


if __name__ == "__main__":
    receiver = ArduinoConnection("Receiver", "COM5", 115200)

    receiver.start()

    time.sleep(10)
    print("Time out")
    receiver.save_data("Data")
    receiver.run = False
