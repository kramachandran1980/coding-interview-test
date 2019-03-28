#pragma once
#include <iostream>
//#include <forward_list>
#include "IProblem.h"
using namespace std;

class Problem4 : public IProblem
{
    public :
    virtual void DescribeProblem();
    virtual void ExecuteTests();

    private:
    //forward_list<int>::const_iterator EraseElementFromList(int pos, forward_list<int>& list);
};