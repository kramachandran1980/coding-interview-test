#include <iostream>
#include <forward_list>
using namespace std;

///////////////////////////////////////////
// Logic 
////////////////////////////////////////// 

forward_list<int>::const_iterator EraseElementFromList(int pos, forward_list<int>& list);

class CStyleList
{    
public :
    struct Node
    {
        Node(int v):val(v), next(nullptr) {}
        Node* next;
        int val;
    };

    CStyleList(): first(nullptr), last(nullptr) {}
    ~CStyleList() {
        Node* iter(first);
        while(iter != nullptr)
        {
            auto temp = iter;
            iter = iter->next;
            delete temp;
        }
    }
    
    void initialize(initializer_list<int>&& initialVals)
    {
        for (int i: initialVals) {
            if (first == nullptr && last == nullptr) {
                first = new Node(i);
                last = first;
            }
            else{
                last->next = new Node(i);
                last = last->next;
            }            
        }
    }

    Node* EraseElementFromList(int pos) {
        Node* slowPtr(nullptr); //before begin
        Node* fastPtr(first); //begin
        
        if (moveFastPtrByCountSteps(pos, &fastPtr))
        {
            while(fastPtr != nullptr /*last*/) {
                fastPtr = fastPtr->next;               
                slowPtr = (slowPtr == nullptr) ? first : slowPtr->next;
            };

            // if before_begin is null , we need to delete first
            if (slowPtr == nullptr) { 
                auto temp = first->next;
                delete first;
                first = temp;
            }
            else {
                auto temp = slowPtr->next;
                slowPtr->next = slowPtr->next->next;
                delete temp;
            }
        }
        return first;
    }

    Node* getFirst() const{
        return first;
    }

private :

    Node* first;
    Node* last;

    bool moveFastPtrByCountSteps(int pos, Node** fastPtr)
    {
        bool successful(true);
        int count(pos);
        if (count <= 0) {
            cout << "out of bounds for count of " << pos << endl;
            successful = false;
        }
        else if ((*fastPtr) == nullptr) {
            successful = false;
        }        
        else {
            //move fastPtr by count steps.
            while(count > 0 && (*fastPtr) != nullptr) {
                (*fastPtr) = (*fastPtr)->next; 
                count--;
            };

            if (count != 0) {
                cout << "out of bounds for count of " << pos << endl;
                successful = false;
            }
        }
        return successful;
    }
};

int main() 
{
    forward_list<int> inputList = { 1, 2 , 8, 11, 4, 7, 9, 10};

    CStyleList linkedList;
    linkedList.initialize({ 1, 2 , 8, 11, 4, 7, 9, 10});

    linkedList.EraseElementFromList(4);
    linkedList.EraseElementFromList(3);
    linkedList.EraseElementFromList(7);
    linkedList.EraseElementFromList(6);
    linkedList.EraseElementFromList(0);

    auto iter(linkedList.getFirst());
    while(iter != nullptr)
    {
        cout << iter->val;
        iter = iter->next;
    }

    EraseElementFromList(4, inputList);
    EraseElementFromList(3, inputList);
    EraseElementFromList(7, inputList);
    EraseElementFromList(6, inputList);
    EraseElementFromList(0, inputList);
    
    for(auto item: inputList) { cout << item; }
     
    string s;
    cin >> s;
    return 0;
}

forward_list<int>::const_iterator EraseElementFromList(int pos, forward_list<int>& list)
{
    if (pos <= 0) {
        cout << "out of bounds for count of " << pos << endl;
        return list.begin();
    }
    forward_list<int>::iterator slowPtr(list.before_begin()), fastPtr(list.begin());
    
    int count(pos);
    while(count > 0 && fastPtr != list.end()) {
        fastPtr++; count--;
    };

    if (count != 0) {
        cout << "out of bounds for count of " << pos << endl;
        return list.begin();
    }

    while(fastPtr != list.end()) {
        fastPtr++;
        slowPtr++;
    };

    list.erase_after(slowPtr);
    return list.begin();
}

