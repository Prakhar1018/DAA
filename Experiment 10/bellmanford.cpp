
#include<iostream>
#include<vector>
#include<climits>
using namespace std;
//Prakhar Srivastava(25/DA/050)

int main(){
    int n,m;
    cin>>n>>m;

    vector<vector<int>> edges(m,vector<int>(3));

    for(int i=0;i<m;i++){
        cin>>edges[i][0]>>edges[i][1]>>edges[i][2];
    }

    int src;
    cin>>src;

    vector<int> dist(n,INT_MAX);
    dist[src]=0;

    for(int i=0;i<n-1;i++){
        for(int j=0;j<m;j++){
            int u=edges[j][0];
            int v=edges[j][1];
            int w=edges[j][2];

            if(dist[u]!=INT_MAX&&dist[u]+w<dist[v]){
                dist[v]=dist[u]+w;
            }
        }
    }

    for(int i=0;i<m;i++){
        int u=edges[i][0];
        int v=edges[i][1];
        int w=edges[i][2];

        if(dist[u]!=INT_MAX&&dist[u]+w<dist[v]){
            cout<<"Negative weight cycle detected";
            return 0;
        }
    }

    cout<<"Shortest distances:"<<endl;
    for(int i=0;i<n;i++){
        if(dist[i]==INT_MAX) cout<<i<<" : INF"<<endl;
        else cout<<i<<" : "<<dist[i]<<endl;
    }

    return 0;
}
