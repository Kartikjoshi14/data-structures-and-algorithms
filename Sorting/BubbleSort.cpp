#include<bits/stdc++.h>
using namespace std;

void BubbleSort(vector<int> &arr){
    int n=arr.size();
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-i-1;j++){
            if(arr[j] > arr[j+1]){
                swap(arr[j],arr[j+1]);
            }
        }
    }
}
int main(){
    vector<int> arr={23,54,72,64,34,92};
    BubbleSort(arr);
    for(int i:arr){
        cout<<i<<" ";
    }
    return 0;
}