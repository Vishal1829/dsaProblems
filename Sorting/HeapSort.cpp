#include <bits/stdc++.h>
using namespace std;

void maxHeapify(vector<int> &v, int i, int n){
    int largest=i, left=2*i+1,right=2*i+2;
    if(left<n and v[left]>v[largest])
      largest=left;
    if(right<n and v[right]>v[largest])
      largest=right;
    if(largest!=i){
       swap(v[i], v[largest]);
       maxHeapify(v, largest, n);
    }
}

void minHeapify(vector<int> &v, int i, int n){
    int smallest=i, left=2*i+1,right=2*i+2;
    if(left<n and v[left]<v[smallest])
      smallest=left;
    if(right<n and v[right]<v[smallest])
      smallest=right;
    if(smallest!=i){
       swap(v[i], v[smallest]);
       minHeapify(v, smallest, n);
    }
}


// void buildHeap(vector<int> &v, int n){
//     for(int i=(n-2)/2;i>=0;i--){
//         minHeapify(v, i, n);
//     }
// }

void buildHeap(vector<int> &v, int n){
    for(int i=(n-2)/2;i>=0;i--){
        maxHeapify(v, i, n);
    }
}

void heapSort(vector<int> &v){
    int n=v.size();
    buildHeap(v, n);
    for(int i=n-1;i>=1;i--){
        swap(v[0], v[i]);
        maxHeapify(v, 0, i);
        // minHeapify(v, 0, i);
    }
}

int main(){
   vector<int> v={5,7,1,2,8,10,3,9,16,12};
  //  vector<int> v={18,18,18,12,18,12,18,18};
   heapSort(v);
   for(auto &k : v)
     cout<<k<<" ";
}

/*
  Logic:- The idea of HeapSort is same as SelectionSort, it's just that selectionSort do linear
  search to find out the max element and HeapSort uses max-heap data structure to find the max element.
  So what we do is:- we know that every array is a complete binary tree and so we convert this array 
  into a max-heap by calling buildHeap process and to form a Max-Heap from a random array is O(n) time. 
  After building the max-Heap we swap the last element of array with the root of the Max-Heap so the 
  maximum element goes to the end like we do in selectionSort. After that we call the maxHeapify process 
  as swapping disturbs the root of the max-heap  so we fix it by calling the heapify process. And we keep 
  on repeating this process.
  Note:-To sort an array in Increasing order we use Max-Heap. And to sort an array in decreasing order 
  we use a Min-Heap.
  Steps:-
  1.Call buildHeap process, it begins from the last internal node (parent of last index which n-2/2 as 
  parent of any index i is (n-1)/2 so last index is n-1 therefor ((n-1)-1)/2) goes till root of the tree 
  which is 0 index and keeps calling Heapify for every node it visits. Time Complexity of buildHeap is O(n).
  2.Repeatedly swap root with last node, reduce heap size by one, and heapify.
  HeapSort is not stable and in-place algorithm.
*/