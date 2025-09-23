#include<bits/stdc++.h>
using namespace std;

bool CheckAnagarams(string s1,string s2){
    if(s1.size() != s2.size()) return false;
    vector<int> freq(26,0) ;// assuming lowecase letters only
    for(char c:s1) freq[c -'a']++;
    for(char c:s2) freq[c - 'a']--;
    for(int count:freq){
        if(count != 0) return false;
    }
    return true;
}
int main(){
    string s1 = "listen",s2="silent";
    cout<<CheckAnagarams(s1,s2)<<endl;
    return 0;
}