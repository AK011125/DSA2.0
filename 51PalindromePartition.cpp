#include<iostream>
using namespace std;
//LC 131
// O(n* 2^n)

bool isPalin(string s){
    string s2 = s;
    reverse(s2.begin(), s2.end());

    return s2 == s;
}

void getAllParts(string s,vector<string> &partitions, vector<vector<string>> &ans){

    if(s.size() == 0){
        ans.push_back(partitions);
        return;
    }

    for(int i=0; i< s.size(); i++){
        string part = s.substr(0, i+1);

        if(isPalin(part)){
            partitions.push_back(part);
            getAllParts(s.substr(i+1), partitions, ans);
            partitions.pop_back();
        }
    }
}

vector<vector<string>> partition(string s){
    vector<vector<string>> ans;
    vector<string> partitions;

    getAllParts(s, partitions, ans);
    return ans;
}


int main() {
    string s = "aab";

    vector<vector<string>> ans = partition(s);

    cout << "Palindrome partitions are:\n";

    for (int i = 0; i < ans.size(); i++) {
        cout << "[ ";
        for (int j = 0; j < ans[i].size(); j++) {
            cout << "\"" << ans[i][j] << "\" ";
        }
        cout << "]\n";
    }

    return 0;
}