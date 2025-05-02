#include <bits/stdc++.h> 
using namespace std; 
 
class MinHeap{ 
    private:
        vector<int> v; 
    public: 

    int left(int ind){ 
        return (2*ind+1); 
    } 

    int right(int ind){ 
        return (2*ind+2); 
    } 

    int parent(int ind){ 
        return (ind-1)/2; 
    } 

    void insert(int value){ 
        v.push_back(value); 
        for(int ind = v.size()-1; ind != 0 and v[parent(ind)] > v[ind];){ 
            swap(v[ind], v[parent(ind)]); 
            ind = parent(ind); 
        } 
    } 

    void minHeapify(int ind){ 
        int minInd=ind; 
        int leftInd = left(ind), rightInd = right(ind); 
        if(leftInd<v.size() and v[leftInd]<v[minInd]) 
          minInd = leftInd; 
        if(rightInd<v.size() and v[rightInd]<v[minInd]) 
          minInd = rightInd; 
        if(minInd != ind){ 
            swap(v[ind], v[minInd]); 
            minHeapify(minInd); 
        } 
    } 

    int extractMin(){ 
        if(v.empty()) 
          return INT_MAX; 
        if(v.size()==1){ 
            int minVal = v.back(); 
            v.pop_back(); 
            return minVal; 
        } 
        swap(v[0], v[v.size()-1]); 
        int minVal = v.back(); 
        v.pop_back(); 
        minHeapify(0); 
        return minVal; 
    } 

    void decreaseKey(int ind,int value){ 
        if(ind >= v.size() or v[ind] <= value) 
            return; 
        v[ind]=value; 
        while(ind != 0 and v[parent(ind)] > v[ind]){ 
            swap(v[ind], v[parent(ind)]); 
            ind = parent(ind); 
        } 
    } 

    void deleteKey(int ind){ 
        if(ind >= v.size()) 
          return; 
        decreaseKey(ind, INT_MIN); 
        extractMin(); 
    } 

    void display(){ 
        for(const auto& val : v) {
            cout<<val<<" ";
        }
        cout<<endl; 
    } 

    void buildHeap(vector<int> &array) {
        v = array;
        //we start to build heap from the bottom most rightmost internal node which is the
        //last leaf node parent.
        int startInd = parent(v.size() - 1);
        //So the way this loop works is it will first fix the subtree with root as ind, then
        //it will fix the subtree with root as ind-1 ... and so on and the last subtree will be 
        //the root having 0th index after that our minHeapify is ready.
        //so maxheapify- ind,ind-1,ind-2,ind-3....0th index.
        for(int ind = startInd; ind >= 0; ind--) {
            minHeapify(ind);
        }
    }
}; 
 
int main() { 
    MinHeap obj; 
    // obj.insert(4); 
    // obj.insert(10); 
    // obj.insert(2); 
    // obj.insert(1); 
    // obj.insert(5); 
    // obj.insert(0); 
    // obj.insert(8); 
    // obj.insert(9); 
    // obj.display(); 
    vector<int> array = {40, 20, 30, 35, 25, 80, 32, 100, 70, 60};
    obj.buildHeap(array);

    obj.display(); 
    cout<<obj.extractMin()<<endl; 
    obj.deleteKey(2); 
    obj.display(); 
    return 0; 
}
/*
https://lihaobhsfer.github.io/md-binary-tree-maker/

Complete Tree: in a Complete tree all the levels are completely filled except possibly the last level and it has to be filled from left
to right.
Binary Heap is a Complete binary tree.(stored as an array)
 0 1 2 3 4 5
[1,2,3,4,5,6]
           1  
          / \ 
         2   3
        / \ / 
        4 5 6 
      
left(i)=2*i+1
right(i)=2*i+2
parent(i)=floor((i-1)/2)

By Using this complete binary tree restriction for Heap, we have an advantage we can store it in an array.
Since its a CBT, so height is minimum possible -> advantage.
Also its stored in an array so advantage of cache friendly.

Note: Every Array represents some Complete Binary Tree.

2 Types of heap:
1. Min Heap: Every node has value smaller than all its descendants.
2. Max Heap: Every node has value larger than all its descendants.

Lets consider Min heap for understanding:

1. Working of insert operation: first we increase size then insert at (size-1)th index (always insert at end) and then we compare it with 
its parent if it is greater then we swap it & again we do the same thing, also finding parent is constant as it is (ind-1)/2th index.
Insertion is log(size) or log(n).

2. Heapify: Basically, heapify is an algorithm used to re-arrange the heap if the root node violates the heap property (child subtrees must be heaps!). 
It's a vital part of building a heap, inserting or deleting a top node from the heap.

So the way heapify works is we pass the node index and this index represents a tree or subtree. So heapify will correct or converts this tree 
into a binary heap which follows the heap property.
We start from the given index and so we try to find the minimum b/w left child, right child & root lets say root=40, left=20, right=50
so min(40,20,50) = 20 which is left and here it is violating the minHeap property so here root is greater so we swap it with root
& then we recursively do it for left index and its subtrees.


Ex:
 0  1  2  3  4  5  6  7   8  9
[40,20,30,35,25,80,32,100,70,60]
heapify(0)
             40        
           /    \      
       20         30   
     /    \      /  \  
   35      25  80    32
 /   \    /            
100  70  60            
heapify(1)
             20        
           /    \      
       40         30   
     /    \      /  \  
   35      25  80    32
 /   \    /            
100  70  60            
Now its a valid MinHeap.
             20        
           /    \      
       25         30   
     /    \      /  \  
   35      40  80    32
 /   \    /            
100  70  60            

Heapify Time Complexity: O(logn), Aux Space: O(logn) for recursion, Aux Space: O(1) for iterative

3. Extract Min: So we know that in a MinHeap the index 0th is our min element now we want to get this and also remove it from heap. So 
what we do is swap it with the arrays last element and also reduce the size of heap or array to size-1 so that we do not consider the last
element in our heapify process and we will call the heapify with index 0th reason since we swapped the last element to first we may have 
vialated the heap property so just hepify. T.C: O(logn)

4. Decrease a key: decreases the value of a the key to any lower value. So the idea is update the value at the specified index and then keep
on swapping the value to its parent if arr[parent]>arr[curInd] then swap and update i=parent and keep on doing this until we reach root node 
which is 0th index. T.C: O(logn)

5. Delete a node: deletes the given node. So the idea is call decreaseKey(i, -infinity) now after the decreaseKey operation the root has the
value as -infinity now call the extractMIn method so it will swap the root to last element and remove the last element and thats how we delete
a node in heap. T.C: O(logn)

6. Build Heap: Given a random array, re-arrange its elements to form a MinHeap.
So the idea is we begin with bottom most rightmost internal node then we call minHeapify for this index i & then minHeapify for i-1, i-2...
until we reach 0th index.
Index of bottom most rightmost internal node is: floor((size-1)/2) or floor((n-1)/2)
which is Parnet of last leaf node is the bottom most rightmost internal node. Also floor((i-2)/2) is parent formula.

Ex:
               0 1 2  3 4 5
random array=[10,5,20,2,4,8]
minHeapify(2)
     10    
    /  \   
  5      20
 / \    /  
2   4  8   
minHeapify(1)
     10   
    /  \  
  5      8
 / \    / 
2   4  20 
minHeapify(0)
     10   
    /  \  
  2      8
 / \    / 
5   4  20 


Final MinHeap
     2   
    / \  
  4     8
 / \   / 
5  10 20 

Time Complexity for buildHeap: O(n) [n=size]

  In C++:
  PriorityQueue is by default maxHeap => prority_queue<int> pq;
  minHeap => prority_queue<int, vector<int>, greater<int>> pq;
  Custom comparator for PriorityQueue:
  struct myCmp {
      bool operator() (const auto &a, const auto &b) {
          return a.val<b.val;
      }
  };
  or
  class myCmp {
    public:
      bool operator() (const auto &a, const auto &b) {
          return a.val<b.val;
      }
  };
*/