#include<iostream>
#include<vector>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int>t(n+1, 0);

    for(int i = 2; i <= n; i++) {
        for(int j = 1; j <= i/2; j++) {
            t[i] = max(t[i], max(j*(i-j), j*t[i-j]));
        }
    }
    cout << t[n];
}
