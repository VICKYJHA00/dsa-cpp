#include<iostream>
#include<vector>
using namespace std;


// ------------------------------------------------
// https://leetcode.com/problems/unique-binary-search-trees/

//--------------------------------------------------    
//recursive
class Solution {
public:
    int numTrees(int n) {
        if( n <= 1) return 1;
        int ans = 0;
        for(int i = 1;i<=n;i++){
            ans += numTrees(i-1) * numTrees(n-i);
        }
        return ans;
    }
};

// memoization
class Memoization {
public:
    int solve(int n, vector<int>& dp){
        if(n<=1) return 1;
        if(dp[n] != -1) return dp[n];
        int ans = 0;
        for(int i = 1;i<=n;i++){
            ans += solve(i-1,dp) * solve(n-i,dp);
        }
        return dp[n] = ans;
    }
    int numTrees(int n) {
        vector<int> dp(n+1,-1);
        return solve(n,dp);
    }
};


// tabulation
class tabulation {
public:
    int numTrees(int n) {
        if(n<=1) return 1;
        vector<int> dp(n+1,0);
        dp[0] = 1;
        dp[1] = 1;
        for(int node = 2;node<=n;node++){
            for(int j = 1;j<=node;j++){
                dp[node] += dp[j-1]*dp[node-j];
            }
        }
        return dp[n];
    }
};

// catalan number
class catalanNumber {
public:
    int numTrees(int n) {
        long long catalan = 1;

        for(int i = 1; i <= n; i++) {
            catalan = catalan * 2 * (2 * i - 1) / (i + 1);
        }

        return (int)catalan;
    }
};

int main(){
    int n = 3;
    cout<<catalanNumber().numTrees(n)<<endl;
    cout<<tabulation().numTrees(n)<<endl;
    cout<<Memoization().numTrees(n)<<endl;
    return 0;
}