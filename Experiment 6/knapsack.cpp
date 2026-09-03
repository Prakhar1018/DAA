#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
//Prakhar Srivastava(25/DA/050)
struct Item{
    int weight;
    int value;
};

bool compare(Item a,Item b){
    return (double)a.value/a.weight > (double)b.value/b.weight;
}

double fractionalKnapsack(vector<Item>& items,int capacity){
    sort(items.begin(),items.end(),compare);
    double totalValue=0;
    for(int i=0;i<items.size();i++){
        if(items[i].weight<=capacity){
            capacity-=items[i].weight;
            totalValue+=items[i].value;
        }
        else{
            totalValue+=(double)items[i].value/items[i].weight*capacity;
            break;
        }
    }
    return totalValue;
}

int main(){
    vector<Item> items={{10,60},{20,100},{30,120}};
    int capacity=50;
    cout<<"Answer:"<<fractionalKnapsack(items,capacity);
    return 0;
}