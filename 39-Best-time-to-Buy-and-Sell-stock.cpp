#include<iostream>
#include<vector>
using namespace std;

int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if(n <= 1) return 0;
        int left[n], right[n];
        left[0] = prices[0];
        right[n-1] = prices[n-1];
        for(int i = 1; i < n; i++)
            left[i] = min(left[i-1], prices[i]);
        for(int i = n-2; i >= 0; i--)
            right[i] = max(right[i+1], prices[i]);
        int mx = 0;
        for(int i = 0; i < n; i++)
            mx = max(mx, right[i]-left[i]);
        return mx;
}

int main() {
    int n;
    cin >> n;
    vector<int>p(n);
    for(int i = 0; i < n; i++)
        cin >> p[i];
    cout << maxProfit(p);
}
