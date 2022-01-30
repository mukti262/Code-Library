#include<iostream>
#include<vector>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int>a(n+1, 0);
    a[0] = 1;
    for(int i = 3; i <= n; i++)
        a[i] += a[i-3];
    for(int i = 5; i <= n; i++)
        a[i] += a[i-5];
    for(int i = 10; i <= n; i++)
        a[i] += a[i-10];
    cout << a[n];
}
