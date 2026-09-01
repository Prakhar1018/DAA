#include<iostream>
#include<vector>
using namespace std;
//Prakhar Srivastava(25/DA/050)
void merge(vector<int>&arr,int low,int mid,int high){
    vector<int> temp;
    int i=low;
    int j=mid+1;
    while(i<=mid&&j<=high){
        if(arr[i]<arr[j]) temp.push_back(arr[i++]);
        else temp.push_back(arr[j++]);}
        while(i<=mid) temp.push_back(arr[i++]);
        while(j<=high) temp.push_back(arr[j++]);
        for(int k=low;k<=high;k++){
            arr[k]=temp[k-low];
        }
    }

void mergesort(vector<int>&arr,int low,int high){
    if(low>=high) return;
    int mid=low+(high-low)/2;
    mergesort(arr,low,mid);
    mergesort(arr,mid+1,high);
    merge(arr,low,mid,high);
}
int main(){
    vector<int>a={5,4,2,6,8,1};
    cout<<"Original array:"<<endl;
    for(int c:a) cout<<c<<" ";
    mergesort(a,0,a.size()-1);
    cout<<"\nSorted array:"<<endl;
    for(int c:a) cout<<c<<" ";

}