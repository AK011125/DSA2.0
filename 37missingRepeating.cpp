#include<iostream>
#include<unordered_set>
using namespace std;
//LC 2965
vector<int> missingRepeatingvalue(vector<vector<int>>&grid){
    vector<int> ans;
    unordered_set<int> s;
    int n = grid.size();
    int a, b;

    int expSum = 0, actualSum = 0;

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            actualSum += grid[i][j];

            if(s.find(grid[i][j]) != s.end()){
                a = grid[i][j];
                ans.push_back(a);

            }
            s.insert(grid[i][j]);
        }
    }

    expSum = (n*n)*(n*n+1)/2;
    b = expSum + a - actualSum;
    ans.push_back(b);

    return ans;

}

int main(){
    vector<vector<int>> grid = {{1,3},{2,2}};

    vector<int> ans;
    ans = missingRepeatingvalue(grid);

    for(int i = 0; i< ans.size();i++){
        cout<<ans[i]<<" ";
    }
    return 0;
}