import time

from ArduinoConnection import ArduinoConnection


def word_to_binary(word):
    binary_repr = ' '.join(format(ord(letter), 'b') for letter in word)
    return binary_repr


def binary_to_word(binary_str):
    word = ''.join(chr(int(binary, 2)) for binary in binary_str.split())
    return word


if __name__ == "__main__":
    sender = ArduinoConnection("Sender", "COM6", 9600)
    receiver = ArduinoConnection("Receiver", "COM5", 9600)
    # jammer = ArduinoConnection("Jammer", "COM1", 9600)

    sender.start()
    receiver.start()

    word = 'SOS'
    print(f'Send word: {word}')
    binary_representation = word_to_binary(word)
    print(binary_representation)
    print(f'Send word binary representation: {binary_representation}')
    sender.send(binary_representation)
    time.sleep(5)
    sender.save_data("Data")
    sender.run = False
    receiver.save_data("Data")
    receiver.run = False
    del sender, receiver
    # word = binary_to_word(binary_representation)
    # print(word)
