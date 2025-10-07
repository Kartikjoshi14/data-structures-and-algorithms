#include<bits/stdc++.h>
using namespace std;

int FibRec(int n){
    if(n<2) return n;
    return FibRec(n-1) + FibRec(n-2);
}

int fibrecursion(int n,vector<int> &memo){
    if(n<=1) return n;
    if(memo[n] != -1){
        return memo[n];
    }
    memo[n] = fibrecursion(n-1,memo) + fibrecursion(n-2,memo);
    return memo[n];
}
int FibMemo(int n){
    vector<int> memo(n+1,-1);
    return fibrecursion(n,memo);
}

int FibTabulation(int n){
    vector<int> dp(n+1);
    dp[0] = 0,dp[1] = 1;
    for(int i=2;i<=n;i++){
        dp[i] = dp[i-1] + dp[i-2];
    }
    return dp[n];
}
int main(){
    int n;
    cin>>n;
    cout<<"FIbonacci using simple recsurion: "<<FibRec(n)<<endl;
    cout<<"fib using dp(memoization):"<<FibMemo(n)<<endl;
    cout<<"fib using dp(tabulation):"<<FibTabulation(n)<<endl;
}