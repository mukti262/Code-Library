#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int solve(vector<int>& a, int n, int m){
    if(!m || !n) return 0;
    if(m > n) return -1;
    sort(a.begin(), a.end());
    int diff = 100000;
    for(int i = 0; i <= n-m; i++){
        diff = min(diff, a[i+m-1] - a[i]);
    }
    return diff;
}

int main(){
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    for(int i = 0; i < n; i++)
        cin >> a[i];
    cout << solve(a, n, m);
}

