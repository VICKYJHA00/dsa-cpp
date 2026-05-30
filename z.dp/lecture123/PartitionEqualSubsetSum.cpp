#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

// =====================
// Recursive Solution
// =====================

class Solution {
public:

    bool solve(vector<int>& nums, int target, int index) {

        if(target == 0)
            return true;

        if(index >= nums.size() || target < 0)
            return false;

        bool include =
            solve(nums,
                  target - nums[index],
                  index + 1);
  
                  
        bool exclude =
            solve(nums,
                  target,
                  index + 1);

        return include || exclude;
    }

    bool canPartition(vector<int>& nums) {

        int sum =
            accumulate(nums.begin(),
                       nums.end(),
                       0);

        if(sum & 1)
            return false;

        int target = sum / 2;

        return solve(nums,
                     target,
                     0);
    }
};

// =====================
// Memoization Solution
// =====================

class Memoization {
public:

    bool solve(vector<int>& nums,
               int target,
               int index,
               vector<vector<int>>& dp) {

        if(target == 0)
            return true;

        if(index >= nums.size() || target < 0)
            return false;

        if(dp[index][target] != -1)
            return dp[index][target];

        bool include =
            solve(nums,
                  target - nums[index],
                  index + 1,
                  dp);

        bool exclude =
            solve(nums,
                  target,
                  index + 1,
                  dp);

        return dp[index][target] =
               include || exclude;
    }

    bool canPartition(vector<int>& nums) {

        int sum =
            accumulate(nums.begin(),
                       nums.end(),
                       0);

        if(sum & 1)
            return false;

        int target = sum / 2;

        vector<vector<int>> dp(
            nums.size(),
            vector<int>(target + 1, -1));

        return solve(nums,
                     target,
                     0,
                     dp);
    }
};



// =====================
// Tabulation Solution
// =====================
class Tabulation {
public:

    bool canPartition(vector<int>& nums) {

        int n = nums.size();

        int sum = accumulate(nums.begin(),
                       nums.end(),
                       0);

        if(sum & 1)
            return false;

        int target = sum / 2;

        vector<vector<bool>> dp(
            n + 1,
            vector<bool>(target + 1, false));

        for(int i = 0; i <= n; i++)
            dp[i][0] = true;

        for(int index = n - 1; index >= 0; index--) {

            for(int t = 1; t <= target; t++) {

                bool include = false;

                if(t - nums[index] >= 0)
                    include =
                        dp[index + 1]
                          [t - nums[index]];

                bool exclude =
                    dp[index + 1][t];

                dp[index][t] =
                    include || exclude;
            }
        }

        return dp[0][target];
    }
};

// =====================
// Space optimized Tabulation Solution
// =====================
class SpaceOptimized {
public:

    bool canPartition(vector<int>& nums) {

        int n = nums.size();

       int sum = accumulate(nums.begin(),
                       nums.end(),
                       0);
        if(sum & 1)
            return false;

        int target = sum / 2;

        vector<bool> curr(target + 1, false);
        vector<bool> next(target + 1, false);

        curr[0] = true;
        next[0] = true;

        for(int index = n - 1;
            index >= 0;
            index--) {

            for(int t = 1;
                t <= target;
                t++) {

                bool include = false;

                if(t - nums[index] >= 0)
                    include =
                        next[t - nums[index]];

                bool exclude =
                    next[t];

                curr[t] =
                    include || exclude;
            }

            next = curr;
        }

        return next[target];
    }
};




// =====================
// Main Function
// =====================

int main() {

    vector<int> nums = {1, 5, 11, 5};

    Solution recursion;
    Memoization memo;
    Tabulation tab;
    SpaceOptimized spaceOpt;

    cout << "Recursion   : "
         << recursion.canPartition(nums)
         << endl;

    cout << "Memoization : "
         << memo.canPartition(nums)
         << endl;

    cout << "Tabulation  : "
         << tab.canPartition(nums)
         << endl;

    cout << "Space Opt.  : "
         << spaceOpt.canPartition(nums)
         << endl;

   return 0;
}