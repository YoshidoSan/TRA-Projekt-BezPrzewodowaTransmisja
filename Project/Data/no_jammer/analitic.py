import pandas as pd
import matplotlib.pyplot as plt

# Wczytaj DataFrame
df1 = pd.read_csv('Receiver_received_nojammer.csv')
df2 = pd.read_csv('Sender_received_nojammer.csv')
merge = pd.concat([df1, df2])
merge = merge.sort_values(by='time')
merge["value_list"] = merge["value"].str.split("_")
merge.reset_index(drop=True, inplace=True)
print(merge)
merge["status"] = merge["value_list"].apply(lambda x: x[0])
merge["rep"] = merge["value_list"].apply(lambda x: x[2] if x[0] == "send" else None)
merge["protocol"] = merge["value_list"].apply(lambda x: x[4] if x[0] == "send" else x[6])
merge["number"] = merge["value_list"].apply(lambda x: x[6] if x[0] == "send" else x[4])
merge["decimal"] = merge["value_list"].apply(lambda x: None if x[0] == "send" else x[2])
merge = merge[merge["protocol"].isin([f'{i}' for i in range(1, 13)])]
merge.reset_index(inplace=True)
merge = merge.iloc[0:1477]
for i in range(len(merge)):
    value = merge["rep"][i]
    if value is None:
        temp_df = merge[0:i]
        last_not_none_index = temp_df[temp_df['rep'] != None].index[-1]
        last_not_none_value = merge["rep"][last_not_none_index]
        merge["rep"][i] = last_not_none_value

print(merge)
merge.to_csv("data.csv")


data_test_rep = [[], []]
for i in range(1, 10):
    print(f"Repetition: {i}")
    df = merge[merge["rep"] == f"{i}"]
    first_index = df.index[0]
    last_index = df.index[-1]
    print(first_index, last_index)
    count_send = len(df[df['status'] == "send"])
    count_received = len(df[df['status'] == "rec"])
    print(f"Send msg: {count_send}, received msg: {count_received} => {(100*count_received)/(count_send*i)}%")
    data_test_rep[0].append(i)
    data_test_rep[1].append((100*count_received)/(count_send*i))

plt.plot(data_test_rep[0], data_test_rep[1])
plt.xlabel('Ilość powtorzeń')
plt.ylabel('Procent otrzymanych informacji')
plt.savefig('wykres1.png')
plt.close()

print(merge)
df = merge[merge["rep"] == "9"]
data_test_rep = [[], []]
for i in range(1, 13):
    print(f"Protocol: {i}")
    temp_df = df[df["protocol"] == f"{i}"]
    count_send = len(temp_df[temp_df['status'] == "send"])
    count_received = len(temp_df[temp_df['status'] == "rec"])
    print(f"Send msg: {count_send}, received msg: {count_received} => {(100*count_received)/(count_send*9)}%")
    data_test_rep[0].append(i)
    data_test_rep[1].append((100*count_received)/(count_send*9))


plt.scatter(data_test_rep[0], data_test_rep[1])
plt.xlabel('Numer protokołu')
plt.ylabel('Procent otrzymanych informacji')
plt.savefig('wykres2.png')
