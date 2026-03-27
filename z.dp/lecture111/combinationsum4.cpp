#include<iostream>
#include<vector>
using namespace std;

// using recusrion 
int solve(vector<int> &arr , int  target){
    if(target == 0) return 1;
    if(target<0) return 0;

    int ans = 0;
    for(int i = 0;i<arr.size();i++){
        ans += solve(arr,target-arr[i]);
    }
    return ans;
}

int solveMem(vector<int> & arr, int target, vector<int> &dp){
    if(target == 0) return 1;
    if(target < 0) return 0;

    if(target < dp.size() && dp[target] != -1) return dp[target];

    int ans = 0;
    for(int i = 0;i<arr.size();i++){
        ans += solveMem(arr,target-arr[i],dp);
    }
    if(target < dp.size())
        dp[target] = ans;
    return ans;

}

int solve2(vector<int> & arr, int target){
    vector<int> dp(target + 1, -1);
    return solveMem(arr,target,dp);
}

int solveTab(vector<int>& arr, int target){
    vector<int> dp(target+1,0);
    dp[0] = 1;

    for(int i = 1;i<=target;i++){
        for(int j = 0;j<arr.size();j++){
            if(arr[j] <= i){
                dp[i] += dp[i - arr[j]];
            }
        }
    }
    return dp[target];
}


int main(){
    vector<int> arr = {1,2,3};
    int target = 4;
    cout<<"solve using recursion "<<endl;
    cout<<solve(arr,target)<<endl;
    cout<<"solve using memoization "<<endl;
    cout<<solve2(arr,target)<<endl;
    cout<<"solve using tabulation "<<endl;
    cout<<solveTab(arr,target)<<endl;
}