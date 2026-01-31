#include<iostream>
#include<climits>
using namespace std;

// using recursion only 
 int minCoins(vector<int> coins, int x){
    if(x == 0 ) return 0;
    if(x < 0 ) return INT_MAX;

    int mini = INT_MAX;
    for(int i = 0;i<coins.size();i++){
        int ans = minCoins(coins, x-coins[i]);
        if(ans != INT_MAX) mini = min(mini,1 + ans);
    }
    return mini;
}


 int main(){

 }