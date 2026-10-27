
#include<iostream>
#include<vector>
#include<climits>
using namespace std;
//Prakhar Srivastava(25/DA/050)

int solve(vector<int>&p,int i,int j,vector<vector<int>>&dp){
    if(i==j) return 0;
    if(dp[i][j]!=-1) return dp[i][j];

    int ans=INT_MAX;
    for(int k=i;k<j;k++){
        int cost=p[i-1]*p[k]*p[j]+solve(p,i,k,dp)+solve(p,k+1,j,dp);
        ans=min(ans,cost);
    }

    return dp[i][j]=ans;
}

int main(){
    int n;
    cin>>n;
    vector<int>p(n);
    for(int i=0;i<n;i++) cin>>p[i];
    vector<vector<int>>dp(n,vector<int>(n,-1));
    cout<<"Minimum number of multiplications: "<<solve(p,1,n-1,dp);
    return 0;
}
