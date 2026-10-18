#include<iostream>
#include<list>
#include<stack>
using namespace std;

class Stack1{
    vector<int> v; //using vector

    public:
    void push(int val){ //O(1)
        v.push_back(val);
    }

    void pop(){ //O(1)
        v.pop_back();
    }

    int top(){ //O(1)
        return v[v.size()-1];
    }

    bool empty(){
        return v.size() == 0;
    }

};

class Stack2{
    list <int> ll; //using ll

    public:
    void push(int val){ //O(1)
        ll.push_front(val);
    }

    void pop(){ //O(1)
        ll.pop_front();
    }

    int top(){ //O(1)
        return ll.front();
    }

    bool empty(){
        return ll.size() == 0;
    }

};

int main(){
    Stack2 s;

    s.push(1);
    s.push(2);
    s.push(3);

    while(!s.empty()){
        cout<<s.top()<<" ";
        s.pop();
    }

    cout<<endl;

    stack<int> S; //using stl
    s.push(10);
    s.push(20);
    s.push(30);

    while(!s.empty()){
        cout<<s.top()<<" ";
        s.pop();
    }

    return 0;
}