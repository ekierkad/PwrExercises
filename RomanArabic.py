class RomanArabic():

    _romanNumbers = ["I", "IV", "V", "IX", "X", "XL", "L", "XC", "C", "CD", "D", "CM", "M"];
    _arabicValues = [1, 4, 5, 9, 10, 40, 50, 90, 100, 400, 500, 900, 1000];

    def arabic2roman(number,printing=False):
        if (type(number) != int):
            return "{} nie jest liczba calkowita".format(number);
        elif (number>3999 or number<1):
            return "Liczba {} nie miesci sie w przedziale <1, 3999>.".format(number);
        num = number;
        string = "";
        pointer=12;
        while (num>0):
            if (RomanArabic._arabicValues[pointer]<=num):
                string+=RomanArabic._romanNumbers[pointer];
                num-=RomanArabic._arabicValues[pointer];
            else:
                pointer-=1;
        if printing:
            return "{} w systemie rzymskim to: {}".format(number,string);
        else:
            return string;

    def roman2arabic(number):
        if(type(number) != str):
            return "{} nie jest stringiem".format(number);
        pointer = 0;
        value = 0;
        while(pointer<len(number)):
            if (len(number)-pointer>1):
                if(number[pointer]+number[pointer+1] in RomanArabic._romanNumbers):
                    value+=RomanArabic._arabicValues[RomanArabic._romanNumbers.index(number[pointer]+number[pointer+1])];
                    pointer+=2;
                elif (number[pointer] in RomanArabic._romanNumbers):
                    value += RomanArabic._arabicValues[RomanArabic._romanNumbers.index(number[pointer])];
                    pointer += 1;
            elif (number[pointer] in RomanArabic._romanNumbers):
                value+=RomanArabic._arabicValues[RomanArabic._romanNumbers.index(number[pointer])];
                pointer+=1;
            else:
                return "Nie rozpoznano znaku w {}".format(number);
        if (number == RomanArabic.arabic2roman(value)):
            return "{} to {} w systemie arabskim".format(number,value);
        else:
            return"{} nie jest poprawnie zapisana w systemie rzymskim".format(number);


if __name__== "__main__":
    for i in ["MDCVI","CCLVIII", 12, "MMXDCVI","XDCA", "XDDD"]:
        print(RomanArabic.roman2arabic(i));

    print("\n");

    for i in [258, -1, 1999, "abab", 3999, 3.5, 5000, 2646, "xd"]:
        print(RomanArabic.arabic2roman(i,True));

# PwrExercises
