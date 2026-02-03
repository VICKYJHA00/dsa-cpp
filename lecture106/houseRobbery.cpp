// same as previous question maximum sum of non adjacent elements but the twist is that the first and last elements are considered adjacent

// house robbery problem circular array variation
#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;

// using space optimization
int solve(vector<int> &nums){
    int n = nums.size();
    if (n == 0) return 0;
    if (n == 1) return nums[0];
    int prev2 = 0;
    int prev1 = nums[0];
    for (int i = 1; i < n; ++i) {
        int incl = prev2 + nums[i];
        int excl = prev1;
        int ans = max(incl, excl);
        prev2 = prev1;
        prev1 = ans;
    }
    return prev1;
}

int houseRobbery(vector<int> &nums){
    int n = nums.size();
    if(n ==1) return nums[0];
    vector<int> temp1, temp2;
    for(int i =0;i<n;i++){
        if(i != n-1) temp1.push_back(nums[i]);
        if( i != 0) temp2.push_back(nums[i]);
    }
    return max(solve(temp1),solve(temp2));
}

int main(){
    vector<int> nums = {2,3,2};
    cout<<houseRobbery(nums);
    return 0;
}