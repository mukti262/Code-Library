#include<iostream>
#include<vector>
using namespace std;

vector<vector<int>> generatePT(int numRows) {
        vector<vector<int>>ans;
        ans.push_back({1});

        for(int i = 1; i < numRows; i++) {
            vector<int>v;
            v.push_back(1);
            for(int j = 1; j < i; j++) {
                int num = i, den = i-j;
                unsigned long long int resnum = 1, resden = 1;
                for(int k = 1; k <= den; k++){
                    resnum = resnum*(num--);
                    resnum = resnum/k;
                }
                v.push_back(resnum);
            }
            v.push_back(1);
            ans.push_back(v);
        }

        return ans;
}

int main() {
    int row;
    cin >> row;
    vector<vector<int>> m = generatePT(row);
    for(int i = 0; i < row; i++){
        for(int j = 0; j < row; j++)
            cout << m[i][j] << " ";
        cout << "\n";
    }
}
