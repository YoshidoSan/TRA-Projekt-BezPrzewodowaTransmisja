import matplotlib.pyplot as plt
import pandas as pd


# df = pd.read_csv("Data/Testy_Otoczenia/rawData/Receiver_received.csv")
df = pd.read_csv("Data/Receiver_received.csv")

plt.plot(df["time"], df["value"])
plt.xlabel('Chwila czasu')
plt.ylabel('Odczytana wartość')
plt.savefig('wykres4.png')
plt.show()
