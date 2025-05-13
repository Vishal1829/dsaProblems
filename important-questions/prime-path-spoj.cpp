/*
Problem Statement:
Given two 4 digit prime numbers say A and B, find the minimum number of operations to convert A
into B.
In one step you can change 1 digit of the number and the resulting number must also be prime.
Sample testcase:
1033 8179
Ans: 6
       1033
       1733
       3733
       3739
       3779
       8179

https://www.spoj.com/problems/PPATH/

Input:
3
1033 8179
1373 8017
1033 1033

Output:
6
7
0

*/


#include <bits/stdc++.h>
using namespace std;
 
vector<int> adj[100001]; //size 10^5
vector<int> primes;

int dist[100001], visited[100001];

//T.C: O(sqrt(n))
bool isPrime(int n) {
  for(int i=2;i*i<=n;i++) {
    if(n%i==0)
      return false;
  }
  return true;
}

bool isDifferBy1Digit(int a, int b) {
  int cnt=0;
  while(a > 0) {
    if(a % 10 != b % 10)
      cnt++;

    a /= 10;
    b /= 10;
  }

  return cnt==1;
}

void buildGraph() {
  
    for(int i=1000;i<=9999;i++) {
      if(isPrime(i)) {
        primes.push_back(i);
      }
    }

    for(int i=0;i<primes.size();i++) {
      for(int j=i+1;j<primes.size();j++) {
        int a=primes[i];
        int b=primes[j];

        if(isDifferBy1Digit(a, b)) {
          adj[a].push_back(b);
          adj[b].push_back(a);
        }
      }
    }

}

void bfs(int src) {
  queue<int> q;
  q.push(src);
  visited[src]=1;
  dist[src]=0;

  while(!q.empty()) {
    int curr = q.front();
    q.pop();

    for(int child : adj[curr]) {
      if(visited[child]==0) {
        visited[child]=1;
        dist[child]=dist[curr]+1;
        q.push(child);
      }
    }
  }
}


int main() {

  int t, a, b;
  cin>>t;

  buildGraph();

  while(t--) {

      cin>>a>>b;

      //initialize all 4-digit number distance to -1
      for(int i=1000;i<=9999;i++) {
        dist[i]=-1;
        visited[i]=0;
      }

      bfs(a);

      if(dist[b]==-1)
        cout<<"impossible"<<endl;
      else
        cout<<dist[b]<<endl;
  }

  return 0;
}