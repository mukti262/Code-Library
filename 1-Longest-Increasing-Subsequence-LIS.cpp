#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int>a(n);
    for(int i = 0; i < n; i++)
        cin >> a[i];
    vector<int>t(n+1, 1);
    for(int i = 1; i < n; i++) {
        for(int j = 0; j < i; j++) {
            if(a[i] > a[j] && t[j]+1 > t[i])
                t[i]++;
        }
    }
    cout << *max_element(t.begin(), t.end());
}
