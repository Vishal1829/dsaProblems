#include <bits/stdc++.h>
using namespace std;

pair<int,pair<int,int>> getMaxSumSubarray(vector<int> &v){
    int n=v.size();
    int sum=0,startInd=-1,maxi=INT_MIN,ansStartInd=-1,ansEndInd=-1;
    for(int i=0;i<n;i++){
       if(sum==0)
         startInd=i;
       sum+=v[i];
       if(sum>maxi){
          maxi=sum;
          ansStartInd=startInd,ansEndInd=i;
       }
       if(sum<0)
         sum=0;
    }
    return {maxi,{ansStartInd,ansEndInd}};
}

int main(){
   int n;
   cin>>n;
   vector<int> v;
   for(int i=0;i<n;i++){
      int x;
      cin>>x;
      v.push_back(x);
   }
   auto p = getMaxSumSubarray(v);
   cout<<"Max Sum of Subarray is:- "<<p.first<<endl;
   if(p.second.first!=-1){
      cout<<"Subarray is:-  ";
      for(int i=p.second.first;i<=p.second.second;i++)
         cout<<v[i]<<" ";
   }
}