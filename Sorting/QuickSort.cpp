#include <bits/stdc++.h>
using namespace std;

int hoarePartition(vector<int> &v, int l, int h){
   int randPivotInd = rand()%(h-l + 1) + l;
   swap(v[l], v[randPivotInd]);
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
   int randPivotInd = rand()%(h-l + 1) + l;
   swap(v[h], v[randPivotInd]);
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
   srand(time(NULL));
   vector<int> v={5,7,1,2,8,10,3,9,16,12};
   quickSort1(v, 0 ,v.size()-1);
  //  quickSort2(v, 0 ,v.size()-1);
   for(auto &k : v)
     cout<<k<<" ";
}

/*
    To generate a random number between min and max, use:
    int randNum = rand()%(max-min + 1) + min;
    (Includes max and min)

    rand() % ((highestNumber - lowestNumber) + 1) + lowestNumber
*/