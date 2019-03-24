#pragma once
#include <iostream>
#include <vector>
#include <string.h>
#include "IProblem.h"
using namespace std;

class Problem3 : public IProblem
{
    public :
    virtual void DescribeProblem();
    virtual void ExecuteTests();
};