#include <bits/stdc++.h>
using namespace std;
 
vector<int> adj[10001];
int vis[10001];
 
int maxdist, maxNode;
 
void dfs(int src,int dist=0){
    vis[src]=1;
    if(maxdist<dist){
        maxdist=dist;
        maxNode=src;
    }
    for(auto k: adj[src])
      if(!vis[k])
        dfs(k,dist+1);
}
int main() {
	
    int n;
    cin>>n;
    int a,b;
    for(int i=0;i<n-1;i++){
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    maxdist=-1;
    dfs(a);
    memset(vis,0,sizeof(vis));
    maxdist=-1;
    dfs(maxNode);
    cout<<maxdist;
	return 0;
}
/*
What is Diameter of a Tree?
It is defined as the longest path between any 2 nodes in the tree.
[1,2,null,3,4,7,null,5,6]
          1
         /  
       2    
      / \   
     3   4  
    /   / \ 
    7   5 6

Here the diameter of the tree is of length 4. Its either from (7 to 6) or (7 to 5) so one
diameter is having endpoint 7 and 6 and the other diameter is having endpoint 7 and 5.

Naive Approach:
We would run DFS N times and in each iteration , we would set ith Node as root and find
distance of farthest node.
Running Time: O(N^2)

Better Approach:
We can find diameter in only 2 DFS run

So Take any arbitrary node as root and run DFS from it and find the farthest node,
let this node be x.

Then Run a DFS from node x and find the maximum distance from this node to any other node,
this distance is diameter.
*/
