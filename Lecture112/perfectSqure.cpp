#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>
using namespace std;

int solveMem(int n,vector<int>&dp){
    if(n == 0) return 0;
    if(dp[n] != -1) return dp[n];
    int ans = INT_MAX;
    for(int i = 1;i*i<=n;i++){
        ans = min(ans,1 + solveMem(n-i*i,dp));
    }
    

    return dp[n] = ans;
}
int solve(int n ){
    vector<int>dp(n+1,-1);
    return solveMem(n,dp);
}

int solveTab(int n){
    vector<int> dp(n+1,INT_MAX);
    dp[0] = 0;

    for(int i = 1;i<=n;i++){
        for(int j = 1;j*j<=i;j++){
            if(dp[i-j*j] != INT_MAX){
                dp[i] = min(dp[i],1 + dp[i-j*j]);
            }
        }
        
    }
    return dp[n];
}


int main(){
    int n = 5;
    cout<<"The solution from the memorization : ";
    cout<<solve(n);
    cout<<endl;
    cout<<"The solution from the tabulation : ";
    cout<<solveTab(n);

}
