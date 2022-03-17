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
    int n;
    cin >> n;
    vector<int>p(n);
    for(int i = 0; i < n; i++)
        cin >> p[i];
    cout << singleNumber(p);
}
