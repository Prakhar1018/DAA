#include<iostream>
#include<vector>
#include<queue>
using namespace std;
//Prakhar Srivastava(25/DA/050)
struct Node{
    char ch;
    int freq;
    Node*left;
    Node*right;

    Node(char c,int f){
        ch=c;
        freq=f;
        left=right=NULL;
    }
};

struct Compare{
    bool operator()(Node*a,Node*b){
        return a->freq>b->freq;
    }
};

void printCodes(Node*root,string code){
    if(!root->left&&!root->right){
        cout<<root->ch<<" : "<<code<<endl;
        return;
    }

    printCodes(root->left,code+"0");
    printCodes(root->right,code+"1");
}

int main(){
    int n;
    cin>>n;
    priority_queue<Node*,vector<Node*>,Compare>pq;
    for(int i=0;i<n;i++){
        char ch;
        int freq;
        cin>>ch>>freq;
        pq.push(new Node(ch,freq));
    }

    while(pq.size()>1){
        Node*a=pq.top();pq.pop();
        Node*b=pq.top();pq.pop();

        Node*temp=new Node('\0',a->freq+b->freq);
        temp->left=a;
        temp->right=b;
        pq.push(temp);
    }
    cout<<"Huffman Codes:"<<endl;
    printCodes(pq.top(),"");
    return 0;
}