#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(int i , int j ,string& word1,string& word2,vector<vector<int>>& dp){
        if(i == word1.size()) return word2.size()-j;
        if(j == word2.size()) return word1.size()-i;
        if(dp[i][j] != -1) return dp[i][j];

        int len = 0;
        if(word1[i] == word2[j]){
            len = solve(i+1,j+1,word1,word2,dp);
        }else{
            int delet = 1 + solve(i,j+1,word1,word2,dp);
            int insert = 1 + solve(i+1,j,word1,word2,dp);
            int replace = 1 + solve(i+1,j+1,word1,word2,dp);

            len = min(delet,min(insert,replace));
        }

        return dp[i][j] = len;

    }
    int minDistance(string word1, string word2) {
        vector<vector<int>> dp(word1.length(),vector<int>(word2.length(),-1));
        return solve(0,0,word1,word2,dp);
    }
};

int main() {
    string word1 = "intention";
    string word2 = "execution";
    Solution sol;
    cout<<"The minimum operations to match the string is :"<<sol.minDistance(word1,word2);
    return 0;
}
