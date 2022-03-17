#include<iostream>
#include<vector>
using namespace std;

void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        for(int i = 0; i < n; i++)
            for(int j = i; j < n; j++)
                swap(matrix[i][j], matrix[j][i]);
        for(int i = 0; i < n; i++)
            for(int j = 0; j < (n/2); j++)
                swap(matrix[i][j], matrix[i][n-1-j]);
}

int main(){
    int n, ele;
    cin >> n;
    vector<vector<int>> m;
    for(int i = 0; i < n; i++){
        vector<int>arr;
        for(int j = 0; j < n; j++) {
            cin >> ele;
            arr.push_back(ele);
        }
        m.push_back(arr);
    }
    rotate(m);
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++)
            cout << m[i][j] << " ";
        cout << "\n";
    }
}
