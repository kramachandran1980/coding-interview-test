#include <iostream>
#include <vector>
using namespace std;

// To execute C++, please define "int main()"

bool isValidPartition(int start, int end, int maxBound);
int orderAroundThePivotValue(vector<int>& in, const int start, const int end);
void quicksort(vector<int>& in , const int startPos, const int end);

int main() {
  auto words = { "Hello, ", "World!", "\n" };
  for (const string& word : words) {
    cout << word;
  }

  vector<int> xs = { 1, 2 , 3, 4, 5};

  /*
3,5,4,8,10
3 5 4 10 8

  3 10 4 8 5
  3 4 10 8 5
  3 4 5 8 10

  */

  //choose a pivot - lets say the last element 
  // 2 pointers from both sides 
  // first pt runs till it finds a value > pivot
  //second runs till value less than pivot
  //swap the pointers
  //continue till both meet 
  //swap that place with pivot element 
  // work on the partitions left of ptr , rght of ptr
  //each partition - size + start pos

  /*int pivotPos(xs.size()-1); //last element as pivot
  while (pivotPos >= 0)
  {
      
      //cal partitionsize
      
  }*/

  quicksort(xs,0, xs.size()-1);
  //cout << "partition is " << isValidPartition(6, 5, 5) << endl;

  //cout << orderAroundThePivotValue(xs, 0, xs.size()-1);

  for (int i: xs)
  {
      cout << i << " ";
  }

string s;
  cin >> s;
  return 0;
}


//swap that place with pivot element 
  // work on the partitions left of ptr , rght of ptr
  //each partition - size + start pos
void quicksort(vector<int>& in , const int startPos, const int end){   
    
    if (!isValidPartition(startPos,end, in.size()-1))  { 
      return; 
    }

    cout << startPos << end << endl;
    if (end - startPos == 1)
    {
      if (in[end] < in[startPos])
      {
        swap(in[end] , in[startPos]);
      }
    }
    else 
    {
      int pivotPos(orderAroundThePivotValue(in, startPos, end));

      swap(in[pivotPos] , in[end]); //move pivot to start of right partition
      quicksort(in, startPos, pivotPos-1);
      quicksort(in, pivotPos, end);
    }
}

bool isValidPartition(int start, int end, int maxBound)
{
  if (end <= start)  { return false; }
  if (start > maxBound || end > maxBound) { return false; }
  if (end < 0 || start < 0 ) { return false; }
  
  return true;
}

//choose a pivot - lets say the last element 
// 2 pointers from both sides 
  // first pt runs till it finds a value > pivot
  //second runs till value less than pivot
  //swap the values at pointers
  //continue till both meet
  //finally return the value where the partition happened 
int orderAroundThePivotValue(vector<int>& in, const int start, const int end)
{
  int left(start), right(end-1), pivotVal(in[end]);
  while(left < right) {
    while(in[left] < pivotVal && left != right){  
            left++;    
    };
    while(in[right] >= pivotVal && right >= 0 && right != left){
            right--;     
    };

    if (left != right) {
    swap(in[left],in[right]);
    left++; right--;
    }
  };

  int pivotPos(left == right ? right : right+1);
  return pivotPos;
}