#include<iostream>
using namespace std;
int main(){
    //span -> the span for a given day is the maximum number of consecutive days 
    // right before (and including) that day for which the stock price was less 
    // than or equal to the price on the current day.
    
    //O(n)
    //stock prices
    vector<int> price = {100,80,60,70,60,75,85};

    //soln
    vector<int> ans(price.size(), 0);
    stack<int> s;

    for(int i=0; i<price.size(); i++){
        while(s.size() > 0 && price[s.top()] <= price[i]){
            s.pop();
        }

        if(s.empty()){
            ans[i] = i + 1;
        } else {
            ans[i] = i - s.top(); // i - prevHigh
        }

        s.push(i);
    }

    //print ans vals
    for(int val : ans){
        cout<< val << " ";
    }

    cout<< endl;

    return 0;
}