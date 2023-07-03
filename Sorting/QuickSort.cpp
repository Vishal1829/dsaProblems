#include <bits/stdc++.h>
using namespace std;

int hoarePartition(vector<int> &v, int l, int h){
   int pivot = v[l];
   int i=l-1, j=h+1;
   while(true){
      do{
          i++;
      }while(v[i] < pivot);
      do{
          j--;
      }while(v[j] > pivot);
      if(i>=j) 
        return j;
      swap(v[i], v[j]);
   }
}

int lomutoPartition(vector<int> &v, int l, int h){
   int pivot = v[h];
   int i=l-1;
   for(int j=l;j<=h-1;j++){
      if(v[j] < pivot){
          i++;
          swap(v[i], v[j]);
      }
   }
   swap(v[i+1], v[h]);
   return (i+1);
}

void quickSort1(vector<int> &v, int l, int h){
    if(l < h)
    {
        int p = lomutoPartition(v,l,h);
        quickSort1(v,l,p-1);
        quickSort1(v,p+1,h);
    }
}

void quickSort2(vector<int> &v, int l, int h){
    if(l < h)
    {
        int p = hoarePartition(v,l,h);
        quickSort2(v,l,p);
        quickSort2(v,p+1,h);
    }
}

int main(){
   vector<int> v={5,7,1,2,8,10,3,9,16,12};
  //  quickSort1(v, 0 ,v.size()-1);
   quickSort2(v, 0 ,v.size()-1);
   for(auto &k : v)
     cout<<k<<" ";
}

/*
 In BubbleSort we always compare the adjacent elements i.e., arr[i] to arr[i+1] and if arr[i]>arr[i+1]
 then only we will swap. It is an stable and in-place algorithm.
*/