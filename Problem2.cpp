#include "Problem2.h"

namespace customConverter
{
    //Assumption : implementation only for base 10, signed and unsigned integers
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
    // string is cleaned to remove spaces , and negetive sign 
    // sign is added back later  
    // For overflow case, retval is 0  
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

void Problem2::ExecuteTests() {   
    char buf[33]; // depends on radix

    cout << "normal number test with 123" << endl;
    int v1(123);
    customConverter::itoa(v1, buf);
    cout << "itoa gave: " << buf << endl;
    customConverter::atoi(buf);
    cout << "atoi gave: " << buf << endl;

    cout << "largenumber with 2147483647" << endl;
    v1 = (2147483647);
    customConverter::itoa(v1, buf);
    cout << "itoa gave: " << buf << endl;
    customConverter::atoi(buf);
    cout << "atoi gave: " << buf << endl;

    cout << "overflow test with 2147483800" << endl;
    customConverter::atoi(buf);
    cout << "atoi gave: " << buf << endl;

    cout << "negative test with -123" << endl;
    v1=(-123);
    customConverter::itoa(v1, buf);
    cout << "itoa gave: " << buf << endl;
    customConverter::atoi(buf);
    cout << "atoi gave: " << buf << endl;

    cout << "0 test with 0" << endl;
    v1=(0);
    customConverter::itoa(v1, buf);
    cout << "itoa gave: " << buf << endl;
    customConverter::atoi(buf);
    cout << "atoi gave: " << buf << endl;
}

void Problem2::DescribeProblem()
{
  cout << endl;
  cout << "---------------------------------------------------" << endl;
  cout << "-------------------PROBLEM 2-----------------------" << endl;
}
