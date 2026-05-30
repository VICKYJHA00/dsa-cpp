// 801. Minimum Swaps To Make Sequences Increasing
#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>
using namespace std;

// =====================
// Recursive Solution
// =====================
class Recursion {
public:
    int solve(vector<int>& nums1,vector<int>& nums2,int index,bool swapped){
        if(index == nums1.size()) return 0;

        int prev1 = swapped ? nums2[index-1] : nums1[index-1];
        int prev2 = swapped ? nums1[index-1] : nums2[index-1];

        int ans = INT_MAX;

        if(nums1[index] > prev1 && nums2[index] > prev2){
            ans = solve(nums1,nums2,index+1,false);
        }
        if(nums1[index] > prev2 && nums2[index] > prev1){
            ans = min(ans,1 + solve(nums1,nums2,index+1,true));
        }
        return ans;
    }
    int minSwapRecursion(vector<int>& nums1, vector<int>& nums2) {
        return solve(nums1,nums2,1,false);
    }
};


// =====================
// Memoization Solution
// =====================
class Memoization {
public:
    int solve(vector<int>& nums1,vector<int>& nums2,int index,bool swapped,vector<vector<int>>& dp){
        if(index == nums1.size()) return 0; 
        if(dp[index][swapped] != -1) return dp[index][swapped];

        int prev1 = swapped ? nums2[index-1] : nums1[index-1];
        int prev2 = swapped ? nums1[index-1] : nums2[index-1];
        int ans = INT_MAX;
        if(nums1[index] > prev1 && nums2[index] > prev2){ // No swap
            ans = solve(nums1,nums2,index+1,false,dp);
        }
        if(nums1[index] > prev2 && nums2[index] > prev1){ // Swap
            ans = min(ans,1 + solve(nums1,nums2,index+1,true,dp));
        }
        return dp[index][swapped] = ans;
    }
    int minSwapMemoization(vector<int>& nums1, vector<int>& nums2) {
        nums1.insert(nums1.begin(), INT_MIN); // To handle the base case for the first element
        nums2.insert(nums2.begin(), INT_MIN);
        int n = nums1.size();
        vector<vector<int>> dp(n,vector<int>(2,-1));
        return solve(nums1,nums2,1,false,dp);
    }
};

// =====================    
// Tabulation Solution
// =====================
class Tabulation {
public:
    int minSwap(vector<int>& nums1, vector<int>& nums2) {

        nums1.insert(nums1.begin(), INT_MIN);
        nums2.insert(nums2.begin(), INT_MIN);

        int n = nums1.size();

        vector<vector<int>> dp(n + 1, vector<int>(2, 0));

        const int INF = 1e9;

        for (int i = n - 1; i >= 1; i--) {

            for (int swapped = 0; swapped <= 1; swapped++) {

                int prev1 = nums1[i - 1];
                int prev2 = nums2[i - 1];

                if (swapped) {
                    swap(prev1, prev2);
                }

                int ans = INF;

                // No swap at current index
                if (nums1[i] > prev1 && nums2[i] > prev2) {
                    ans = dp[i + 1][0];
                }

                // Swap at current index
                if (nums1[i] > prev2 && nums2[i] > prev1) {
                    ans = min(ans, 1 + dp[i + 1][1]);
                }

                dp[i][swapped] = ans;
            }
        }

        return dp[1][0];
    }
};


int main(){
    vector<int> nums1 = {1,3,5,4};
    vector<int> nums2 = {1,2,3,7};
    Memoization sol;
    Recursion solRecursion;
    Tabulation solTabulation;
    cout << "Recursive Solution: " << solRecursion.minSwapRecursion(nums1,nums2) << endl;
    cout << "Memoization Solution: " << sol.minSwapMemoization(nums1,nums2) << endl; // Output: 1
    cout << "Tabulation Solution: " << solTabulation.minSwap(nums1,nums2) << endl; // Output: 1
    return 0;
}