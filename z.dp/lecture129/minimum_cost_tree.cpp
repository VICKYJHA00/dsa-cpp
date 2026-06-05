// 1130. Minimum Cost Tree From Leaf Values
// Solved
// Medium
// Topics
// premium lock iconCompanies
// Hint

// Given an array arr of positive integers, consider all binary trees such that:

//     Each node has either 0 or 2 children;
//     The values of arr correspond to the values of each leaf in an in-order traversal of the tree.
//     The value of each non-leaf node is equal to the product of the largest leaf value in its left and right subtree, respectively.

// Among all possible binary trees considered, return the smallest possible sum of the values of each non-leaf node. It is guaranteed this sum fits into a 32-bit integer.

// A node is a leaf if and only if it has zero children.

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(int left,int right,vector<int>& arr,vector<vector<int>>& dp){
        if(left == right) return 0;
        if(dp[left][right] != -1) return dp[left][right];

        int ans = INT_MAX;
        for(int k = left;k<right;k++){
            int leftMax = *max_element(arr.begin() + left , arr.begin()+k+1);
            int rightMax = *max_element(arr.begin() + k+1 , arr.begin()+right+1);
            
            ans = min(ans, leftMax * rightMax + solve(left,k,arr,dp) + solve(k+1,right,arr,dp) ) ;
        }
        return dp[left][right] = ans;
    }

    int mctFromLeafValues(vector<int>& arr) {
        int n = arr.size()-1;
        vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
        return solve(0,n,arr,dp);
    }
};

int main() {
    vector<int> arr = {6, 2, 4};

    Solution s;

    cout << "Minimum Cost Tree From Leaf Values: "
         << s.mctFromLeafValues(arr);

    cout << endl;

    return 0;
}