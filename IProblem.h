#pragma once
#include <iostream>

using namespace std;
class IProblem
{
    public :
    virtual void DescribeProblem()=0;
    virtual void ExecuteTests()=0;
    void TearDown()
    {
        cout << endl;
        cout << "------*-------*-----------*------------*-----------" << endl;
    }

};