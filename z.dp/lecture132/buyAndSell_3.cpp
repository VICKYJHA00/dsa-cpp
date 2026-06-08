#include <bits/stdc++.h>
using namespace std;

class Memoization {
public:
    int solve(vector<int>& prices, int index,int buy, vector<vector<vector<int>>>& dp, int limit){
        if(index == prices.size() || limit == 0) return 0;
        if(dp[index][buy][limit] != -1) return dp[index][buy][limit];
         
        int profit = 0;
        if(buy){ // purchase
            int include = -prices[index] + solve(prices,index+1,0,dp,limit);
            int exclude =  solve(prices,index+1,1,dp,limit);
            profit = max(include,exclude);
        }else{ // sell 
            int include = prices[index] + solve(prices,index+1,1,dp,limit-1);
            int exclude =  solve(prices,index+1,0,dp,limit);
            profit = max(include,exclude);
        }

        return dp[index][buy][limit] = profit;
    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>> dp(n,vector<vector<int>>(2,vector<int>(3,-1)));
        return solve(prices,0,1,dp,2);
    }
};

class Tabulation {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>> dp(n+1,vector<vector<int>>(2,vector<int>(3,0)));
        for(int index = n-1; index >= 0;index-- ){
            for(int buy = 0;buy <= 1 ;buy++){
                for(int limit = 1; limit <= 2; limit++){
                    int profit = 0;
                    if(buy){ // purchase
                        int include = -prices[index] + dp[index+1][0][limit];
                        int exclude =  dp[index+1][1][limit];
                        profit = max(include,exclude);
                    }else{ // sell
                        int include = prices[index] + dp[index+1][1][limit-1];
                        int exclude =  dp[index+1][0][limit];
                        profit = max(include,exclude);
                    }

                    dp[index][buy][limit] = profit;
                }
            }
        }
        return dp[0][1][2];
    }
};


class SpaceOptimised {
public:
    
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        // vector<vector<vector<int>>> dp(n+1,vector<vector<int>>(2,vector<int>(3,0)));
        vector<vector<int>> curr(2,vector<int>(3,0));
        vector<vector<int>> next(2,vector<int>(3,0));
        for(int index = n-1; index >= 0;index-- ){
            for(int buy = 0;buy <= 1 ;buy++){
                for(int limit = 1; limit <= 2; limit++){
                    int profit = 0;
                    if(buy){ // purchase
                        int include = -prices[index] + next[0][limit];
                        int exclude =  next[1][limit];
                        profit = max(include,exclude);
                    }else{ // sell
                        int include = prices[index] + next[1][limit-1];
                        int exclude =  next[0][limit];
                        profit = max(include,exclude);
                    }

                    curr[buy][limit] = profit;
                }
                next = curr;
            }
        }
        return next[1][2];
    }
};

int main() {

    vector<int> prices =  {3,3,5,0,0,3,1,4};
    Memoization m;
    Tabulation t;
    SpaceOptimised s;
    cout<<"The answers for buy and sell 2 \n";
    cout<<"Memoization :"<<m.maxProfit(prices)<<endl;
    cout<<"Tabulation :"<<t.maxProfit(prices)<<endl;
    cout<<"Space Optimized :"<<s.maxProfit(prices)<<endl;
    return 0;
}
