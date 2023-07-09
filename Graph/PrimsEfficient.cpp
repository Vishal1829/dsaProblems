#include <bits/stdc++.h>
using namespace std;
using pii = pair<int,int>;

int spanningTree(vector<pii> adj[], int src, int V){
    vector<int> key(V, INT_MAX), parent(V), mst(V, 0);
    priority_queue<pii, vector<pii>, greater<pii>> minh;
    key[src]=0;
    parent[src]=-1;
    minh.push({0, src});
    while(!minh.empty()){
        int node = minh.top().second;
        minh.pop();
        mst[node] = 1;
        for(auto& it: adj[node]) {
            // auto [vert, wt] = it;
            int vert = it.first;
            int wt = it.second;
            if(mst[vert]==0 and wt<key[vert]) {
                key[vert] = wt;
                parent[vert] = node;
                minh.push({wt, vert});
            }
        }
    }
    return accumulate(key.begin(), key.end(), 0);
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
    int src=0;
    cout<<spanningTree(adj, src, V);
    return 0;
}
