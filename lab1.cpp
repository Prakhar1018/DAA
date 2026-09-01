#include<bits/stdc++.h>
using namespace std;
int multiple(){
    int add=0;
    for(int i=1;i<1000;i++){
        if(i%3==0||i%5==0) add+=i;
    }
    return add;
}
void quadratic(int a,int b,int c){
    int det=sqrt(b*b-4*a*c);
    if(det<0) cout<<"no roots";
    else if(det==0){
        cout<<-b/2*a;
        cout<<-b/2*a;}
    else{
        cout<<(-b+det)/2*a;
        cout<<(-b-det)/2*a;
    }
    }

int largest(int a,int b,int c){
    int large;
    if(a>b&&a>c) large=a;
    else if(b>a&&b>c) large=b;
    else if(c>a&&c>b) large=c;
    return large;
}
bool evenodd(int a){
    if(a%2==0) return true;
    else return false;
}
void divide(int a,int b){
    int rem=a>b?a%b:b%a;
    int quot=a>b?a/b:b/a;
    cout<<"remainder"<<rem;
    cout<<"quot"<<quot;
}
void hundo(){
    for(int i=100;i<=200;i+=2){
        cout<<i << " ";
    }
}
void bubblesort(vector<int>&arr){
    for(int i=0;i<arr.size()-1;i++){
        int flag=1;
        for(int j=0;j<arr.size()-i-1;j++){
            if(arr[j]>arr[j+1]){
                swap(arr[j],arr[j+1]);
                flag=0;
            }
        }
        if(flag==1) break;
    }
}
int recursum(int n){
    if(n==0) return 0;
    return n+recursum(n-1);
    
}
int main(){
// int ans=largest(2,3,4);
int ans=recursum(5);
cout<<ans;
// vector<int> arr={4,3,6,7,8};
// bubblesort(arr);
// for(int i :arr){
//     cout<<i<<" ";
// }



}
