#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


int solve(vector<vector<int>>& mat, int i, int j, int& maxi){
    if(i >= mat.size() || j >= mat[0].size()) return 0;

    int right = solve(mat, i, j+1, maxi);
    int down = solve(mat, i+1, j, maxi);
    int diagonal = solve(mat, i+1, j+1, maxi);
    
    if(mat[i][j] == 1){
        int ans = min({right, down, diagonal}) + 1;
        maxi = max(maxi, ans);
        return ans;
    }
    else{
        return 0;
    }
}


int solveMem(vector<vector<int>>& mat, int i, int j, vector<vector<int>>& dp, int& maxi){
    if(i >= mat.size() || j >= mat[0].size()) return 0;
    if(dp[i][j] != -1) return dp[i][j];

    int right = solveMem(mat, i, j+1, dp, maxi);
    int down = solveMem(mat, i+1, j, dp, maxi);
    int diagonal = solveMem(mat, i+1, j+1, dp, maxi);
    
    if(mat[i][j] == 1){
        int ans = min({right, down, diagonal}) + 1;
        maxi = max(maxi, ans);
        dp[i][j] = ans;
    }
    else{
        dp[i][j] = 0;
    }
    return dp[i][j];
}

int memorization(vector<vector<int>>& mat){
    int maxi = 0;
    vector<vector<int>> dp(mat.size(), vector<int>(mat[0].size(), -1));
    solveMem(mat, 0, 0, dp, maxi);
    return maxi;
}


int tabulation(vector<vector<int>>& mat){
    int maxi = 0, rows = mat.size(), cols = mat[0].size();
    vector<vector<int>> dp(rows + 1, vector<int>(cols + 1, 0));

    for(int i = rows - 1; i >= 0; i--){
        for(int j = cols - 1; j >= 0; j--){
            int right = dp[i][j+1];
            int diagonal = dp[i+1][j+1];
            int down = dp[i+1][j];

            if(mat[i][j] == 1){
                dp[i][j] = min({right, diagonal, down}) + 1;
                maxi = max(maxi, dp[i][j]);
            }
            else{
                dp[i][j] = 0;
            }
        }
    }
    return maxi;
}


int spaceOptimized(vector<vector<int>>& mat){
    int maxi = 0, rows = mat.size(), cols = mat[0].size();
    vector<int> curr(cols + 1, 0), next(cols + 1, 0);

    for(int i = rows - 1; i >= 0; i--){
        for(int j = cols - 1; j >= 0; j--){
            int right = curr[j+1];
            int diagonal = next[j+1];
            int down = next[j];

            if(mat[i][j] == 1){
                curr[j] = min({right, diagonal, down}) + 1;
                maxi = max(maxi, curr[j]);
            }
            else{
                curr[j] = 0;
            }
        }
        next = curr;
    }
    return maxi;
}

int main(){
    vector<vector<int>> mat = {{0, 1, 1, 0},{1, 1, 1, 0},{0, 1, 1, 1}};

    int maxi = 0;
    cout << "Longest square submatrix of 1s (Recursion): " << solve(mat, 0, 0, maxi) << endl;
    cout << "Longest square submatrix of 1s (Memoization): " << memorization(mat) << endl;
    cout << "Longest square submatrix of 1s (Tabulation): " << tabulation(mat) << endl;
    cout << "Longest square submatrix of 1s (Space Optimized): " << spaceOptimized(mat) << endl;

    return 0;
}
