#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    int largestRectangleArea(vector<int>& height){
        int n = height.size();
        stack<int> st;
        int maxArea = 0;
        int i = 0;

        while(i<n){
            if(st.empty() || height[st.top()]<height[i]){
                st.push(i++);
            }else{
                int tp = st.top(); st.pop();
                int width = st.empty() ? i : i-st.top() - 1;
                int area = height[tp] * width;
                maxArea = max(maxArea,area);
            }
        }
        while(!st.empty()){
            int tp = st.top(); st.pop();
            int width = st.empty() ? i : i-st.top() - 1;
            int area = height[tp] * width;
            maxArea = max(maxArea,area);
        }

        return maxArea;
    }

    int maximalRectangle(vector<vector<char>>& matrix) {
        if(matrix.size() == 0) return 0;
        int n = matrix.size();
        int m = matrix[0].size();
        vector<int> height(m,0);
        int maxArea = 0;
        for(int i = 0;i<n;i++){
            for(int j = 0;j<m;j++){
                if(matrix[i][j] == '1'){
                    height[j]++;
                }
                else{
                    height[j] = 0;
                }
            }
            maxArea = max(maxArea,largestRectangleArea(height));
        }


        return maxArea;

    }
};

int main() {
    vector<vector<char>> matrix = {{'1','0','1','0','0'},{'1','0','1','1','1'},{'1','1','1','1','1'},{'1','0','0','1','0'}};
    Solution s;
    cout<<"The largest rectangle form by 1 is : "<<s.maximalRectangle(matrix);
    return 0;
}
