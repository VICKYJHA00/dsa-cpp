#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(int start,int end,vector<vector<int>>& dp){
        if(start >= end) return 0;
        if(dp[start][end] != -1) return dp[start][end];

        int ans = INT_MAX;
        for(int i = start;i<end;i++){
            ans = min(ans,i + max(solve(start,i-1,dp),solve(i+1,end,dp)));
        }

        return dp[start][end] = ans;
    }
    int getMoneyAmount1(int n) {
        vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
        return solve(1,n,dp);

    }

    int getMoneyAmount(int n) {
        vector<vector<int>> dp(n+2,vector<int>(n+2,0));
        for(int start = n;start >= 1;start--){
            for(int end = start;end<=n;end++){
                if(start == end) continue;
                
                int ans = INT_MAX;
                for(int i = start;i<end;i++){
                    ans = min(ans,i + max(dp[start][i-1],dp[i+1][end]));
                }
                dp[start][end] = ans;
            }
            
        }
        return dp[1][n];
    }
};

int main(){
    Solution s;
    cout<<s.getMoneyAmount1(10)<<endl;
    cout<<s.getMoneyAmount(10)<<endl;
}