#include <bits/stdc++.h> 
using namespace std; 
 
class MaxHeap{ 
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
        for(int ind = v.size()-1; ind != 0 and v[parent(ind)] < v[ind];){ 
            swap(v[ind], v[parent(ind)]); 
            ind = parent(ind); 
        } 
    } 

    void maxHeapify(int ind){ 
        int maxInd = ind; 
        int leftInd = left(ind), rightInd = right(ind); 
        if(leftInd<v.size() and v[leftInd]>v[maxInd]) {
          maxInd = leftInd; 
        }
        if(rightInd<v.size() and v[rightInd]>v[maxInd]) {
          maxInd = rightInd; 
        }
        if(maxInd != ind){ 
            swap(v[ind], v[maxInd]); 
            //now calling heapify for maxInd to fix the subtree with root as maxInd.
            maxHeapify(maxInd); 
        } 
    } 

    int extractMax(){ 
        if(v.empty()) 
          return INT_MIN; 
        if(v.size() == 1){ 
            int maxVal = v.back(); 
            v.pop_back(); 
            return maxVal; 
        } 
        //swap the maximum element which is at index 0 to the last index value and reduce the size of 
        //heap or array and then call the heapify as the maxHeap property may be violated by swapping.
        swap(v[0], v[v.size()-1]); 
        int maxVal = v.back(); 
        v.pop_back(); 
        maxHeapify(0); 
        return maxVal; 
    } 

    void increaseKey(int ind, int value){ 
        if(ind>=v.size() or v[ind] >= value) 
            return; 
        v[ind] = value; 
        while(ind != 0 and v[parent(ind)] < v[ind]){ 
            swap(v[ind], v[parent(ind)]); 
            ind = parent(ind); 
        } 
    } 

    /*
      Logic of delete key is: call increaseKey with value Maximum value here its INT_MAX, so after
      this operation INT_MAX will be at 0th index now just call extractMax() it will delete the 0th
      node as its the max value in maxHeap.
    */
    void deleteKey(int ind){ 
        if(ind >= v.size()) 
          return; 
        increaseKey(ind, INT_MAX); 
        extractMax(); 
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
        //the root having 0th index after that our maxHeap is ready.
        //so maxheapify- ind,ind-1,ind-2,ind-3....0th index.
        for(int ind = startInd; ind >= 0; ind--) {
            maxHeapify(ind);
        }
    }
}; 
 
int main() { 
    MaxHeap obj; 
    // obj.insert(4); 
    // obj.insert(10); 
    // obj.insert(2); 
    // obj.insert(1); 
    // obj.insert(5); 
    // obj.insert(0); 
    // obj.insert(8); 
    // obj.insert(9); 
    // obj.display(); 

    vector<int> array = {1, 3, 5, 4, 6, 13, 10, 9, 8, 15, 17};
    obj.buildHeap(array);

    // cout<<obj.extractMax()<<endl;
    int maxVal=obj.extractMax();
    while(maxVal != INT_MIN){
        cout<<maxVal<<" ";
        maxVal=obj.extractMax();
    }
    // obj.display(); 
    // obj.deleteKey(2); 
    // obj.display(); 
    return 0; 
}
/*
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