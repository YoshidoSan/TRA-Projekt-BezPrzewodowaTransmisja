function diff = compareVectors(vector1, vector2)
    len = length(vector1);
    if length(vector1) ~= length(vector2)
        error('Wektory muszą mieć taką samą długość.');
    end

    diff = 0;
    for i=1:len
        if vector1(i) ~= vector2(i)
            diff = diff + 1;
        end
    end
end