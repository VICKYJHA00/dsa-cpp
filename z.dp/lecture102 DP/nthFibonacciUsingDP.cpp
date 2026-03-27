// nth finbonacci number using dynamic programming
#include <iostream>
#include <vector>
using namespace std;

int fibo(int n, vector<int> &dp){ // using memorization method top-Down approach
    if(n <= 1) return n;

    if(dp[n] != -1) return dp[n];

    dp[n] = fibo(n-1,dp) + fibo(n-2,dp);

    return dp[n];

}

int fib(int n){
    vector<int> dp(n+1,-1); // using tabulation method
    dp[0] = 0;
    dp[1] = 1;

    for(int i = 0;i<=n;i++){
        dp[i] = dp[i-1] + dp[i-2];
    }
    return dp[n];

}

int fibon(int n){
    if(n<=1) return n;

    int prev2 = 0;
    int prev1 = 1;
    for(int i = 2;i<= n;i++){
        int curr = prev1 + prev2;
        prev2 = prev1;
        prev1 = curr;
    }
    return prev1;
}


int main(){
    
    int n;
    cout<<"Enter the value of n: ";
    cin>>n;
    vector<int> dp(n+1,-1);
    // dp[0] = 0;
    int ans = fibo(n,dp);
    cout<<"The "<<n<<"th fibonacci number is: "<<ans<<endl;

    cout<<fibon(n);
    
    return 0;

}