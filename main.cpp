
#include <iostream>
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
    problems.push_back(new Problem1());
    problems.push_back(new Problem2());
    problems.push_back(new Problem3());
    problems.push_back(new Problem4());
    
    for (int i(0); i < problems.size(); i++) {
        IProblem* p = problems[i];
        p->DescribeProblem();
        p->ExecuteTests();
        p->TearDown();
        delete p;
    }

    problems.clear();

    string s;
    cout << "Press any key" << endl;
    cin >> s;
}

