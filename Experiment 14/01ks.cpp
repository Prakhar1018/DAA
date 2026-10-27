
#include<iostream>
#include<vector>
using namespace std;
//Prakhar Srivastava(25/DA/050)

int solve(vector<int>&wt,vector<int>&val,int i,int w,vector<vector<int>>&dp){
    if(i==0||w==0) return 0;
    if(dp[i][w]!=-1) return dp[i][w];

    if(wt[i-1]<=w){
        return dp[i][w]=max(val[i-1]+solve(wt,val,i-1,w-wt[i-1],dp),solve(wt,val,i-1,w,dp));
    }

    return dp[i][w]=solve(wt,val,i-1,w,dp);
}

int main(){
    int n,w;
    cin>>n>>w;

    vector<int>wt(n),val(n);
    for(int i=0;i<n;i++) cin>>wt[i];
    for(int i=0;i<n;i++) cin>>val[i];
    vector<vector<int>>dp(n+1,vector<int>(w+1,-1));
    cout<<"Maximum profit: "<<solve(wt,val,n,w,dp);
    return 0;
}
