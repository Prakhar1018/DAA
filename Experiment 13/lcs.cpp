
#include<iostream>
#include<vector>
#include<string>
using namespace std;
//Prakhar Srivastava(25/DA/050)

int solve(string &a,string &b,int i,int j,vector<vector<int>>&dp){
    if(i==0||j==0) return 0;
    if(dp[i][j]!=-1) return dp[i][j];

    if(a[i-1]==b[j-1]){
        return dp[i][j]=1+solve(a,b,i-1,j-1,dp);
    }

    return dp[i][j]=max(solve(a,b,i-1,j,dp),solve(a,b,i,j-1,dp));
}

int main(){
    string a,b;
    cin>>a>>b;
    int n=a.size();
    int m=b.size();
    vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
    cout<<"Length of LCS: "<<solve(a,b,n,m,dp);
    return 0;
}
