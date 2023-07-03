#include <bits/stdc++.h>
using namespace std;

void merge(vector<int> &v, int l, int m, int r){
   int n1=m-l+1,n2=r-m;
   int left[n1],right[n2];
   for(int i=0;i<n1;i++)
     left[i]=v[l+i];
   for(int i=0;i<n2;i++)
     right[i]=v[m+1+i];
   int i=0,j=0,k=l;
   while(i<n1 and j<n2){
      if(left[i]<=right[j]){
          v[k]=left[i++];
      }
      else{
          v[k]=right[j++];
      }
      k++;
   }
   while(i<n1){
      v[k++]=left[i++];
   }
   while(j<n2){
      v[k++]=right[j++];
   }
}

void mergeSort(vector<int> &v, int l, int r){
    if(r > l)  //Atleast two elements
    { 
        int m = l+(r-l)/2;
        mergeSort(v,l,m);
        mergeSort(v,m+1,r);
        merge(v,l,m,r);
    } 
}

int main(){
   vector<int> v={5,7,1,2,8,10,3,9,16,12};
   mergeSort(v,0,v.size()-1);
   for(auto &k : v)
     cout<<k<<" ";
}
/*
 Idea:- So what we do in mergeSort, we first check if there are atleast 2 elements, if there is one element 
 there's no point of swapping . After checking this we find the mid-point, after that we recursively sort 
 elements from low to mid and then we recursively sort elements from mid+1 to r. After sorting these two halves, 
 we merge these halves by using the merge func. Merge func takes l to m as one subArray and m+1 to r as another 
 subArray, m is the dividing point and then merge func merges them into one sorted array.
 MergeSort is an stable algorithm.
*/