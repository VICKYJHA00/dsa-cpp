#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>
using namespace std;

int recursion(vector<int>& v,int currlane,int currpos){
    int n = v.size()-1;
    if(currpos == n) return 0;
    if(v[currpos+1] != currlane) return recursion(v,currlane,currpos+1);
    else{
        int ans = INT_MAX;
        for(int i = 1;i<=3;i++){
            if(i != currlane && v[currpos] != i){
                ans = min(ans,1+recursion(v,i,currpos));
            }
        }
        return ans;
    }
}
int memorization(vector<int>& v,int currlane,int currpos,vector<vector<int>>& dp){
    int n = v.size()-1;
    if(currpos == n) return 0;
    if(v[currpos+1] != currlane) return memorization(v,currlane,currpos+1,dp);
    else{
        int ans = INT_MAX;
        for(int i = 1;i<=3;i++){
            if(i != currlane && v[currpos] != i){
                ans = min(ans,1+memorization(v,i,currpos,dp));
            }
        }
        return dp[currlane][currpos] = ans;
    }
}

int main(){
    vector<int> v = {0,1,2,3,0};
    vector<vector<int>> dp(4,vector<int>(v.size(),-1));
    
    cout<<recursion(v,2,0)<<endl;
    cout<<memorization(v,2,0,dp)<<endl;
    return 0;

}