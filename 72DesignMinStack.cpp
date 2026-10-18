#include<iostream>
using namespace std;
class MinStack {
public:
stack<pair<int,int>> s; // val, minval
    MinStack() {
        
    }
    
    void push(int value) {
        if(s.empty()){
            s.push({value, value});
        }else{
            int minval = min(value , s.top().second);
            s.push({value, minval});
        }
    }
    
    void pop() {
        s.pop();
    }
    
    int top() {
        return s.top().first;
    }
    
    int getMin() {
        return s.top().second;
    }
};


class MinStack2 {
public:
stack<long long int> s2;
long long int minVal;
    MinStack2() {
        
    }
    
    void push(int value) {
        if(s2.empty()){
            s2.push(value);
            minVal = value;
        }else{
            if(value < minVal){
                s2.push((long long)2*value - minVal);
                minVal = value;
            }else{
                s2.push(value);
            }
        }
    }
    
    void pop() {
        if(s2.top() < minVal){
            minVal = 2 * minVal - s2.top();
        }

        s2.pop();
    }
    
    int top() {
        if(s2.top() < minVal){
            return minVal;
        }
        return s2.top();
    }
    
    int getMin() {
        return minVal;
    }
};


/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(value);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */

 int main(){

    return 0;
 }