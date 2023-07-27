#include <bits/stdc++.h> 
using namespace std; 
 
class MaxHeap{ 
    vector<int> v; 
    public: 
    int left(int i){ 
        return (2*i+1); 
    } 
    int right(int i){ 
        return (2*i+2); 
    } 
    int parent(int i){ 
        return (i-1)/2; 
    } 
    void insert(int x){ 
        v.push_back(x); 
        for(int i=v.size()-1;i!=0 and v[parent(i)]<v[i];){ 
            swap(v[i],v[parent(i)]); 
            i=parent(i); 
        } 
    } 
    void maxHeapify(int i){ 
        int lt=left(i),rt=right(i); 
        int largest=i; 
        if(lt<v.size() and v[lt]>v[largest]) 
          largest=lt; 
        if(rt<v.size() and v[rt]>v[largest]) 
          largest=rt; 
        if(largest!=i){ 
            swap(v[i],v[largest]); 
            maxHeapify(largest); 
        } 
    } 
    int extractMax(){ 
        if(v.empty()) 
          return INT_MIN; 
        if(v.size()==1){ 
            int maxVal=v.back(); 
            v.pop_back(); 
            return maxVal; 
        } 
        swap(v[0],v[v.size()-1]); 
        int maxVal=v.back(); 
        v.pop_back(); 
        maxHeapify(0); 
        return maxVal; 
    } 
    void decreaseKey(int i,int x){ 
        if(i>=v.size()) 
            return; 
        v[i]=x; 
        while(i!=0 and v[parent(i)]<v[i]){ 
            swap(v[i],v[parent(i)]); 
            i=parent(i); 
        } 
    } 
    void deleteKey(int i){ 
        if(i>=v.size()) 
          return; 
        decreaseKey(i,INT_MAX); 
        extractMax(); 
    } 
    void display(){ 
        for(int i=0;i<v.size();i++) 
          cout<<v[i]<<" "; 
        cout<<endl; 
    } 
}; 
 
int main() { 
    MaxHeap obj; 
    obj.insert(4); 
    obj.insert(10); 
    obj.insert(2); 
    obj.insert(1); 
    obj.insert(5); 
    obj.insert(0); 
    obj.insert(8); 
    obj.insert(9); 
    obj.display(); 
    // cout<<obj.extractMax()<<endl;
    int maxVal=obj.extractMax();
    while(maxVal!=INT_MIN){
        cout<<maxVal<<" ";
        maxVal=obj.extractMax();
    }
    // obj.display(); 
    // obj.deleteKey(2); 
    // obj.display(); 
    return 0; 
}
