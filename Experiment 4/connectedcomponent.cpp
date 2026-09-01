#include <iostream>
#include <vector>
using namespace std;
//Prakhar Srivastava(25/DA/050)

void DFS(int node,vector<vector<int>>& adj,vector<bool>& visited){
    visited[node]=true;
    cout<<node<<" ";
    for(int neighbour:adj[node]){
        if(!visited[neighbour]) DFS(neighbour,adj,visited);
    }
}

int connectedcomponents(vector<vector<int>>& adj){
    int n=adj.size();
    vector<bool> visited(n,false);
    int count=0;
    for(int i=0;i<n;i++){
        if(!visited[i]){
            cout<<"(";
            DFS(i,adj,visited);
            cout<<")"<<endl;
            count++;
        }
    }
    return count;
}

int main(){
    vector<vector<int>> adj(6);
    adj[0]={1,2};
    adj[1]={0,2};
    adj[2]={0,1};
    adj[3]={4};
    adj[4]={3};
    adj[5]={};
    cout<<"Number of connected components: "<<connectedcomponents(adj);
    return 0;
}