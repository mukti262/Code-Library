#include<iostream>
#include<vector>
using namespace std;

int findLength(vector<int>& A, vector<int>& B) {
        int m = A.size();
        int n = B.size();
        int t[m+1][n+1];
        for(int i = 0; i <= m; i++)
            t[i][0] = 0;
        for(int j = 1; j <= n; j++)
            t[0][j] = 0;
        int res = 0;
        for(int i = 1; i <= m; i++){
            for(int j = 1; j <= n; j++){
                if(A[i-1] == B[j-1])
                    t[i][j] = 1+t[i-1][j-1];
                else
                    t[i][j] = 0;
                res = max(res, t[i][j]);
            }
        }
       return res;
}

int main() {
    int m, n;
    cin >> m >> n;
    vector<int>a(m);
    vector<int>b(n);
    for(int i = 0; i < m; i++)
        cin >> a[i];
    for(int i = 0; i < n; i++)
        cin >> b[i];
    cout << findLength(a, b);
}
