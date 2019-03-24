#pragma once
#include <iostream>
#include <vector>
#include "IProblem.h"

using namespace std;
class Problem1 : public IProblem
{
    public :
    virtual void DescribeProblem();
    virtual void ExecuteTests();

    private :
    void sort(vector<int>& in);
    bool isValidPartition(int start, int end, int maxBound);
    int orderAroundThePivotValue(vector<int>& in, const int start, const int end);
    void quicksort(vector<int>& in , const int startPos, const int end);
};