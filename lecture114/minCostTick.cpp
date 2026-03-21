#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;

int mincostTickets(vector<int>& days, vector<int>& cost) {
    queue<pair<int,int>> weekly, monthly;
    int ans = 0;

    for(int day : days) {

        // remove expired weekly passes
        while(!weekly.empty() && weekly.front().first + 7 <= day)
            weekly.pop();

        // remove expired monthly passes
        while(!monthly.empty() && monthly.front().first + 30 <= day)
            monthly.pop();

        // add new passes
        weekly.push({day, ans + cost[1]});
        monthly.push({day, ans + cost[2]});

        // choose minimum cost
        ans = min({
            ans + cost[0],
            weekly.front().second,
            monthly.front().second
        });
    }

    return ans;
}

int main(){
    vector<int>days = {1,4,6,7,8,20,25};
    vector<int>costs = {2,7,15};
    cout<<mincostTickets(days,costs)<<endl;
}