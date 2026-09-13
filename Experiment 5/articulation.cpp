#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
//Prakhar Srivastava(25/DA/050)
void dfs(int u,int parent,vector<vector<int>>&adj,
        vector<int>&visited,vector<int>&tin,
        vector<int>&low,vector<int>&art,int&timer){

    visited[u]=1;
    tin[u]=low[u]=timer++;
    int children=0;
    for(int v:adj[u]){
        if(v==parent)
            continue;
        if(visited[v]){
            low[u]=min(low[u],tin[v]);
        }
        else{
            dfs(v,u,adj,visited,tin,low,art,timer);
            low[u]=min(low[u],low[v]);
            if(parent!=-1&&low[v]>=tin[u])
                art[u]=1;
            children++;
        }
    }
    if(parent==-1&&children>1)
        art[u]=1;
}

void findArticulationPoints(int n,vector<vector<int>>&adj){
    vector<int>visited(n,0);
    vector<int>tin(n,-1);
    vector<int>low(n,-1);
    vector<int>art(n,0);
    int timer=0;
    for(int i=0;i<n;i++){
        if(!visited[i])
            dfs(i,-1,adj,visited,tin,low,art,timer);
    }
    cout<<"Articulation Points are: ";

    for(int i=0;i<n;i++){
        if(art[i])
            cout<<i<<" ";
    }

    cout<<endl;
}

int main(){

    int n,m;
    cout<<"Enter number of vertices: ";
    cin>>n;
    cout<<"Enter number of edges: ";
    cin>>m;
    vector<vector<int>>adj(n);
    cout<<"Enter the edges:"<<endl;
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    findArticulationPoints(n,adj);
    return 0;
}