#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

class RomanArabic
{
private:
    static const string romanNumbers[13];
    static const int arabicValues[13];

public:
    static string arabic2roman (int arabic) throw (string)
    {
        if (arabic <= 0 || arabic > 3999)
        {
            throw (string) (" - liczba spoza zakresu [1,3999].");
        }
        string roman = "";
        int pointer = 12;
        while (arabic > 0)
        {
            if (RomanArabic::arabicValues[pointer]<=arabic)
            {
                roman += RomanArabic::romanNumbers[pointer];
                arabic-=RomanArabic::arabicValues[pointer];
            }
            else
            {
                pointer-=1;
            }
        }
        return roman;
    }

    static int roman2arabic (string roman) throw (string)
    {
        int pointer = 0;
        int arabic = 0;
        bool is_found;
        string current;
        while (pointer < roman.length())
        {
            is_found = false;
            if (roman.length()-pointer>1)
            {
                current = roman[pointer];
                current += roman[pointer+1];
                for (int i=0; i<=12; i++)
                {
                    if (current == RomanArabic::romanNumbers[i])
                    {
                        arabic+=RomanArabic::arabicValues[i];
                        pointer+=2;
                        is_found = true;
                        break;
                    }
                }
                if (is_found)
                {
                    continue;
                }
            }
            current = roman[pointer];
            for (int i=0; i<=12; i++)
            {
                if (current == RomanArabic::romanNumbers[i])
                {
                    arabic+=RomanArabic::arabicValues[i];
                    pointer+=1;
                    is_found=true;
                }
            }
            if (is_found==false)
            {
                throw (string) " - nie jest poprawne w systemie rzymskim.";
            }
        }
        if (roman == RomanArabic::arabic2roman(arabic))
        {
            return arabic;
        }
        else
        {
            throw (string) " - nie jest poprawne w systemie rzymskim.";
        }
    }

};

const string RomanArabic::romanNumbers[13] = { "I","IV","V","IX","X","XL","L","XC","C","CD","D","CM","M" };
const int RomanArabic::arabicValues[13] = { 1, 4, 5, 9, 10, 40, 50, 90, 100, 400, 500, 900, 1000};


int main (int argc, char* argv[])
{
    int n;
    for (int i=1; i<argc; i++)
    {
        n = atoi (argv[i]);
        if (n==0 && argv[i] != "0")
        {
            try
            {
                cout << argv[i] << " = " << RomanArabic::roman2arabic(argv[i]) << " w systemie arabskim." << endl;
            }
            catch (string w)
            {
                cout << argv[i] << w << endl;
            }
        }
        else
        {
            try
            {
                cout << n << " = " << RomanArabic::arabic2roman(n) << " w systemie rzymskim." << endl;
            }
            catch (string w)
            {
                cout << n << w << endl;
            }
        }
    }
    return 0;
}
