#pragma once
#include <iostream>
#include <vector>
#include <string.h>
#include <math.h>
#include "IProblem.h"
using namespace std;

class Problem2 : public IProblem
{
    public :
    virtual void DescribeProblem();
    virtual void ExecuteTests();
};