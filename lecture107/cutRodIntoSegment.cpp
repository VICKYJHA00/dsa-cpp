// in this problem we are given a rod of length n and an array of prices that contains prices of all pieces of size smaller than n. We have to determine the maximum value obtainable by cutting up the rod and selling the pieces. For example, if length of the rod is 8 and the values of different pieces are given as following, then the maximum obtainable value is 22 (by cutting in two pieces of lengths 2 and 6)
#include<iostream>
#include<algorithm>
#include<climits>
#include<vector>
using namespace std;

    //-- this is normal recursion--//
// int solve(int n, int x, int y, int z){
//     if(n==0 ) return 0;
//     if(n<0) return INT_MIN;
//     int a = solve(n-x,x,y,z) +1;
//     int b = solve(n-y,x,y,z) +1;
//     int c = solve(n-z,x,y,z) +1;

//     int ans = max(a,max(b,c));
//     return ans;
// }

// int cutRodIntoSegment(int n , int x, int y , int z){
//     int ans = solve(n,x,y,z);
//     return ans;
// }



//-- this is memorization--//
// int solveMem(int n, int x, int y, int z, vector<int> &dp){
//     if(n==0 ) return 0;
//     if(n<0) return INT_MIN;
//     if(dp[n] != -1) return dp[n];
//     int a = solveMem(n-x,x,y,z,dp) +1;
//     int b = solveMem(n-y,x,y,z,dp) +1;
//     int c = solveMem(n-z,x,y,z,dp) +1;

//     int ans = max(a,max(b,c));
//     return dp[n] = ans;
// }

// int cutRodIntoSegment(int n , int x, int y , int z){
//     vector<int> dp(n+1,-1);
//     int ans = solveMem(n,x,y,z,dp);
//     return ans;
// }

// -- using tabulation form {bottom up approach} --//

int solveTab(int n, int x, int y, int z){
    vector<int> dp(n+1,INT_MIN);
    dp[0] = 0;

    for(int i =0;i<=n;i++){
        if(i-x >= 0)
            dp[i] = max(dp[i],dp[i-x] + 1);

        if(i-y >= 0)
            dp[i] = max(dp[i],dp[i-y] + 1);    

        if(i-z >= 0)
            dp[i] = max(dp[i],dp[i-z] + 1);
    }

    if(dp[n]<0) return 0;
    else return dp[n];
}

int cutRodIntoSegment(int n,int x, int y , int z){
    int ans = solveTab(n,x,y,z);
    return ans;
}



int main(){
    int n = 7, x = 5, y = 2, z = 2;
    // cout<<cutRodIntoSegment(n,x,y,z);
    cout<<cutRodIntoSegment(n,x,y,z);

    return 0;
}