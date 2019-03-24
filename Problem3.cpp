#include "Problem3.h"

///////////////////////////////////////////
// Logic 
////////////////////////////////////////// 


void Problem3::ExecuteTests()
{
    vector<int> moneyInEachHouse = { 1, 2 , 8, 100};
    cout << "input : ";
    for (int i: moneyInEachHouse){ cout << i << " ";}
    cout << endl;

    //base case
    int maxMoneyTillNMinusTwoHouse(moneyInEachHouse[0]);
    int maxMoneyTillNMinusOneHouse(max(moneyInEachHouse[0], moneyInEachHouse[1]));

    for (int i(2); i < moneyInEachHouse.size(); i++) {
        int val = max(maxMoneyTillNMinusOneHouse, 
                                    moneyInEachHouse[i] + maxMoneyTillNMinusTwoHouse);
        
        maxMoneyTillNMinusTwoHouse = maxMoneyTillNMinusOneHouse;
        maxMoneyTillNMinusOneHouse = val;
    }

    cout << "output is" << maxMoneyTillNMinusOneHouse << endl; 
}

void Problem3::DescribeProblem()
{
  cout << endl;
  cout << "---------------------------------------------------" << endl;
  cout << "-------------------PROBLEM 3-----------------------" << endl;
}