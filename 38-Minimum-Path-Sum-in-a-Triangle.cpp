#include<iostream>
#include<vector>
using namespace std;

int minimumTotal(vector<vector<int>> t) {
        int m = t.size();
        int n = t[0].size();
        for(int i = m-2; i >= 0; i--)
            for(int j = 0; j <= i; j++)
                t[i][j] = t[i][j] + min(t[i+1][j], t[i+1][j+1]);
        return t[0][0];
}

int main() {
    vector<vector<int>> t;
    int n, j = 1, ele;
    cin >> n;
    for(int i = 0; i < n; i++) {
        vector<int>a;
        for(int k = 0; k < j; k++){
            cin >> ele;
            a.push_back(ele);
        }
        t.push_back(a);
        j++;
    }
    cout << minimumTotal(t);
}
