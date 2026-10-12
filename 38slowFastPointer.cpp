#include<iostream>
using namespace std;
// LC 287 {without using extra space}
//Slow fast pointer of LL
//element is nxt node and idx is node
// Slow pointer first move +1 fast moves +2
// when they are equal then reinitialise slow to arr[0]
//then slow will move +1 and fast move +1
//when again both are equal so they will meet at the common node
// which is duplicate which we have to find out

int findDuplicate(vector<int> &arr){
    int slow = arr[0], fast = arr[0];

    do{
        slow = arr[slow]; //+1
        fast = arr[arr[fast]]; // +2
    }while(slow != fast);

    slow = arr[0];

    while(slow != fast){
        slow = arr[slow]; // +1
        fast = arr[fast]; // +1
    }

    return slow;
}

int main(){
    vector <int> v1 = {1,3,2,2};
    vector <int> v2 = {3,1,3,4,2};

    int ans;
    ans = findDuplicate(v2);

    cout<<ans;

    return 0;
}