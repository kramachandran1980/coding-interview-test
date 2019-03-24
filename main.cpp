
#include <iostream>
#include <cstdlib>
#include <vector>
#include "IProblem.h"
#include "Problem1.h"
#include "Problem2.h"
#include "Problem3.h"
#include "Problem4.h"

using namespace std;
int main()
{
    vector<IProblem*> problems;
    problems.emplace_back(new Problem1());
    problems.emplace_back(new Problem2());
    problems.emplace_back(new Problem3());
    problems.emplace_back(new Problem4());
    
    for (auto p: problems) {
        p->DescribeProblem();
        p->ExecuteTests();
        p->TearDown();
    }

    problems.clear();
    string s;
    cout << "Press any key" << endl;
    cin >> s;
}

