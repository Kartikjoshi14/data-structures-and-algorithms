#include<bits/stdc++.h>
using namespace std;

int MajorityElement(vector<int> &arr){
    int candidate = -1,count = 0;
    //step 1: find candididate
    for(int i:arr){
        if(count == 0){
            candidate = i;
            count = 1;
        }else if(i==candidate){
            count++;
        }else{
            count--;
        }
    }

    //step 2:verify candidiate
    count = 0;
    for(int i:arr){
        if(i==candidate) count++;
    }
    if(count > arr.size()/2) return candidate;
    return -1; // nomajority element

}
int main(){
    vector<int> arr={2,2,1,1,1,2,2};
    cout<<MajorityElement(arr)<<endl;
    return 0;
}