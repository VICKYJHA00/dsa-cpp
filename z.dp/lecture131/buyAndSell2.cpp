#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(int index,int buyed,vector<int>& prices,vector<vector<int>>& dp){
        if(index>= prices.size()) return 0;
        // if buyed = 1 then sell
        // if not the buy 
        if(dp[index][buyed] != -1) return dp[index][buyed];
        int profit = 0;
        if(buyed == 0){
            int include = -prices[index]+solve(index+1,1,prices,dp);
            int exclude = solve(index+1,0,prices,dp);
            profit = max(include,exclude);
        }else{
            int include = prices[index]+solve(index+1,0,prices,dp);
            int exclude = solve(index+1,1,prices,dp);
            profit = max(include,exclude);
        }

        return dp[index][buyed] = profit;
    }
    int maxProfit(vector<int>& prices) {
        vector<vector<int>> dp(prices.size()+1,vector<int>(2,-1));
        return solve(0,0,prices,dp);
    }
};

int main() {
    vector<int> prices = {7,1,5,3,6,4};
    Solution s;
    cout<<"The maximum profit is: "<<s.maxProfit(prices);
    cout<<endl;
    return 0;
}
