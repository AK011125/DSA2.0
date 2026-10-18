#include<iostream>
using namespace std;
//LC 504
//O(n)
class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans (n,-1);
        stack<int> s;

        for(int i = 2*n-1; i>=0; i--){
            while(s.size() > 0 && nums[s.top()] <= nums[i%n]){
                s.pop();
            }

            ans[i%n] = s.empty() ? -1 : nums[s.top()];
            s.push(i%n);
        }

        return ans;
    }
};

int main(){
    vector<int> nums = {1,2,3,4,3};
    Solution s;

    vector<int> ans;
    ans = s.nextGreaterElements(nums);

    for(int i= 0; i< ans.size(); i++){
        cout<<ans[i]<<" ";
    }

    return 0;
}