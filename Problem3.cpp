#include "Problem3.h"

///////////////////////////////////////////
// Logic 
////////////////////////////////////////// 


void Problem3::ExecuteTests()
{
    int arr[]= { 1, 2 , 8, 100};
    vector<int> moneyInEachHouse(arr, arr + sizeof(arr) / sizeof(arr[0]));
    
    cout << "input : ";
    for (int i(0); i < moneyInEachHouse.size(); i++){ cout << moneyInEachHouse[i] << " ";}
    cout << endl;

    if (moneyInEachHouse.size() < 2)
    {
      cout << "too small an input" << endl;
      return ;
    }
    
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