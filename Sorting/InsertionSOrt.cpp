#include<bits/stdc++.h>
using namespace std;

void InsertionSort(vector<int> &arr){
    int n=arr.size();
    for(int i=1;i<n;i++){
        int current_ele = arr[i];
        int j = i-1;
        while(j>=0 && arr[j]>current_ele){
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = current_ele;
    }
}
int main(){
    vector<int> arr={23,54,72,64,34,92};
    InsertionSort(arr);
    for(int i:arr){
        cout<<i<<" ";
    }
    return 0;
}