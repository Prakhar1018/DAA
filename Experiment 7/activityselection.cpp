#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
//Prakhar Srivastava(25/DA/050)
struct Activity{
    int start;
    int finish;
};
bool compare(Activity a,Activity b){
    return a.finish<b.finish;
}
void activitySelection(vector<Activity>&activities){
    sort(activities.begin(),activities.end(),compare);
    cout<<"Selected activities: ";
    int lastFinish=-1;
    for(int i=0;i<activities.size();i++){
        if(activities[i].start>=lastFinish){
            cout<<"("<<activities[i].start<<","<<activities[i].finish<<") ";
            lastFinish=activities[i].finish;
        }
    }
    cout<<endl;
}

int main(){
    int n;
    cout<<"Enter number of activities: ";
    cin>>n;
    vector<Activity>activities(n);
    cout<<"Enter start and finish time of each activity:"<<endl;
    for(int i=0;i<n;i++){
        cin>>activities[i].start>>activities[i].finish;
    }
    activitySelection(activities);
    return 0;
}