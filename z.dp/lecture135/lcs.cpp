#include <bits/stdc++.h>
using namespace std;

class Memoization {
public:
    int solve(int i , int j, string& text1, string& text2,vector<vector<int>>& dp){
        if(i >= text1.length() || j >= text2.length()) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        int length = 0;
        if(text1[i] == text2[j]){
            length = 1 + solve(i+1,j+1,text1,text2,dp);
        }else{
            int a = solve(i+1,j,text1,text2,dp);
            int b = solve(i,j+1,text1,text2,dp);
            length = max(a,b);
        }
        return dp[i][j] = length;
    }
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.length();
        int m = text2.length();
        vector<vector<int>>dp(n,vector<int>(m,-1));
        return solve(0,0,text1,text2,dp);
    }
};

class Tabulation
public: 
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.length();
        int m = text2.length();
        vector<vector<int>>dp(n+1,vector<int>(m+1,0));
        for(int i = text1.length()-1;i>= 0;i--){
            for(int  j = text2.length()-1;j>= 0;j--){
                 int length = 0;
                if(text1[i] == text2[j]){
                    length = 1 + dp[i+1][j+1];
                }else{
                    int a = dp[i+1][j];
                    int b = dp[i][j+1];
                    length = max(a,b);
                }
                dp[i][j] = length;
            }
        }
        return dp[0][0];
    }
};

class spaceOptimised {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.length();
        int m = text2.length();
        // vector<vector<int>>dp(n+1,vector<int>(m+1,0));
        vector<int> curr(m+1,0);
        vector<int> next(m+1,0);
        for(int i = text1.length()-1;i>= 0;i--){
            for(int  j = text2.length()-1;j>= 0;j--){
                 int length = 0;
                if(text1[i] == text2[j]){
                    length = 1 + next[j+1];
                }else{
                    int a = next[j];
                    int b = curr[j+1];
                    length = max(a,b);
                };
                curr[j] = length ;
            }
            next = curr;
        }
        return next[0];
    }
};


int main() {

    string text1 = "abcde";
    string text2 = "ace";

    Memoization m;
    Tabulation t;
    SpaceOptimised s;

    cout << "The Longest Common Subsequence by Memoization : "
         << m.longestCommonSubsequence(text1, text2) << endl;

    cout << "The Longest Common Subsequence by Tabulation : "
         << t.longestCommonSubsequence(text1, text2) << endl;

    cout << "The Longest Common Subsequence by Space Optimised : "
         << s.longestCommonSubsequence(text1, text2) << endl;

    return 0;
}