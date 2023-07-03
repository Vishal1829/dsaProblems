#include <bits/stdc++.h>
using namespace std;

void insertionSort(vector<int> &v){
    int n=v.size();
    for(int i=1;i<n-1;i++){
      int key=v[i];
      int j=i-1;
      while(j>=0 and v[j] > key){
        v[j+1]=v[j];
        j--;
      }
      v[j+1]=key;
    }
}

int main(){
   vector<int> v={5,7,1,2,8,10,3,9,16,12};
   insertionSort(v);
   for(auto &k : v)
     cout<<k<<" ";
}
/*
  0             i              n-1
  -------------------------------
  |  Sorted  | key |  Unsorted  |
  -------------------------------

  i goes  from 1 to n-1
  Logic:- When we are at the "ith" position we try to insert this in the sorted part
  at correct position and increase the sorted part.
  Note:-Only single element in sorted part is always sorted, so that's why start the loop from 1.
  InsertionSort is an stable and in-place algorithm.
*/