#include <bits/stdc++.h>
using namespace std;
using pii = pair<int,int>;

/*
So here in BellmanFord, we are trying to find shortest distance from the source vertex to all other vertices. And so we know that,
between the source node to any one particular node the shotest distance must have atmoost (V-1) edges. So the idea here is we are 
trying to relax all the edges of the Graph (V-1) times. So Time Complexity of BellmanFord is:- O((V-1)*E)=O(VE).

Now After relaxing all the edges (V-1) times. We try to relax one more time so at Vth time if we are still getting a shorter distance
then we are sure that the Graph contains negative edge weight cycle. As we already know that between the source node and the other
particular node the shortest distance must have atmost (V-) edges and we already relax all the edges (V-1) times and now when we are
trying to relax all the edges Vth time then the shorter distance should not be change but if we are getting another shorter distance
it means it's a cycle or more precisely a negative edge weight cycle.

BellmanFord is a dynamic programmic approach. It builds the solution in a bottom-up fashion. Ex:-
V=5 - so we will relax the edges (V-1)times=4. Source vertex=0.
0  |  1  |  2  |  3  |  4
--------------------------
0  |  I  |  I  |  I  |  I  
--------------------------
0  |  2  |  7  |  2  |  4   -> 1st time
--------------------------
0 |  2  |  7  |  -2  |  4   -> 2nd time
--------------------------
0 |  2  |  7  |  -2  |  4   -> 3rd time
--------------------------
0 |  2  |  7  |  -2  |  4   -> 4th time

Now for ex-at 1st tine relaxation, from 0 to 3 the shortest distance comes out to be 2 via some edges
(suppose here the path to reach to 3 is 0-1-2-3). Now in 2nd time relaxation the shortest distance from 0 to 3 comes out 
to be -2 via some edges(suppose here the path to reach to 3 is 0-2-3). So that's how the shorter distance fro each node 
gets updated. And that is how this algorithm works. Also at any point we find any two row's value same then it means we found
the shortest distance to all other vertices from the source node so we can return from here no need to proceed further.
*/

bool bellmanFord(vector<pii> adj[],int V,int src,vector<int> &dist){
    bool cycle=0;
    dist[src]=0;
    bool update;
    for(int i=0;i<V-1;i++){
        update=0;
        for(int u=0;u<V;u++){
            for(auto v: adj[u]){
                // auto [vertex, wt] = v;
                int vertex = v.first;
                int wt = v.second;
                if(dist[u]!=1e8 && dist[u]+wt < dist[vertex]){
                    update=1;
                    dist[vertex] = dist[u]+wt;
                }
            }
        }
        if(update==0)
         return cycle;
    }
    for(int u=0;u<V;u++){
        for(auto v: adj[u]){
            // auto [vertex, wt] = v;
            int vertex = v.first;
            int wt = v.second;
            if(dist[u]!=1e8 && dist[u]+wt < dist[vertex]){
                cycle=1;
                return cycle;
            }
        }
    }
    return cycle;
}

int main()
{
    int V,E;
    cin>>V>>E;
    vector<pii> adj[V];
    for(int i=0;i<E;i++){
        int u,v,wt;
        cin>>u>>v>>wt;
        adj[u].push_back({v,wt});
    }
    vector<int> dist(V,1e8);
    int src=2;
    if(bellmanFord(adj,V,src,dist))
        cout<<"Graph Contains Negative Edge Weight Cycle";
    else{
        cout<<"Minimum distance from src = "<<src<<" to all other vertices using BellmanFord Algorithm are:-\n";
        for(auto &k : dist)
          cout<<k<<" ";
    }
    return 0;
}
/*
0-1-6
0-2-7
1-2-8
1-3-(-4)
1-4-5
2-3-9
2-4-(-3)
3-4-7
3-0-2
4-1-(-2)
*/
// 3 4
// 0 1 5
// 1 0 3
// 1 2 -1
// 2 0 1
// For src=2, ans = 1 6 0