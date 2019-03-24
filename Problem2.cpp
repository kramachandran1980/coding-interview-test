#include <iostream>
#include <vector>
#include <string.h>
#include <math.h>
using namespace std;

namespace customConverter
{
    // as of now base 10 only with signed ints
    char * itoa ( int value, char * str, int base=10 )
    { 
        int j(0), addSign(value < 0); 
        if (addSign) { value = abs(value);}      
        while(value > 0)
        {
            int v = value% base;
            str[j++] = char((int)'0' + (v));
            value = value/base;
        }
        if (addSign) { str[j++] = '-';}
        str[j]='\0';

        //reverse string
        for (int l(0), r(j-1); l < r ; l++, r--) {
            swap(str[l],str[r]);
        }       
        return str;
    }

    //decimal only    
    int atoi (const char * str)
    {
        //clean up string to remove spaces
        char* cleanedStr;
        int i(0);
        
        for(int j(0); j < strlen(str); j++) { 
            if (!isspace(str[j])) cleanedStr[i++] = str[j];
        }
        cleanedStr[i]= '\0';

        //loop string and each digdit multiply
        bool negative(cleanedStr[0] == '-');
        int length(strlen(cleanedStr));
        if (negative) length--;

        int outVal(0), power(length-1), base(10);
        for (int iter(negative ? 1: 0); iter < strlen(cleanedStr); iter++, power--)
        {
            int digit(cleanedStr[iter] - '0');
            outVal += digit* pow(base,power);
            if (outVal < 0) { // exceeds limit
                outVal = 0;
                break;
            }
        }

        if (negative && outVal != 0) { outVal = outVal * -1;}
        return outVal;
    }
};
int main() {   
    char buf[33]; // depends on radix

    int val(-2147483647);
    customConverter::itoa(val, buf);
    cout << buf << endl;

    cout << customConverter::atoi("1") << endl;

    cout << customConverter::atoi("2147483647") << endl;

  string s;
  cin >> s;
  return 0;
}
