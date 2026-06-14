#include <bits/stdc++.h>
using namespace std;

class Solution {
public:


    // bool solve(string& s, string& p, int i ,int j , vector<vector<int>>& dp){
    //     if(i==0 && j==0) return true;
    //     if(i>0 && j==0) return false; 
    //     if(i==0 && j>0){
    //         for(int k = 0;k<j;k++ ){
    //             if(p[k] != '*') return false;
    //         }
    //         return true;
    //     } 
        
    //     if(dp[i][j] != -1) return dp[i][j];

    //     if(s[i-1] == p[j-1] || p[j-1] == '?') return dp[i][j] = solve(s,p,i-1,j-1,dp);
    //     else if(p[j-1] == '*')  return dp[i][j] = solve(s,p,i-1,j,dp) || solve(s,p,i,j-1,dp);
    //     else return dp[i][j] =  false;
    // }



    // bool solveTab(string s, string p) {
    //     int m = s.length();
    //     int n = p.length();
    //     vector<vector<int>>dp(m+1,vector<int>(n+1,0));
    //     dp[0][0] = true;
    //     for(int j = 1;j<=n;j++){
    //         bool flag = true;
    //         for(int k = 0;k<j;k++ ){
    //             if(p[k] != '*'){
    //                 flag = false;
    //                 break;
    //             }
    //         }
    //         dp[0][j] = flag;
    //     }

    //     for(int i =1;i<=m;i++){
    //         for(int j = 1;j<=n;j++){
    //             if(s[i-1] == p[j-1] || p[j-1] == '?')  dp[i][j] = dp[i-1][j-1];
    //             else if(p[j-1] == '*')   dp[i][j] = dp[i][j-1] || dp[i-1][j];
    //             else  dp[i][j] =  false;
    //         }
    //     }

    //     return dp[m][n];
    // }



       bool solveOP(string s, string p) {
        int m = s.length();
        int n = p.length();
        // vector<vector<int>>dp(m+1,vector<int>(n+1,0));
        vector<int>curr(n+1,0);
        vector<int>prev(n+1,0);
        prev[0] = true;
        for(int j = 1;j<=n;j++){
            bool flag = true;
            for(int k = 0;k<j;k++ ){
                if(p[k] != '*'){
                    flag = false;
                    break;
                }
            }
            prev[j] = flag;
        }

        for(int i =1;i<=m;i++){
            fill(curr.begin(), curr.end(), false);
            curr[0] = false;
            for(int j = 1;j<=n;j++){
                if(s[i-1] == p[j-1] || p[j-1] == '?')  curr[j] = prev[j-1];
                else if(p[j-1] == '*')   curr[j] = curr[j-1] || prev[j];
                else  curr[j] =  false;
            }
            prev = curr;
        }

        return prev[n];
    }



    bool isMatch(string s, string p) {
        int i = s.length();
        int j = p.length();
        vector<vector<int>>dp(i+1,vector<int>(j+1,-1));
        // return solve(s,p,i,j,dp);
        return solveOP(s,p);
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
