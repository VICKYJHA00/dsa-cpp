#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>
using namespace std;

int solve(int i, int j, vector<int>& v, vector<vector<int>>& dp) {
    if (j - i < 2) return 0;

    if (dp[i][j] != -1) return dp[i][j];

    int ans = INT_MAX;

    for (int k = i + 1; k < j; k++) {
        int cost = v[i] * v[k] * v[j]
                 + solve(i, k, v, dp)
                 + solve(k, j, v, dp);

        ans = min(ans, cost);
    }

    return dp[i][j] = ans;
}
int memorization(vector<int>& v) {
    int n = v.size();
    vector<vector<int>> dp(n, vector<int>(n, -1));
    return solve(0, n - 1, v, dp);
}
int tabulation(vector<int>& v) {
    int n = v.size();
    vector<vector<int>> dp(n, vector<int>(n, 0));

    for(int i = n - 1; i >= 0; i--) {
        for (int j = i + 2; j < n; j++) {
            int ans = INT_MAX;

            for (int k = i + 1; k < j; k++) {
                int cost = v[i] * v[k] * v[j]
                         + dp[i][k]
                         + dp[k][j];

                ans = min(ans, cost);
            }

            dp[i][j] = ans;
        }
    }
    return dp[0][n - 1];
}


int main() {
    vector<int> v = {1, 2, 3, 4, 5};
    cout << memorization(v) << endl;
    cout << tabulation(v) << endl;
    return 0;
}