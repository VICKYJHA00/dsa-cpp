#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Memorization{
    public:
    int solve(vector<int>& days, vector<int>& costs,int n , vector<int>& dp){
        if(n>=days.size()) return 0;

        if(dp[n] != -1) return dp[n];

        int opt1 = costs[0] + solve(days,costs,n+1,dp);
        int i = n;
        while(i<days.size() && days[i] < days[n]+7) i++;
        int opt2 = costs[1] + solve(days,costs,i,dp);

        i = n;
        while(i<days.size() && days[i] < days[n]+30) i++;
        int opt3 = costs[2] + solve(days,costs,i,dp);

        return dp[n] = min(opt1,min(opt2,opt3));
    }
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int n = days.size();
        vector<int>dp(n+1, -1);
        return solve(days,costs,0,dp);
    }
};

class Solution1{
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int n = days.size();
        vector<int>dp(n+1,-1);
        dp[n] = 0;
        for(int i = n-1;i>=0;i--){
            int opt1 = costs[0] + dp[i+1];
            int j = i;
            while(j<n && days[j] < days[i]+ 7) j++;
            int opt2 = costs[1] + dp[j];

            j = i;
            while(j<n && days[j]< days[i]+ 30) j++;
            int opt3 = costs[2] + dp[j];
            dp[i] = min(opt1,min(opt2,opt3));
        }
        return dp[0];
    }
};

int main(){
    vector<int>days = {1,4,6,7,8,20};
    vector<int>costs = {2,7,15};
    Solution1 s;
    cout<<s.mincostTickets(days,costs)<<endl;
    Memorization m; 
    cout<<m.mincostTickets(days,costs)<<endl;
}