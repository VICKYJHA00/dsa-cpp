#include<iostream>
#include<vector>
using namespace std;

const long long mod = 1e9 + 7;

long long memorization(int n , int k, vector<long long> &dp){
    if(n == 1) return k;
    if(n == 2) return 1LL * k * k % mod;

    if(dp[n] != -1) return dp[n];

    dp[n] = ((memorization(n-1,k,dp) + memorization(n-2,k,dp)) % mod * (k-1)) % mod;
    return dp[n];
}

long long solve1(int n ,int k){
    if(n == 0) return 0;
    vector<long long> dp(n+1,-1);
    return memorization(n,k,dp);
}

long long tabulation(int n , int k){
    if(n == 0) return 0;

    vector<long long> dp(n+1);
    dp[1] = k;
    if(n>=2) dp[2] = 1LL * k * k % mod;

    for(int i = 3; i<= n;i++){
        dp[i] = ((dp[i-1] + dp[i-2]) % mod * (k-1)) % mod;
    }
    return dp[n];
}

long long spaceoptimization(int n , int k){
    if(n == 0) return 0;
    if(n == 1) return k;
    if(n == 2) return 1LL * k * k % mod;
    
    long long prev2 = k;
    long long prev1 = 1LL * k * k % mod;

    for(int i = 3; i<= n;i++){
        long long curr = ((prev1 + prev2) % mod * (k-1)) % mod;
        prev2 = prev1;
        prev1 = curr;
    }
    return prev1;
}

int main(){
    int n = 5;
    int k = 3;
    cout<<"The Count of Ways to Paint the Fence is: ";
    cout<<spaceoptimization(n,k)<<endl;
}