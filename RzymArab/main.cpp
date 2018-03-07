#include <iostream>
#include <string>
using namespace std;

static int arabicValues[] ={1,4,5,9,10,40,50,90,100,400,500,900,1000};
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
    for (i=0;i <= sizeof(romanNumbers)/sizeof(string);i++)
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
    for (i=0;i <= sizeof(romanNumbers)/sizeof(string);i++)
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
        if (RomN.length()-p > 1)
        {
            if (isInRomN(RomN[p]+RomN[p+1]))
            {

            }
            else if ()
            {

            }
        }
        else if (isInRomN(RomN[p]))
        {
            value+=arabicValues[index(RomN[p])];
            p++;
        }
    }
}


int main()
{
    cout << Arabic2Roman(0);
    return 0;
}
