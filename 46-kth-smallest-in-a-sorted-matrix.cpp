#include<iostream>
#include<vector>
using namespace std;

int kthSmallest(vector<vector<int>>& matrix, int k) {
        priority_queue<int> h1;
        priority_queue<int> h2;
        for(auto i : matrix){
            for(auto j : i){
                h1.push(j);
                if(h1.size() > k)
                    h1.pop();
            }
        }
        int n = matrix.size();
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                h2.push(matrix[j][i]);
                if(h2.size() > k)
                    h2.pop();
            }
        }
        return max(h1.top(), h2.top());
}

int main() {
    int n, k;
    cin >> n >> k;
    vector<vector<int>>m;
    for(int i = 0; i < n; i++) {
        vector<int>arr(n);
        for(int j = 0; j < n; j++) {
            cin >> arr[j];
        }
        m.push_back(arr);
    }
    cout << kthSmallest(m, k);
}
