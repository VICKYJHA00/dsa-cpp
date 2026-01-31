#include<iostream>
#include<vector>
#include<climits>
using namespace std;

// using recursion only 
 int minCoins(vector<int> coins, int x){
    if(x == 0 ) return 0;
    if(x < 0 ) return INT_MAX;

    int mini = INT_MAX;
    for(int i = 0;i<coins.size();i++){
        int ans = minCoins(coins, x-coins[i]);
        if(ans != INT_MAX) mini = min(mini,1 + ans);
    }
    return mini;
}

// using DP - tabulation
int minCoinsDP(vector<int> &coins, int x){
    vector<int> dp(x+1, INT_MAX);
    dp[0] = 0;
    for(int i = 0;i<=x;i++){
        for(int j = 0;j<coins.size();j++){
            if(i - coins[j] >= 0 && dp[i - coins[j]] != INT_MAX){
                dp[i] = min(dp[i], 1+ dp[i-coins[j]]);
            }
        }
    }
    
    if(dp[x] == INT_MAX) return -1;
    return dp[x];
}

int solve(vector<int> &coins, int x){
    vector<int> dp(x+1, INT_MAX);
    dp[0] = 0;
    for(int i = 0;i<=x;i++){
        for(int coin : coins){
            if(i- coin >= 0 && dp[i - coin] != INT_MAX){
                dp[i] = min(dp[i], 1 + dp[i- coin]);
            }
        }
    }
    return dp[x] == INT_MAX ? -1 : dp[x];
}


 int main(){
    vector<int> coins = {1,3,4};
    int x = 6;
    cout<<minCoinsDP(coins,x)<<endl;
    cout<<solve(coins,x)<<endl;
 }