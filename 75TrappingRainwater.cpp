#include<iostream>
using namespace std;
//LC 42
//O(n)
class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int ans = 0;
        int l = 0, r = n-1;
        int lmax = 0, rmax = 0;

        while(l<r){
            lmax = max(lmax, height[l]);
            rmax = max(rmax, height[r]);

            if(lmax < rmax){
                ans+= lmax - height[l];
                l++;
            }else{
                ans+= rmax - height[r];
                r--;
            }
        }

        return ans;
    }
};

int main(){
    Solution s;

    vector<int> height = {0,1,0,2,1,0,1,3,2,1,2,1};
    vector<int> height2 = {4,2,0,3,2,5};

    int ans = s.trap(height2);
    cout<<ans<<endl;

    return 0;
}