#include <bits/stdc++.h>
using namespace std;
using pii = pair<int,int>;

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
// 3 4
// 0 1 5
// 1 0 3
// 1 2 -1
// 2 0 1
// For src=2, ans = 1 6 0