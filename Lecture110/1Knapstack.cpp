#include<iostream> 
#include<vector>
#include<algorithm>
using namespace std;

int solve(vector<int> &weight,vector<int> &value, int n , int capacity){
    // base case
    if(n == 0){
        if(weight[n] <= capacity){
            return value[0];
        }else
         return 0;
    }

    int include = 0;
    if(weight[n]<= capacity){
        include = value[n] + solve(weight,value,n-1, capacity - weight[n]);
    }
    int exclude = solve(weight,value,n-1,capacity);

    int ans = max(include,exclude);
    return ans;
}

int solve1(vector<int> &weight,vector<int> &value, int n , int capacity , vector<vector<int>> &dp){
    // base case
    if(n == 0){
        if(weight[n] <= capacity){
            return value[0];
        }else
         return 0;
    }

    if(dp[n][capacity] != -1) return dp[n][capacity];

    int include = 0;
    if(weight[n]<= capacity){
        include = value[n] + solve1(weight,value,n-1, capacity - weight[n], dp);
    }
    int exclude = solve1(weight,value,n-1,capacity, dp);

    dp[n][capacity] = max(include,exclude);
    return dp[n][capacity];
}

int Memoization(vector<int> &weight,vector<int> &value, int n , int capacity){
    vector<vector<int>> dp(n, vector<int>(capacity+1, -1));
    return solve1(weight,value,n-1,capacity, dp);
}    


int tabluation(vector<int> & weight , vector<int> &val, int n , int capacity){
    vector<vector<int>> dp(n, vector<int>(capacity+1, 0));

    for(int w = weight[0]; w < capacity ; w++){
        if(weight[0] <= w) dp[0][w] = val[0];
        else dp[0][w] = 0;
    }

    for(int i = 1;i<n; i++){
        for(int w = 0;w<= capacity; w++){
            int include = 0;
            if(weight[i] <= w) include = val[i] + dp[i-1][w-weight[i]];
            int exclude = dp[i-1][w];
            dp[i][w] = max(include,exclude);
        }
    }
    return dp[n-1][capacity];
}

int main() {

    vector<int> weight = {1, 2, 4, 5};
    vector<int> value  = {5, 4, 8, 6};
    int capacity = 5;

    int n = weight.size();

    int result = solve(weight, value, n-1, capacity);
    int result1 = Memoization(weight, value, n, capacity);
    int result2 = tabluation(weight, value, n, capacity);

    cout << "Maximum value in Knapsack = " << result << endl;
    cout << "Maximum value in Knapsack (Memoization) = " << result1 << endl;
    cout << "Maximum value in Knapsack (Tabulation) = " << result2 << endl;

    return 0;
}