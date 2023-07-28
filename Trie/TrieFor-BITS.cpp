#include <bits/stdc++.h>
using namespace std;

class Node {
    public:
      Node * links[2]={NULL};
};
class Trie {
  private: 
    Node * root;
  public:
    Trie() {
      root = new Node();
    }

    void insert(int num) {
      Node * node = root;
      for (int i = 31; i >= 0; i--) {
        int bit = (num >> i) & 1;
        if (!node->links[bit]) {
          node->links[bit]=new Node();
        }
        node = node->links[bit];
      }
    }
 
    int findMax(int num) {
      Node * node = root;
      int maxNum = 0;
      for (int i = 31; i >= 0; i--) {
        int bit = (num >> i) & 1;
        // below one will not give the bit 0 0r 1 but it will give the number after checking that bit
        // int bit = (num & (1 << i));
        if (node->links[!bit]) {
          maxNum = maxNum | (1 << i);
          node = node->links[!bit];
        } else {
          node = node->links[bit];
        }
      }
      return maxNum;
    }
};

int findMaximumXOR(vector<int>& nums) {
    Trie obj;
    for(auto &k : nums)
      obj.insert(k);
    int maxi=0;
    for(auto &k : nums){
        maxi=max(maxi,obj.findMax(k));
    }
    return maxi;
}

int main(){
    return 0;
}