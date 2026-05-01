
#include<iostream>
#include<vector>
#include<climits>
#include<algorithm>
using namespace std;



int solve(int idx,int lastidx,int n ,vector<int> &slices,vector<vector<int>>& dp){
    if(n == 0 || idx >= lastidx) return 0;
    if(dp[idx][n] != -1) return dp[idx][n];

    int incl = slices[idx] + solve(idx+2,lastidx,n-1,slices,dp);
    int excl = solve(idx+1,lastidx,n,slices,dp);

    return dp[idx][n] = max(incl,excl);
}

int maxSizeSlices(vector<int>& slices) {
    int k = slices.size();
    vector<vector<int>> dp(k,vector<int>(k,-1));
    int case1 = solve(0,k-1,k/3,slices,dp);
    dp.assign(k,vector<int>(k,-1));
    int case2 = solve(1,k,k/3,slices,dp);
    return max(case1,case2);
}

int maxSizeSlicesTab(vector<int>& slices) {
    int k = slices.size();
    vector<vector<int>> dp(k+2,vector<int>(k+2,0));
    vector<vector<int>> dp2(k+2,vector<int>(k+2,0));

    for(int i = k-2;i>=0;i--){
        for(int n = 1;n<=k/3;n++){
            int take = slices[i]+ dp[i+2][n-1];
            int nottake =  dp[i+1][n];

            dp[i][n] = max(take,nottake);
        }
    }

    int case1 = dp[0][k/3];

    for(int i = k-1;i>=1;i--){
        for(int n = 1;n<=k/3;n++){
            int take = slices[i]+ dp2[i+2][n-1];
            int nottake =  dp2[i+1][n];

            dp2[i][n] = max(take,nottake);
        }
    }

    int case2 = dp2[1][k/3];

    return max(case1,case2);

}

int main(){
    vector<int> slices = {1, 2, 3, 4, 5, 6};
    int memorizationAns =  maxSizeSlices(slices);
    int tabultationAns = maxSizeSlicesTab(slices);

    cout<<"The ans from the Memorization is : "<<memorizationAns<<endl;
    cout<<"The ans from the Tabulation is : "<<tabultationAns<<endl;
    return 0;

}