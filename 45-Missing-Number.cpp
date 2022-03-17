#include<iostream>
#include<vector>
using namespace std;

int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int sum = (n+1)*(n)/2;
        int sum_arr = 0;
        for(int i = 0; i < n; i++)
            sum_arr += nums[i];
        return sum-sum_arr;
}

int main() {
    int n;
    cin >> n;
    vector<int>p(n);
    for(int i = 0; i < n; i++)
        cin >> p[i];
    cout << missingNumber(p);
}
