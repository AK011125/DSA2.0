#include<iostream>
using namespace std;
// total calls * workdone in a call => time complexity
// O(n*2^n)
void printSubset(vector<int> &arr, vector<int> &ans, int i){
    if(i == arr.size()){
        for(int val : ans){
            cout<< val<< " ";
        }
        cout<< endl;
        return;
    }

    //include
    ans.push_back(arr[i]);
    printSubset(arr,ans,i+1);

    ans.pop_back(); //backtrack
    //exclude
    printSubset(arr,ans,i+1);
}


int main(){
    vector<int> arr = {1,2,3};
    vector<int> ans; //store subsets

    printSubset(arr,ans,0);
    return 0;
}