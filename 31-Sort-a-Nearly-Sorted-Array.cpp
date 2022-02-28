#include<iostream>
#include<queue>
using namespace std;

int main(){
    int arr[] = {6,5,3,2,8,10,9};
    priority_queue<int, vector<int>, greater<int>> minh;
    int k = 3;
    int i = 0;
    int j = 0;
    while(i < 7){
        minh.push(arr[i++]);
        if(minh.size() > k){
            arr[j++] = minh.top();
            minh.pop();
        }
    }
    while(minh.size() >0){
        arr[j++] = minh.top();
        minh.pop();
    }
    for(int i = 0; i < 7; i++)
        cout << arr[i] << " ";
}

