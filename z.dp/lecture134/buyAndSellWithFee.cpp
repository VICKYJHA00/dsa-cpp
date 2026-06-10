#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(int index,int buy,vector<int>& prices, int fee,vector<vector<int>>& dp){
        if(index == prices.size()) return 0;
        if(dp[index][buy] != -1) return dp[index][buy];

        int profit = 0;
        if(buy){
            int include = -prices[index] + solve(index+1,0,prices,fee,dp);
            int exclude = solve(index+1,1,prices,fee,dp);
            profit = max(include,exclude);
        }else{
            int include = prices[index] - fee + solve(index+1,1,prices,fee,dp);
            int exclude = solve(index+1,0,prices,fee,dp);
            profit = max(include,exclude);
        }

        return dp[index][buy] = profit;
    }
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        vector<vector<int>> dp(n+1,vector<int>(2,-1));
        return solve(0,1,prices,fee,dp);
    }
};

int main() {
    vector<int> prices = {1,3,2,8,4,9};
    int fee = 2;
    Solution s;
   cout<<"THE max Profit of sell and buy stock with fee is : "<< s.maxProfit(prices,fee)<<endl;
    return 0;
}
