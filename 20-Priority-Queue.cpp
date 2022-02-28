#include<iostream>
#include<queue>
using namespace std;

void show(priority_queue <int> q){
    priority_queue <int> pq = q;
    while(!pq.empty()){
        cout << pq.top() << " ";
        pq.pop();
    }
    cout << endl;
}
int main(){
    priority_queue <int> q;
    q.push(10);
    q.push(5);
    q.push(9);
    show(q);

    cout << "size " << q.size();
}
