#include<bits/stdc++.h>
using namespace std;

vector<pair<int,int>> TwoSum(vector<int> &arr,int target){
    unordered_map<int,int> mp;
    vector<pair<int,int>> result;
    for(int i=0;i<arr.size();i++){
        int complement = target - arr[i];
        if(mp.find(complement) != mp.end()){
            result.push_back({mp[complement],i});
        }
        mp[arr[i]] = i;
    }
    return result;
}
int main(){
    vector<int> arr={2,7,11,15};
    int target = 9;
    vector<pair<int,int>> res = TwoSum(arr,target);
    for(auto i:res){
        cout<<i.first<<" "<<i.second<<endl;
    }
    return 0;
}