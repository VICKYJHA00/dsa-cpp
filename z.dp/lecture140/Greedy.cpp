#include <bits/stdc++.h>
using namespace std;
class activitySelection {
  public:
    static bool compare(pair<int,int>& a, pair<int,int>& b){
        return a.second < b.second;
    }
    int activitySelection(vector<int> &start, vector<int> &finish) {
        // code 
        vector<pair<int,int>> meeting;
        for(int i = 0;i<start.size();i++){
           pair<int,int> p = make_pair(start[i],finish[i]);
           meeting.push_back(p);
        }
        sort(meeting.begin(),meeting.end(),compare);
        int count = 1;
        int endMeeting = meeting[0].second;
        for(int i = 1;i<meeting.size();i++){
            if(meeting[i].first > endMeeting){
                count++;
                endMeeting = meeting[i].second;
            }
        }
        return count;
        
    }
};

class minMax {
public:
    vector<int> minMaxCandy(vector<int>& prices, int k) {
        sort(prices.begin(), prices.end());

        int n = prices.size();

        int minCost = 0, maxCost = 0;

        int i = 0, j = n - 1;

        // Minimum cost
        while (i <= j) {
            minCost += prices[i];
            i++;
            j -= k;
        }

        i = 0;
        j = n - 1;

        // Maximum cost
        while (i <= j) {
            maxCost += prices[j];
            j--;
            i += k;
        }

        return {minCost, maxCost};
    }
};

class survivalDays {
  public:
    int minimumDays(int S, int N, int M) {
        // code here
        if(N < M)
            return -1;

        if(S > 6 && 6 * N < 7 * M)
            return -1;
            
        int sunday = S/7;
        int totalDays = S-sunday;
        int ans = 0;
        int totalFood = S*M;
        
        if(totalFood % N == 0){
            ans = totalFood/N;
        }else{
            ans = totalFood/N + 1;
        }
        
         if(ans <= totalDays)
            return ans;
        return -1;
    }
};

class Mincost {
  public:
    int minCost(vector<int>& arr) {
        // code here
         priority_queue<int, vector<int>, greater<int>> pq;
         for(int i =0;i<arr.size();i++){
             pq.push(arr[i]);
         }
         int Mincost = 0;
         while(pq.size()>1){
             int first = pq.top();
             pq.pop();
             int second = pq.top();
             pq.pop();
             int cost = first + second;
             Mincost += cost;
             pq.push(cost);
         }
         
         return Mincost;
    }
};

struct item{
  public:
  int val;
  int wt;
  double ratio;
  item(int v, int w , double r){
      val = v;
      wt = w;
      ratio = r;
  }
};
class cmp{
  public:
  bool operator()(item a, item b){
      return a.ratio > b.ratio;
  }
};
class fractionalKnapstack {
  public:
    double fractionalKnapsack(vector<int>& val, vector<int>& wt, int capacity) {
        // code here
        vector<item> v;
        for(int i = 0;i<wt.size();i++){
            int value = val[i];
            int w = wt[i];
            item temp(value,w, (double)value/w);
            v.push_back(temp);
        }
        
        sort(v.begin(),v.end(),cmp());
        double ans = 0;
        int currweight = 0;
        for(int i =0;i<val.size();i++){
            if(currweight + v[i].wt <= capacity){
                currweight += v[i].wt;
                ans += v[i].val;
            }else{
                int remain = capacity -currweight;
                ans += remain * v[i].ratio;
                break;
                
            }
        }
        
        return ans;
        
    }
};


int main() {
    
    return 0;
}
