#include<iostream>
#include<vector>
#include<climits>
#include<algorithm>
using namespace std;


int solve(vector<int>& satisfaction,int index,int time,vector<vector<int>> &dp){
    int n = satisfaction.size();
    if(index == n) return 0;

    if(dp[index][time] != -1) return dp[index][time];

    int include = satisfaction[index]*time + solve(satisfaction,index+1,time+1,dp);
    int exclude = solve(satisfaction,index+1,time,dp);

    return dp[index][time] = max(include,exclude);
}
int memorization(vector<int>& satisfaction) {
    int n = satisfaction.size();
    sort(satisfaction.begin(),satisfaction.end());
    vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
    return solve(satisfaction,0,1,dp);
}


int tabularion(vector<int>& satisfaction) {

    int n = satisfaction.size();
    vector<vector<int>> dp(n+1,vector<int>(n+1,0));
    sort(satisfaction.begin(),satisfaction.end());
    for(int i = n-1;i>=0;i--){
        for(int t = i;t>=0;t--){
            int include = satisfaction[i]*(t+1) + dp[i+1][t+1];
            int exclude = dp[i+1][t];

            dp[i][t] = max(include,exclude);
        }
    }
    return dp[0][0];
}

int maxSatisfaction(vector<int>& satisfaction) {

    int n = satisfaction.size();
    vector<int> curr(n+1, 0), next(n+1, 0);
    sort(satisfaction.begin(),satisfaction.end());
    for(int index = n-1; index >= 0; index--) {
    for(int time = index; time >= 0; time--) {
        int include = satisfaction[index] * (time+1) + next[time+1];
        int exclude = next[time];

        curr[time] = max(include, exclude);
    }
    next = curr;
    }
    return curr[0];
}

int main(){
    vector<int> satisfaction = {-1,-8,0,5,-9};
    cout<<"The maximum satisfaction is  by memorization: ";
    cout<<memorization(satisfaction)<<endl;
    cout<<"\nThe maximum satisfaction is  by tabulation: ";
    cout<<tabularion(satisfaction)<<endl;
    cout<<"\nThe maximum satisfaction is  by space optimization: ";
    cout<<maxSatisfaction(satisfaction)<<endl;
    return 0;
}
