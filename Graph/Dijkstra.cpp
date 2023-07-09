#include <bits/stdc++.h>
using namespace std;
using pii = pair<int,int>;
vector<int> dijkstra(vector<pii> adj[], int src, int V){
    vector<int> dist(V, INT_MAX);
    vector<bool> processed(V, false);
    dist[src]=0;
    priority_queue<pii,vector<pii>,greater<pii>> pq;
    pq.push({0,src});
    while(!pq.empty()){
        int u=pq.top().second;
        pq.pop();
        processed[u]=true;
        for(auto &v : adj[u]){
            // auto [vert, wt] = v;
            int vert = v.first;
            int wt = v.second;
            if(processed[vert]==0 and (dist[u]+wt < dist[vert])){
                dist[vert]=dist[u]+wt;
                pq.push({dist[vert], vert});
            }
        }
    }
    return dist;
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
        adj[v].push_back({u,wt});
    }
    int src=2;
    vector<int> ans=dijkstra(adj, src, V);
    for(auto &k : ans){
        cout<<k<<" ";
    }
    cout<<endl;
    return 0;
}
