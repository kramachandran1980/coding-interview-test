
#include <iostream>
#include <cstdlib>
#include "IProblem.h"
#include "Problem1.h"

using namespace std;
int main()
{
    Problem1 x;
    x.DescribeProblem();
    x.ExecuteTests();
    x.TearDown();
    string s;
    cin >> s;
}

