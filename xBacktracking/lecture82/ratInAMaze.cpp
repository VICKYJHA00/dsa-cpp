// day 1 of backtracking from a love babbar series
// today we gonna do a rat in maze problem
#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;
// THE maze is square;

bool isSafe(int x, int y, vector<vector<bool>> &vis, vector<vector<int>> &arr,int n){
    if( (x >= 0 && x<n) && (y>=0 && y<n) && (vis[x][y] == 0) && (arr[x][y] == 1)
    ){
        return true;
    }
    else return false;
}

void solve(int x, int y ,vector<vector<int>> &arr,int n, vector<string> &ans, vector<vector<bool>> &vis, string path){

    // base case
    if(x == n-1 && y == n-1){
        ans.push_back(path);
        return;
    }

    //4 movements
    // D L R U

    // DOWN
    vis[x][y] = true;

    if(isSafe(x+1,y,vis,arr,n)){
        solve(x+1,y,arr,n,ans,vis,path+'D');
    }

    // LEFT
    if(isSafe(x,y-1,vis,arr,n)){
        solve(x,y-1,arr,n,ans,vis,path+'L');
    }

    // RIGHT
    if(isSafe(x,y+1,vis,arr,n)){
        solve(x,y+1,arr,n,ans,vis,path+'R');
    }

    // UP
    if(isSafe(x-1,y,vis,arr,n)){
        solve(x-1,y,arr,n,ans,vis,path+'U');
    }

    vis[x][y] = false;
}

vector<string> searchMaze(vector<vector<int>> & arr,int n)
{
    vector<string> ans;
    vector<vector<bool>> visited(n,vector<bool> (n,0));
    string path = "";
    if( arr.empty() ||arr[0][0] == 0 ) return ans;

    solve(0,0,arr,n,ans,visited,path);

    return ans;

}

int main(){
    vector<vector<int>> arr = {
        {1,0,0,0},
        {1,1,0,0},
        {1,1,0,0},
        {0,1,1,1}
    };

    vector<string> paths = searchMaze(arr,(int)arr.size());

    if(paths.empty()){
        cout << "-1\n";
    } else {
        for(const string &p : paths){
            cout << p << " ";
        }
        cout << "\n";
    }
    return 0;


}