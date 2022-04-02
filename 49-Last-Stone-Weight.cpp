#include<iostream>
#include<vector>
using namespace std;

int lastStoneWeight(vector<int>& stones) {
        priority_queue<int>maxh;
        for(auto i : stones)
            maxh.push(i);
        while(maxh.size() > 1){
            int p = maxh.top();
            maxh.pop();
            int q = maxh.top();
            maxh.pop();
            int r = p-q;
            if(r > 0)
                maxh.push(r);
        }
        if(maxh.size() == 1)
            return maxh.top();
        return 0;
}

int main() {
    int n;
    cin >> n;
    vector<int>arr(n);
    for(int i = 0; i < n; i++)
        cin >> arr[i];
    cout << lastStoneWeight(arr);
}
