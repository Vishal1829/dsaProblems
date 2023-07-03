#include <bits/stdc++.h>
using namespace std;

//Selection Sort by swapping Maximum element
void selectionSort2(vector<int> &v){
    int n=v.size();
    for(int i=n-1;i>0;i--){
       int maxInd = i;
       for(int j=i-1;j>=0;j--){
         if(v[j] > v[maxInd])
           maxInd=j;
       }
       swap(v[maxInd], v[i]);
    }
}

//Selection Sort by swapping Minimum element
void selectionSort1(vector<int> &v){
    int n=v.size();
    for(int i=0;i<n-1;i++){
       int minInd = i;
       for(int j=i+1;j<n;j++){
         if(v[j] < v[minInd])
           minInd=j;
       }
       swap(v[minInd], v[i]);
    }
}

int main(){
  //  vector<int> v={5,7,1,2,8,10,3,9,16,12};
   vector<int> v={18,18,18,12,18,12,18,18};
   selectionSort2(v);
   for(auto &k : v)
     cout<<k<<" ";
}

/*
  0                    n-1
  ------------------------
  |  Sorted  | Unsorted  |
  ------------------------

  Logic:-At every point we are maintaining two Arrays, one array which is already sorted and one
  subArray which is yet to be sorted, and we find out the minimum element in unsorted part.
  Note:-The outer loop will run from 0 n-2 as if n-1 elements sorted the 
  remaining single element will also come at its correct position.
  SelectionSort is an un-stable and in-place algorithm.
*/