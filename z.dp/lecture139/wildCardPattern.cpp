#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool solve(string& s, string& p, int i ,int j , vector<vector<int>>& dp){
        if(i<0 && j<0) return true;
        if(i>=0 && j<0) return false;
        if(i<0 && j>=0){
            for(int k = 0;k<=j;k++ ){
                if(p[k] != '*') return false;
            }
            return true;
        }

        if(dp[i][j] != -1) return dp[i][j];
        if(s[i] == p[j] || p[j] == '?') return dp[i][j] = solve(s,p,i-1,j-1,dp);
        else if(p[j] == '*')  return dp[i][j] = solve(s,p,i-1,j,dp) || solve(s,p,i,j-1,dp);
        else return false;
    }

    bool isMatch(string s, string p) {
        int i = s.length();
        int j = p.length();
        vector<vector<int>>dp(i+1,vector<int>(j+1,-1));
        return solve(s,p,i-1,j-1,dp);
    }
};

int main() {
    string s = "aa";
    string p = "a";
    Solution sol;
    if(sol.isMatch(s,p)){
        cout<<"The answer is  TRUE";
    }else{
        cout<<"The answer is  FALSE";
    }
    return 0;
}
