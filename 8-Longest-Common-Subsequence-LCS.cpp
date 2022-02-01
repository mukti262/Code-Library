#include<iostream>
#include<algorithm>
using namespace std;

int main() {
    string s1, s2;
    cin >> s1 >> s2;
    int m = s1.length();
    int n = s2.length();
    int t[m+1][n+1];

    for(int i = 0; i <= m; i++)
        t[i][0] = 0;
    for(int j = 0; j <= n; j++)
        t[0][j] = 0;

    for(int i = 1; i <= m; i++) {
        for(int j = 1; j <= n; j++) {
            if(s1[i-1] == s2[j-1])
                t[i][j] = 1 + t[i-1][j-1];
            else
                t[i][j] = max(t[i-1][j], t[i][j-1]);
        }
    }

    cout << t[m][n] << "\n";

    string ans = "";
    int i = m, j = n;
    while(i > 0 && j > 0) {
        if(s1[i-1] == s2[j-1]){
            ans.push_back(s1[i-1]);
            i--; j--;
        }
        else if(t[i-1][j] > t[i][j-1])
            i--;
        else
            j--;
    }

    reverse(ans.begin(), ans.end());
    cout << ans;
}
