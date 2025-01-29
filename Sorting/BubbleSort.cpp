#include <bits/stdc++.h>
using namespace std;

void bubbleSort(vector<int> &v){
    int n=v.size();
    //we required only n-1 passes to sort n elements
    for(int i=0;i<n-1;i++){
      bool swapped=false;
      for(int j=0;j<n-i-1;j++){
        if(v[j] > v[j+1]){
          swap(v[j],v[j+1]);
          swapped=true;
        }
      }
      if(swapped==false)
        return;
    }
}

int main(){
   vector<int> v={5,7,1,2,8,10,3,9,16,12};
   bubbleSort(v);
   for(auto &k : v)
     cout<<k<<" ";
}

/*
 In BubbleSort we always compare the adjacent elements i.e., arr[i] to arr[i+1] and if arr[i]>arr[i+1]
 then only we will swap. It is an stable and in-place algorithm.

 Also reason it is known as BubbleSort becoz in every iteration the larger element goes to its right place
 as we compare a particular element to its right side and if bigger then swap so it eventually gets to
 its right place so if 'n' elements are there then we need total n-1 iteration to sort the array
 as in each iteration a element is placed in its correct position.
*/