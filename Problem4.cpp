#include <iostream>
#include <forward_list>
using namespace std;

///////////////////////////////////////////
// Logic 
////////////////////////////////////////// 

forward_list<int>::const_iterator EraseElementFromList(int pos, forward_list<int>& list);

struct CStyleList
{
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
    
    Node* first;
    Node* last;

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

    void erase_after(Node* ptr) {
        if (ptr != nullptr && ptr->next != nullptr) {
            auto temp = ptr->next->next;
            delete ptr->next;
            ptr->next = temp;
            if (temp == nullptr) last = ptr;
        }
    }

    bool moveFastPtrByCountSteps(int count, Node* fastPtr)
    {
        bool successful(true);
        if (count <= 0) {
            cout << "out of bounds";
            successful = false;
        }
        else {
            cout << "here " << count << fastPtr->val << endl;
            //move fastPtr by count steps.
            while(count > 0 && fastPtr != nullptr) {
                fastPtr = fastPtr->next; 
                count--;
            };

            cout << "here " << count << fastPtr->val << endl;

            if (count != 0) {
                cout << "out of bounds";
                successful = false;
            }
        }
        return successful;
    }

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
            //cout << "here " << count << (*fastPtr)->val << endl;
            //move fastPtr by count steps.
            while(count > 0 && (*fastPtr) != nullptr) {
                (*fastPtr) = (*fastPtr)->next; 
                count--;
            };

            //cout << "here " << count << (*fastPtr)->val << endl;

            if (count != 0) {
                cout << "out of bounds for count of " << pos << endl;
                successful = false;
            }
        }
        return successful;
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

    auto iter(linkedList.first);
    while(iter != nullptr)
    {
        cout << iter->val;
        iter = iter->next;
    }

    auto fwdListIter = EraseElementFromList(1, inputList);
    cout << *fwdListIter << endl;

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

