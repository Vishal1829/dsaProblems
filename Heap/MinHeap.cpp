#include <bits/stdc++.h> 
using namespace std; 
 
class MinHeap{ 
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
        for(int i=v.size()-1;i!=0 and v[parent(i)]>v[i];){ 
            swap(v[i],v[parent(i)]); 
            i=parent(i); 
        } 
    } 
    void minHeapify(int i){ 
        int lt=left(i),rt=right(i); 
        int smallest=i; 
        if(lt<v.size() and v[lt]<v[smallest]) 
          smallest=lt; 
        if(rt<v.size() and v[rt]<v[smallest]) 
          smallest=rt; 
        if(smallest!=i){ 
            swap(v[i],v[smallest]); 
            minHeapify(smallest); 
        } 
    } 
    int extractMin(){ 
        if(v.empty()) 
          return INT_MAX; 
        if(v.size()==1){ 
            int minVal=v.back(); 
            v.pop_back(); 
            return minVal; 
        } 
        swap(v[0],v[v.size()-1]); 
        int minVal=v.back(); 
        v.pop_back(); 
        minHeapify(0); 
        return minVal; 
    } 
    void decreaseKey(int i,int x){ 
        if(i>=v.size()) 
            return; 
        v[i]=x; 
        while(i!=0 and v[parent(i)]>v[i]){ 
            swap(v[i],v[parent(i)]); 
            i=parent(i); 
        } 
    } 
    void deleteKey(int i){ 
        if(i>=v.size()) 
          return; 
        decreaseKey(i,INT_MIN); 
        extractMin(); 
    } 
    void display(){ 
        for(int i=0;i<v.size();i++) 
          cout<<v[i]<<" "; 
        cout<<endl; 
    } 
}; 
 
int main() { 
    MinHeap obj; 
    obj.insert(4); 
    obj.insert(10); 
    obj.insert(2); 
    obj.insert(1); 
    obj.insert(5); 
    obj.insert(0); 
    obj.insert(8); 
    obj.insert(9); 
    obj.display(); 
    cout<<obj.extractMin()<<endl; 
    obj.display(); 
    obj.deleteKey(2); 
    obj.display(); 
    return 0; 
}
