#include<iostream>
#include<vector>
using namespace std;

bool solve(vector<vector<char>>& board, string& word, int a, int i, int j, int len){
        if(a == len) return true;
        if(i < 0 || j < 0 || i >= n || j >= m || board[i][j] != word[a])
            return false;
        char x = board[i][j];
        board[i][j] = ' ';
        if(solve(board, word, a+1, i-1, j, len) || solve(board, word, a+1, i+1, j, len) || solve(board, word, a+1, i, j-1, len) || solve(board, word, a+1, i, j+1, len))
            return true;
        board[i][j] = x;
        return false;
}

bool exist(vector<vector<char>>& board, string& word) {
        n = board.size();
        m = board[0].size();
        int len = word.length();
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(word[0] == board[i][j] && solve(board, word, 0, i, j, len))
                    return true;
            }
        }
        return false;
}

int main() {
    int m, n;
    cin >> m >> n;
    char c;
    vector<vector<char>> board;
    for(int i = 0; i < m; i++) {
        vector<char>temp;
        for(int j = 0; j < n; j++) {
            cin >> c;
            temp.push_back(c);
        }
        board.push_back(temp);
    }
    cout << exist(board);
}
