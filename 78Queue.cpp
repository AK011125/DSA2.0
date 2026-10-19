#include<iostream>
#include<queue> //queue
#include<deque> //deque -> double ended queue
using namespace std;

class Node{
public:
    int data;
    Node* next;

    Node(int val){
        data = val;
        next = NULL;
    }

};

class Queue{
    Node* head;
    Node* tail;

public:
    Queue(){
        head = tail = NULL;
    }

    bool empty(){
        return head == NULL;
    }

    void push(int data){
        Node* newNode = new Node(data);

        if(empty()){
            head = tail = newNode;
        }else{
            tail-> next = newNode;
            tail = newNode;
        }
    }

    void pop(){
        if(empty()){
            cout<<"LL is empty \n";
            return;
        }

        Node* temp = head;
        head = head->next;
        delete temp;
    }

    int front(){
        if(empty()){
            cout<<"LL is empty \n";
            return -1;
        }
        return head->data;
    }
};

int main(){
    Queue q;

    q.push(1);
    q.push(2);
    q.push(3);

    while(!q.empty()){
        cout<<q.front() << " ";
        q.pop();
    }

    cout<< endl;

    queue<int> q1; //STL

    q1.push(10);
    q1.push(20);
    q1.push(30);

    while(!q1.empty()){
        cout<<q1.front() << " ";
        q1.pop();
    }

    cout<<endl;

    deque<int> dq;

    dq.push_back(11); //11
    dq.push_back(22); //11,22
    dq.push_back(33); //11,22,33

    dq.push_front(10); //10,11,22,33

    dq.pop_back(); //10,11,22,
    cout<<dq.front()<<" "<< dq.back()<<endl; //10 22

    return 0;
}