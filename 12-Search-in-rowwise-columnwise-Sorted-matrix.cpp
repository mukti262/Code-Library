#include<iostream>
#include<vector>
using namespace std;

int main(){
    int m, n;
    cin >> m >> n;
    vector<vector<int>>mat(m, vector<int>(n));
    for(int i = 0; i < m; i++)
        for(int j = 0; j < n; j++)
            cin >> mat[i][j];
    int target;
    cin >> target;
    int i = 0, j = n-1;
    bool found = false;
    while(i < m && j >= 0){
        if(mat[i][j] == target){
            found = true;
            cout << target << " exists!";
            break;
        }
        else if(mat[i][j] < target)
            i++;
        else
            j--;
    }
    if(!found) cout << target << " does not exists!";
}

