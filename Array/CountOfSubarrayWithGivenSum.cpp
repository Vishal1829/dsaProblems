#include <bits/stdc++.h>
using namespace std;

int getSubarrayCnt(vector<int> &v, int k){
    int n=v.size();
    unordered_map<int,int> mp;
    mp[0]=1;
    int presum=0,cnt=0;
    for(int i=0;i<n;i++){
       presum+=v[i];
       int remove = presum - k;
       cnt += mp[remove];
       mp[presum]++;
    }
    return cnt;
}

int main(){
   int n,k;
   cin>>n>>k;
   vector<int> v;
   for(int i=0;i<n;i++){
      int x;
      cin>>x;
      v.push_back(x);
   }
   cout<<getSubarrayCnt(v,k);
}