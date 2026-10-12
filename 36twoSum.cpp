#include<iostream>
using namespace std;
//LC 01
vector<int>twoSum(vector<int>&arr,int tar){
    unordered_map<int,int> m;
    vector<int> ans;

    for(int i =0;i<arr.size();i++){
        int first = arr[i];
        int sec = tar - first;

        if(m.find(sec) != m.end()){ // if found so loop run (it give time complexity of constant)
            //if a value is not found in map so it returns m.end()
            
            ans.push_back(i);        //pushback both idx
            ans.push_back(m[sec]);
            break;
        }

        m[first] = i; //if not found so store in map
    }

    return ans;
}

int main(){
    vector<int> v = {2,7,11,15};

    int tar = 9;

    vector<int> result;
    result = twoSum(v,tar);


    for(int i=0;i<result.size();i++){
        cout<<result[i]<<" ";
    }

    return 0;
}