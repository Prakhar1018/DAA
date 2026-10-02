#include<bits/stdc++.h>
using namespace std;
//Prakhar Srivastava(25/DA/050)
int main(){
    int n,e;
    cin>>n>>e;
    vector<vector<pair<int,int>>> adj(n);
    for(int i=0;i<e;i++){
        int u,v,w;
        cin>>u>>v>>w;
        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
    }
    vector<int> vis(n,0);
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
    pq.push({0,0});
    int mst=0;
    while(!pq.empty()){
        int w=pq.top().first;
        int u=pq.top().second;
        pq.pop();
        if(vis[u])
            continue;
        vis[u]=1;
        mst+=w;
        for(int i=0;i<adj[u].size();i++){
            int v=adj[u][i].first;
            int wt=adj[u][i].second;
            if(!vis[v])
                pq.push({wt,v});
        }
    }

    cout<<"MST weight = "<<mst;
    return 0;
}
