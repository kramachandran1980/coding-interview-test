#include <iostream>
#include <forward_list>
using namespace std;

///////////////////////////////////////////
// Logic 
////////////////////////////////////////// 

forward_list<int>::const_iterator EraseElementFromList(int pos, forward_list<int>& list);

int main() 
{
    forward_list<int> inputList = { 1, 2 , 8, 11, 4, 7, 9, 10};

    auto iter = EraseElementFromList(1, inputList);
    cout << *iter << endl;

    for(auto item: inputList) { cout << item; }
     
    string s;
    cin >> s;
    return 0;
}

forward_list<int>::const_iterator EraseElementFromList(int pos, forward_list<int>& list)
{
    forward_list<int>::iterator slowPtr(list.before_begin()), fastPtr(list.begin());
    
    int count(pos);
    while(count > 0) {
        fastPtr++; count--;
    };

    while(fastPtr != list.end()) {
        fastPtr++;
        slowPtr++;
    };

    list.erase_after(slowPtr);
    return list.begin();
}

