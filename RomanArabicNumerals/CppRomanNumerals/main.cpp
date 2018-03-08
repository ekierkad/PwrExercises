#include <iostream>
#include <string>
#include <sstream>
#include <ctype.h>
#include <stdlib.h>

using namespace std;

static int arabicValues[] = {1,4,5,9,10,40,50,90,100,400,500,900,1000};
static string romanNumbers[] = {"I", "IV", "V", "IX", "X", "XL", "L", "XC", "C", "CD", "D", "CM", "M"};


string Arabic2Roman(int number)
{
    if ((number < 1) || (number > 3999))
    {
        return "Liczba nie miesci sie w przedziale <1,3999>.";
    }
    int num = number;
    string str = "";
    int p = 12;
    while (num>0)
    {
        if (arabicValues[p] <= num)
        {
            str+=romanNumbers[p];
            num-=arabicValues[p];
        }
        else
        {
            p--;
        }
    }
    return str;
}

bool isInRomN(string str)
{
    unsigned int i;
    for (i=0; i <= sizeof(romanNumbers)/sizeof(string); i++)
    {
        if (romanNumbers[i].compare(str) == 0)
        {
            return true;
        }
    }
    return false;
}
int index(string str)
{
    unsigned int i;
    for (i=0; i <= sizeof(romanNumbers)/sizeof(string); i++)
    {
        if (romanNumbers[i].compare(str) == 0)
        {
            return i;
        }
    }
    return -1;
}

int Roman2Arabic(string RomN)
{
    unsigned int p = 0;
    int value = 0;
    while(p<RomN.length())
    {
        stringstream pSS, pPlus1SS;
        string pRomN, pPlus1RomN;
        pSS << RomN[p];
        pPlus1SS << RomN[p+1];
        pSS >> pRomN;
        pPlus1SS >> pPlus1RomN;
        if (RomN.length()-p > 1)
        {
            if (isInRomN(pRomN+pPlus1RomN))
            {
                value+=arabicValues[index(pRomN+pPlus1RomN)];
                p+=2;
            }
            else if (isInRomN(pRomN))
            {
                value+=arabicValues[index(pRomN)];
                p++;
            }
        }
        else if (isInRomN(pRomN))
        {
            value+=arabicValues[index(pRomN)];
            p++;
        }
        else
        {
            cout << "Nie rozpoznano znaku w " << RomN;
        }

    }
    if (RomN == Arabic2Roman(value))
    {
        return value;
    }
    else
    {
        return -1;
    }
}

int main(int argc, char* argv[])
{
    string str;
    int num;
    stringstream ss;
    ss << argv[1];
    ss >> str;                                                      // TODO: REMOVE BULLSHIT
    if (atoi(argv[1]) != 0)
    {
        num = atoi(argv[1]);
        cout << Arabic2Roman(num);
    }
    else
    {
        cout << Roman2Arabic(str);
    }
    return 0;
}
