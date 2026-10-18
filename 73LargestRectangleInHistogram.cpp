#include<iostream>
using namespace std;
//LC 84
//O(n)
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector<int> left(n,0); // left smaller nearest
        vector<int> right(n,0); // right smaller nearest
        stack<int> s;

        //right smaller
        for(int i=n-1; i>=0; i--){
            while(s.size() > 0 && heights[s.top()] >= heights[i]){
                s.pop();
            }

            right[i] = s.empty() ? n : s.top();
            s.push(i);
        }

        while(!s.empty()){
            s.pop();
        }

        //left smaller
        for(int i=0; i<n; i++){
            while(s.size() > 0 && heights[s.top()] >= heights[i]){
                s.pop();
            }

            left[i] = s.empty() ? -1 : s.top();
            s.push(i);
        }

        int ans = 0;
        for(int i =0; i< n; i++){
            int width = right[i] - left[i] -1;
            int currArea = heights[i] * width;
            ans = max(ans, currArea);
        }

        return ans;
    }
};

int main(){
    vector<int> heights = {2,1,5,6,2,3};

    Solution s;

    int ans;
    ans = s.largestRectangleArea(heights);

    cout<<"Largest Rectangle Area : "<<ans<<endl;

    return 0;
}