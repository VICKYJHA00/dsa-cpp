#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(int i ,int j ,string& s, string& r,vector<vector<int>>&dp){
        if(i>=s.length() || j >= r.length()) return 0;
        if(dp[i][j] != -1) return dp[i][j];

        int len = 0;

        if(s[i] == r[j]){
            return dp[i][j] =   1 + solve(i+1,j+1,s,r,dp);
        }
        else{
            int a = solve(i+1,j,s,r,dp);
            int b = solve(i,j+1,s,r,dp);
            len = max(a,b);
            return dp[i][j] = max(a,b);
        }

    }
    int longestPalindromeSubseq(string s) {
        string r = s;
        reverse(r.begin(),r.end());
        int n = s.length();
        vector<vector<int>>dp(n,vector<int>(n,-1));
        return solve(0, 0 ,s,r,dp);
    }
};


int main() {
    string s = "bbbab";
    Solution sol;
    cout<<"The longest palindrome is : "<<sol.longestPalindromeSubseq(s);
    return 0;
}
