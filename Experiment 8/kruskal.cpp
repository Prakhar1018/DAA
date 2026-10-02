#include<bits/stdc++.h>
using namespace std;
//Prakhar Srivastava(25/DA/050)
struct Edge{
    int u,v,w;
};

bool compare(Edge a,Edge b){
    return a.w<b.w;
}

int parent[100];

int find(int x){
    if(parent[x]==x)
        return x;
    return find(parent[x]);
}

void unite(int a,int b){
    a=find(a);
    b=find(b);
    parent[b]=a;
}

int main(){
    int n,e;
    cin>>n>>e;
    Edge edges[100];
    for(int i=0;i<e;i++)
        cin>>edges[i].u>>edges[i].v>>edges[i].w;
    for(int i=0;i<n;i++)
        parent[i]=i;
    sort(edges,edges+e,compare);
    int cost=0,count=0;
    cout<<"MST edges:\n";

    for(int i=0;i<e;i++){
        int u=edges[i].u;
        int v=edges[i].v;
        int w=edges[i].w;
        if(find(u)!=find(v)){
            cout<<u<<" - "<<v<<" = "<<w<<endl;
            cost+=w;
            unite(u,v);
            count++;
            if(count==n-1)
                break;
        }
    }

    cout<<"MST weight = "<<cost;

    return 0;
}
