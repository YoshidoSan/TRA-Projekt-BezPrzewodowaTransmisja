function binary = stringToBinaryVector(inputString)
    string_binary = '';
    for i = 1:length(inputString)
        string_binary = [string_binary dec2bin(inputString(i), 8)];
    end
    binary = string_binary - '0';
end