 #include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

 bool check(vector<int>& base, vector<int>& box){
        return 
        base[0]<= box[0] &&
        base[1]<= box[1] &&
        base[2]<= box[2] ;
    }

    int maxHeight(vector<vector<int>>& cuboids) {
        // sort all dimention of the cuboids
        for(auto &a : cuboids){
            sort(a.begin(),a.end());
        }

        // sort cuboids basis on w or length
        sort(cuboids.begin(),cuboids.end());

        int n = cuboids.size();
        vector<int> dp(n,0);
        int maxi = 0;

        for(int i = 0;i<n;i++){
            dp[i] = cuboids[i][2]; // height
            for(int j = 0;j<i;j++){
                if(check(cuboids[j],cuboids[i])){
                    dp[i] = max(dp[i],dp[j] + cuboids[i][2]);
                }
            }
            maxi = max(maxi,dp[i]);
        }

        return maxi;
    }

    vector<vector<int>> cuboids = {{50,45,20},{95,37,53},{45,23,12}};
    cout<<maxHeight(cuboids)<<endl;
    return 0;
}