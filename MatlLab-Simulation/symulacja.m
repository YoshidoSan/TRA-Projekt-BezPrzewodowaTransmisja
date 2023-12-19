%% Michał Kwarciński
clear all;
close all;
clc;

% Parametry symulacji
Fs = 9600;         % Częstotliwość próbkowania
Tb = 1000/Fs;            % Czas trwania jednego bitu
fc = 100;           % Częstotliwość nośna
Amplitude = 1;     % Amplituda sygnału nośnego
delay = Fs/10;

% Dane wejściowe
word = 'SOS';
input_data = stringToBinaryVector(word);
% disp(input_data)


figure;
stem(input_data, 'LineWidth', 2);
title('Zakodowane bity');
xlabel('Nr bitu');
ylabel('Wartość');
grid on;

% Tworzenie sygnału ASK
t = 0:1/Fs:Tb-1/Fs;  % Wektor czasu dla jednego bitu

clear ask_signal decoded_bits;
ask_signal = [];     % Inicjalizacja sygnału ASK
%% bez zakłóceń
disp("BEZ ZAKLOCEN")
for bit = input_data
    if bit == 1
        ask_signal = [ask_signal Amplitude * sin(2 * pi * fc * t)];
    else
        ask_signal = [ask_signal zeros(1, length(t))];
    end
end

% Wyświetlanie sygnału ASK
figure;
plot(ask_signal);
title('Sygnał ASK - bez zaklocen');
xlabel('Chwila');
ylabel('Amplituda');
grid on;

% Demodulacja sygnału ASK
demodulated_signal = ask_signal .* repmat(sin(2 * pi * fc * t), 1, length(input_data));

figure;
plot(repmat(sin(2 * pi * fc * t), 1, length(input_data)))

% Otrzymywanie zdekodowanych bitów
decoded_bits = zeros(1, length(input_data));
for i = 1:length(input_data)
    start_index = (i - 1) * length(t) + 1;
    end_index = i * length(t);
    decoded_bits(i) = sum(demodulated_signal(start_index:end_index)) > 0;
end

% disp(decoded_bits)

% Wyświetlanie zdekodowanych bitów
figure;
stem(decoded_bits, 'LineWidth', 2);
title('Zdekodowane bity - bez zaklocen');
xlabel('Nr bitu');
ylabel('Wartość');
grid on;

% Konwersja zdekodowanych bitów na postać tekstową
% Wyświetlanie zdekodowanego tekstu
disp('Otrzymany tekst:');
disp(binaryVectorToString(decoded_bits))
disp('Roznice:')
disp(compareVectors(input_data, decoded_bits))


clear ask_signal decoded_bits;
ask_signal = [];     % Inicjalizacja sygnału ASK
%% z szumem Gaussowskim
disp("SZUM GAUSSOWSKI")
for bit = input_data
    if bit == 1
        signal = Amplitude * sin(2 * pi * fc * t);
    else
        signal = zeros(1, length(t));
    end

    % Dodanie szumu gaussowskiego
    noise = 0.1 * randn(1, length(t));  % Modyfikowalna amplituda szumu
    noisy_signal = signal + noise;

    ask_signal = [ask_signal noisy_signal];
end

% Wyświetlanie sygnału ASK
figure;
plot(ask_signal);
title('Sygnał ASK - szum');
xlabel('Chwila');
ylabel('Amplituda');
grid on;

% Demodulacja sygnału ASK
demodulated_signal = ask_signal .* repmat(sin(2 * pi * fc * t), 1, length(input_data));

% Otrzymywanie zdekodowanych bitów
decoded_bits = zeros(1, length(input_data));
for i = 1:length(input_data)
    start_index = (i - 1) * length(t) + 1;
    end_index = i * length(t);
    decoded_bits(i) = sum(demodulated_signal(start_index:end_index)) > 0;
end

% disp(decoded_bits)

% Wyświetlanie zdekodowanych bitów
figure;
stem(decoded_bits, 'LineWidth', 2);
title('Zdekodowane bity - SZUM');
xlabel('Nr bitu');
ylabel('Wartość');
grid on;

% Konwersja zdekodowanych bitów na postać tekstową
% Wyświetlanie zdekodowanego tekstu
disp('Otrzymany tekst:');
disp(binaryVectorToString(decoded_bits))
disp('Roznice:')
disp(compareVectors(input_data, decoded_bits))


clear ask_signal decoded_bits;
ask_signal = [];     % Inicjalizacja sygnału ASK
%% z zakłoceniem generującym opóźnienie
disp("OPOZNIENIE")
signal = [];

for bit = input_data
    if bit == 1
        signal = [signal Amplitude * sin(2 * pi * fc * t)];
    else
        signal = [signal zeros(1, length(t))];
    end
end

ask_signal = zeros(1, length(signal)); % Initialize ask_signal with zeros
for i = 1:length(signal)
    if i > delay
        ask_signal(i) = signal(i) + signal(i - delay);
    else
        ask_signal(i) = signal(i);
    end
end


% Wyświetlanie sygnału ASK
figure;
plot(ask_signal);
title('Sygnał ASK - OPOZNIENIE');
xlabel('Chwila');
ylabel('Amplituda');
grid on;

% Demodulacja sygnału ASK
demodulated_signal = ask_signal .* repmat(sin(2 * pi * fc * t), 1, length(input_data));

% Otrzymywanie zdekodowanych bitów
decoded_bits = zeros(1, length(input_data));
for i = 1:length(input_data)
    start_index = (i - 1) * length(t) + 1;
    end_index = i * length(t);
    decoded_bits(i) = sum(demodulated_signal(start_index:end_index)) > 0;
end

% disp(decoded_bits)

% Wyświetlanie zdekodowanych bitów
figure;
stem(decoded_bits, 'LineWidth', 2);
title('Zdekodowane bity - OPOZNIENIE');
xlabel('Nr bitu');
ylabel('Wartość');
grid on;

% Konwersja zdekodowanych bitów na postać tekstową
% Wyświetlanie zdekodowanego tekstu
disp('Otrzymany tekst:');
disp(binaryVectorToString(decoded_bits))
disp('Roznice:')
disp(compareVectors(input_data, decoded_bits))


clear ask_signal decoded_bits;
ask_signal = [];     % Inicjalizacja sygnału ASK
%% z zakłoceniem generującym opóźnienie i szumem Gausowskim
disp("SZUM i OPOZNIENIE")
signal = [];
for bit = input_data
    if bit == 1
        temp_signal = Amplitude * sin(2 * pi * fc * t);
    else
        temp_signal = zeros(1, length(t));
    end

    % Dodanie szumu gaussowskiego
    noise = 0.1 * randn(1, length(t));  % Modyfikowalna amplituda szumu
    noisy_signal = temp_signal + noise;

    signal = [signal noisy_signal];
end

ask_signal = zeros(1, length(signal)); % Initialize ask_signal with zeros
for i = 1:length(signal)
    if i > delay
        ask_signal(i) = signal(i) + signal(i - delay);
    else
        ask_signal(i) = signal(i);
    end
end


% Wyświetlanie sygnału ASK
figure;
plot(ask_signal);
title('Sygnał ASK - SZUM i OPOZNIENIE');
xlabel('Chwila');
ylabel('Amplituda');
grid on;

% Demodulacja sygnału ASK
demodulated_signal = ask_signal .* repmat(sin(2 * pi * fc * t), 1, length(input_data));

% Otrzymywanie zdekodowanych bitów
decoded_bits = zeros(1, length(input_data));
for i = 1:length(input_data)
    start_index = (i - 1) * length(t) + 1;
    end_index = i * length(t);
    decoded_bits(i) = sum(demodulated_signal(start_index:end_index)) > 0;
end

% disp(decoded_bits)

% Wyświetlanie zdekodowanych bitów
figure;
stem(decoded_bits, 'LineWidth', 2);
title('Zdekodowane bity - SZUM i OPOZNIENI');
xlabel('Nr bitu');
ylabel('Wartość');
grid on;

% Konwersja zdekodowanych bitów na postać tekstową
% Wyświetlanie zdekodowanego tekstu
disp('Otrzymany tekst:');
disp(binaryVectorToString(decoded_bits))
disp('Roznice:')
disp(compareVectors(input_data, decoded_bits))
