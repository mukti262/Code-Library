#include<iostream>
#include<vector>
using namespace std;

bool isSafe(int row, int col, int n, vector<string>&sol){
        for(int i = 0; i < col; i++){
            if(sol[row][i] != '.')
                return false;
        }
        for(int i = row, j = col; i >= 0 && j >= 0; i--, j--){
            if(sol[i][j] != '.')
                return false;
        }
        for(int i = row, j = col; i < n && j >= 0; i++, j--){
            if(sol[i][j] != '.')
                return false;
        }
        return true;
    }
    void solve(vector<string>&sol, vector<vector<string>>& res, int col, int n){
        if(col == n){
            res.push_back(sol);
        }
        for(int ro = 0; ro < n; ro++)
            if(isSafe(ro, col, n, sol)){
                sol[ro][col] = 'Q';
                solve(sol, res, col+1, n);
                sol[ro][col] = '.';
            }
}

void solveNQueens(int n) {
        vector<vector<string>> res;
        vector<string>sol(n, string(n, '.'));
        solve(sol, res, 0, n);
        for(auto i: res){
            for(auto j: i)
                cout << j << " ";
            cout << "\n";
        }
}

int main() {
    int n;
    cin >> n;
    solveNQueens(n);
}


