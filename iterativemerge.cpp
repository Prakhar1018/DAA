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
void mergesort(vector<int>& arr){
    int n = arr.size();
    for (int size =1; size <n; size*= 2){
        for (int left = 0; left < n; left += 2*size){
            int mid = min(left+size-1,n-1);
            int right = min(left+2*size-1, n-1);
            if (mid < right)
                merge(arr,left,mid,right);
        }
    }
}
int main(){
    vector<int>a={5,4,2,6,8,1};
    cout<<"Original array:"<<endl;
    for(int c:a) cout<<c<<" ";
    mergesort(a);
    cout<<"\nSorted array:"<<endl;
    for(int c:a) cout<<c<<" ";

}