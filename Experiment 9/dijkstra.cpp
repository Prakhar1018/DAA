#include<iostream>
#include<climits>
using namespace std;
//Prakhar Srivastava(25/DA/050)
#define V 5
#define INF INT_MAX

int findMinVertex(int dist[],bool visited[]){
    int minDist=INF;
    int minVertex=-1;
    for(int i=0;i<V;i++){
        if(!visited[i]&&dist[i]<minDist){
            minDist=dist[i];
            minVertex=i;
        }
    }
    return minVertex;
}

void dijkstra(int graph[V][V],int source){
    int dist[V];
    bool visited[V];
    for(int i=0;i<V;i++){
        dist[i]=INF;
        visited[i]=false;
    }
    dist[source]=0;
    for(int count=0;count<V-1;count++){
        int u=findMinVertex(dist,visited);
        visited[u]=true;
        for(int v=0;v<V;v++){
            if(!visited[v]&&graph[u][v]!=0&&dist[u]!=INF&&dist[u]+graph[u][v]<dist[v])
            {
                dist[v]=dist[u]+graph[u][v];
            }
        }
    }

    cout<<"Vertex\tShortest Distance"<<endl;

    for(int i=0;i<V;i++){
        cout<<i<<"\t";
        if(dist[i]==INF)
            cout<<"INF";
        else
            cout<<dist[i];
        cout<<endl;
    }
}

int main(){
    int graph[V][V]={
        {0,10,3,0,0},
        {10,0,1,2,0},
        {3,1,0,8,2},
        {0,2,8,0,7},
        {0,0,2,7,0}
    };
    int source=0;
    dijkstra(graph,source);

    return 0;
}