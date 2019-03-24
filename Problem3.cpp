#include <iostream>
#include <vector>
using namespace std;

///////////////////////////////////////////
// Logic 
////////////////////////////////////////// 


int main() 
{
    vector<int> moneyInEachHouse = { 1, 2 , 8, 5, 5, 6, 8, 10};

    //base case
    int maxMoneyTillNMinusTwoHouse(moneyInEachHouse[0]);
    int maxMoneyTillNMinusOneHouse(max(moneyInEachHouse[0], moneyInEachHouse[1]));

    for (int i(2); i < moneyInEachHouse.size(); i++) {
        int val = max(maxMoneyTillNMinusOneHouse, 
                                    moneyInEachHouse[i] + maxMoneyTillNMinusTwoHouse);
        
        maxMoneyTillNMinusTwoHouse = maxMoneyTillNMinusOneHouse;
        maxMoneyTillNMinusOneHouse = val;
    }

    cout << maxMoneyTillNMinusOneHouse; 
  
  string s;
  cin >> s;
  return 0;
}
