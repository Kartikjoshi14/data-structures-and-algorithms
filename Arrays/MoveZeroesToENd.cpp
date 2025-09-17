#include<bits/stdc++.h>
using namespace std;

void Sortzeroestoend(vector<int> &arr){
    int n = arr.size();
    int count = n-1;
    for(int i=n-1;i>=0;i--){
        if(arr[i] == 0 ){
            swap(arr[i],arr[count]);
            count--;
        }

    }
}
int main(){
    vector<int> arr={1,0,0,1,1,0,1,0};
    Sortzeroestoend(arr);
    for(int i:arr){
        cout<<i<<" ";
    }
    return 0;
}