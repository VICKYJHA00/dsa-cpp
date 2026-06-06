
#include<bits/stdc++.h>
using namespace std;
class solution {
public:
    int maxProfit(vector<int>& prices) {
        int minprice = prices[0];
        int maxprofit = 0;
        for(int price : prices){
            minprice = min(minprice,price);
            maxprofit = max(maxprofit,price-minprice);
        }
        return maxprofit;
    }
};

int main(){
    vector<int> prices = {7,1,5,3,6,4};
    solution s;
    cout<<"The max profit will be : "<<s.maxProfit(prices);
    cout<<endl;

    return 0;
}