#include<bits/stdc++.h>
using namespace std;

int BinarySearchIterative(vector<int> &arr,int target){
    int low = 0,high = arr.size()-1;
    while(low<=high){
        int mid = low + (high - low) / 2;
        if(arr[mid]==target) return mid;
        else if(target < arr[mid]) high = mid-1;
        else low = mid+1;
    }
    return -1;
}
int BinarySearchRecursive(vector<int> &arr,int low,int high,int target){
    if(low>high) return -1;
    int mid = low+(high - low) / 2;
    if(arr[mid] == target) return mid;
    else if(arr[mid]>target){
        BinarySearchRecursive(arr,low,mid-1,target);
    }else{
        BinarySearchRecursive(arr,mid+1,high,target);
    }
}
int main(){
    vector<int> arr={2,4,6,8,10,12,14};
    int target = 6;
    int index1 = BinarySearchIterative(arr,target);
    int index2 = BinarySearchRecursive(arr,0,arr.size()-1,target);
    cout<<index1<<" "<<index2<<endl;
    return 0;
}