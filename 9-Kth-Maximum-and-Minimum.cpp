#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

int main(){
    vector<int> v = {3,5,2,4,1};
    int k = 3;
    priority_queue<int> minheap;
    int n = v.size();
    for(int i = 0; i < n; i++){
        minheap.push(v[i]);
        if(minheap.size() > 2){
            minheap.pop();
        }
    }
    cout << k << "th minimum : " << minheap.top() << endl;
    priority_queue<int, vector<int>, greater<int>> maxheap;
    for(int i = 0; i < n; i++){
        maxheap.push(v[i]);
        if(maxheap.size() > 2){
            maxheap.pop();
        }
    }
    cout << k << "th maximum : " << maxheap.top() << endl;
}

