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


int main() {
    
    return 0;
}
