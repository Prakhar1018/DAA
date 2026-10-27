
#include<iostream>
#include<vector>
using namespace std;
//Prakhar Srivastava(25/DA/050)

bool issafe(vector<string>&board,int row,int col,int n){
    for(int i=0;i<row;i++){
        if(board[i][col]=='Q') return false;
    }

    for(int i=row-1,j=col-1;i>=0&&j>=0;i--,j--){
        if(board[i][j]=='Q') return false;
    }

    for(int i=row-1,j=col+1;i>=0&&j<n;i--,j++){
        if(board[i][j]=='Q') return false;
    }

    return true;
}

bool solve(vector<string>&board,int row,int n){
    if(row==n){
        for(int i=0;i<n;i++){
            cout<<board[i]<<endl;
        }
        cout<<endl;
        return true;
    }

    bool found=false;
    for(int i=0;i<n;i++){
        if(issafe(board,row,i,n)){
            board[row][i]='Q';
            if(solve(board,row+1,n)) found=true;
            board[row][i]='.';
        }
    }

    return found;
}

int main(){
    int n;
    cin>>n;
    vector<string>board(n,string(n,'.'));
    if(!solve(board,0,n)){
        cout<<"No solution exists";
    }
    return 0;
}
