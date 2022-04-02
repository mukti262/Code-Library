#include<iostream>
#include<vector>
using namespace std;

void solve(vector<vector<int>>& image, vector<vector<bool>>visited,int i, int j, int x, int newColor, int X, int Y){
        visited[i][j] = true;
        if(i-1 >= 0 && !visited[i-1][j] && image[i-1][j] == x)
            solve(image, visited, i-1, j, x, newColor, X, Y);
        if(j-1 >= 0 && !visited[i][j-1] && image[i][j-1] == x)
            solve(image, visited, i, j-1, x, newColor, X, Y);
        if(i+1 < X && !visited[i+1][j] && image[i+1][j] == x)
            solve(image, visited, i+1, j, x, newColor, X, Y);
        if(j+1 < Y && !visited[i][j+1] && image[i][j+1] == x)
            solve(image, visited, i, j+1, x, newColor, X, Y);
        image[i][j] = newColor;
}

vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        int i = image.size();
        int j = image[0].size();
        vector<vector<bool>>visited(i, vector<bool>(j, false));
        if(image[sr][sc] != newColor) solve(image, visited, sr, sc, image[sr][sc], newColor, i, j);
        return image;
}

int main() {
    int m, n, sr, sc, newColor;
    cin >> m >> n >> sr >> sc >> newColor;
    vector<vector<int>>arr;
    for(int i = 0; i < m; i++) {
        vector<int>a(n);
        for(int j = 0; j < n; j++) {
            cin >> a[i];
        }
        arr.push_back(a);
    }
    vector<vector<int>> ff = floodFill(arr, sr, sc, newColor);
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++)
            cout << arr[i][j] << " ";
        cout << "\n";
    }
}
