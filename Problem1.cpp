
#include "Problem1.h"

using namespace std;


void Problem1::DescribeProblem()
{
  cout << endl;
  cout << "---------------------------------------------------" << endl;
  cout << "-------------------PROBLEM 1-----------------------" << endl;
}

void Problem1::ExecuteTests() {

  // Already ordered array
  int arr1[] = { 1, 2 , 3, 4, 5};
  vector<int> t1(arr1, arr1 + sizeof(arr1) / sizeof(arr1[0]));
  sort(t1);

  // reverse ordered array
  int arr2[] = { 5, 4 , 3, 2, 1};
  vector<int> t2 (arr2, arr2 + sizeof(arr2) / sizeof(arr2[0]));
  sort(t2);

  // unordered random
  int arr3[] = {3, 2 , 6, 4, 5, 9, 1};
  vector<int> t3 (arr3, arr3 + sizeof(arr3) / sizeof(arr3[0]));
  sort(t3);

  // unordered random with negetive
  int arr4[] = { 3, 2 , -6, 4, 5, 9, 1};
  vector<int> t4 (arr4, arr4 + sizeof(arr4) / sizeof(arr4[0]));
  sort(t4);
}

void Problem1::sort(vector<int>& xs)
{
  cout << "input : ";
  for (int i(0); i < xs.size(); i++){ cout << xs[i] << " ";}
  cout << endl;

  quicksort(xs,0, xs.size()-1);

  cout << "output : ";
  for (int i(0); i < xs.size(); i++){ cout << xs[i] << " ";}
  cout << endl;
}


//Divide and conquer sort , two parts of the array divided by a pivot element. 
// Pivot will be the last element always
// base case : end == start (single didgit array partition)
void Problem1::quicksort(vector<int>& in , const int startPos, const int end){      
    if (end > startPos)
    {
      int pivotPos(orderAroundThePivotValue(in, startPos, end));     
      quicksort(in, startPos, pivotPos-1);
      quicksort(in, pivotPos+1, end);
    }
}

bool Problem1::isValidPartition(int start, int end, int maxBound)
{
  if (end <= start)  { return false; }
  if (start > maxBound || end > maxBound) { return false; }
  if (end < 0 || start < 0 ) { return false; }
  
  return true;
}

//choose a pivot - lets say the last element 
// Have a left and right pointer indicating the end of the partitioned arrays.
// left : indicates where the array segment sepeares the smaller than pivot value, from the greater ones.  
int Problem1::orderAroundThePivotValue(vector<int>& in, const int start, const int end)
{
  int left(start), right(end-1), pivotVal(in[end]);
  
  for(int i(left); i <= end-1; i++) {
    if (in[i] <= pivotVal) { 
      swap(in[i], in[left++]); 
    }  
  }
  swap(in[left], in[end]); // move pivot at intersection, else it will get considered for sort again. 
  return left;
}