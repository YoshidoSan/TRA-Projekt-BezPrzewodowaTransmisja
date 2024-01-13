import pandas as pd
import matplotlib.pyplot as plt
# import re


# def find_repeated_patterns(input_string, pattern_length=11):
#     pattern = re.compile(r'(.{%d})(?=.{%d})' % (pattern_length, pattern_length), flags=re.DOTALL)
#     matches = pattern.findall(input_string)
#
#     repeated_patterns = [match for match in set(matches) if matches.count(match) >= 2]
#
#     return repeated_patterns


def convert_third_char_to_int(df, column_name):
    # Zamiana trzeciego znaku na liczbę całkowitą dla każdego ciągu znaków w kolumnie
    df[column_name] = df[column_name].apply(lambda x: list(x))
    df[column_name] = df[column_name].apply(lambda x: x[2])
    df = df[df[column_name].apply(lambda x: x.isdigit() if isinstance(x, str) else False)]
    df[column_name] = df[column_name].apply(lambda x: int(x))
    return df


# Wczytaj DataFrame
df = pd.read_csv('Data/Receiver_received.csv')
df['Z'] = 3
kolumna_do_wykresu = 'value'
df = convert_third_char_to_int(df, 'value')
x = list(df["value"])
length = 250
for i in range(len(df)):
    if i+length > len(df):
        break
    if all([number == 0 for number in x[i:i+length]]):
        df.loc[i, 'Z'] = 4
df2 = pd.read_csv('Data/Sender_received.csv')
data = [2 for _ in range(len(df2))]



# Utwórz wykres
plt.scatter(df["time"], df["value"], color="blue")
plt.scatter(df2["time"], data, color="red")
plt.scatter(df["time"], df["Z"], color="pink")
plt.step(df["time"], df["Z"], where='post', color='green')
plt.title(f'Wykres kolumny {kolumna_do_wykresu}')
plt.xlabel('Indeks')
plt.ylabel(kolumna_do_wykresu)

# Zaznacz powtarzające się wzorce na wykresie

# long_string = ''.join(df['value'].astype(str))
# repeated_patterns = find_repeated_patterns(long_string)
#
# for pattern in repeated_patterns:
#     pattern_start = long_string.find(pattern)
#     pattern_end = pattern_start + len(pattern)
#
#     plt.axvspan(df["time"].iloc[pattern_start], df["time"].iloc[pattern_end], facecolor='r', alpha=0.3)

plt.show()
