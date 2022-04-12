#include<iostream>
#include<vector>
using namespace std;

int singleNumber(vector<int>& nums) {
        int res = 0;
        for(int i : nums)
            res = res ^ i;
        return res;
}

int main() {
    int m;
    cin >> m;
    vector<int>a(m);
    for(int i = 0; i < m; i++)
        cin >> a[i];
    cout << singleNumber(a);
}
