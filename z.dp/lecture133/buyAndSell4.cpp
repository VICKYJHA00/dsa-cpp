#include <bits/stdc++.h>
using namespace std;

class SpaceOptimised {
public:
    
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int k = 3;
        // vector<vector<vector<int>>> dp(n+1,vector<vector<int>>(2,vector<int>(3,0)));
        vector<vector<int>> curr(2,vector<int>(k+1,0));
        vector<vector<int>> next(2,vector<int>(k+1,0));
        for(int index = n-1; index >= 0;index-- ){
            for(int buy = 0;buy <= 1 ;buy++){
                for(int limit = 1; limit <= k; limit++){
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
        return next[1][k];
    }
};

int main() {

    vector<int> prices =  {3,3,5,0,0,3,1,4};
    int k = 3;
    SpaceOptimised s;
    cout<<"Space Optimized :"<<s.maxProfit(prices)<<endl;
    return 0;
}
