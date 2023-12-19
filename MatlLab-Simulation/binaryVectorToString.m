function outputString = binaryVectorToString(binaryVector)
    % Sprawdzenie, czy długość wektora binarnego jest wielokrotnością 8
    if mod(length(binaryVector), 8) ~= 0
        error('Długość wektora binarnego musi być wielokrotnością 8.');
    end
    
    outputString = '';
    
    % Przetwarzanie wektora binarnego po 8 bitów na raz
    for i = 1:8:length(binaryVector)
        % Wybieranie kolejnych 8 bitów
        binaryChunk = binaryVector(i:i+7);
        
        % Konwersja binarnego wektora na liczby dziesiętne
        decimalValue = bin2dec(num2str(binaryChunk));
        
        % Konwersja liczby dziesiętnej na znak ASCII
        outputString = [outputString, char(decimalValue)];
    end
end
