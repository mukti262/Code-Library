#include<iostream>
#include<vector>
using namespace std;

int searchInsert(vector<int>& nums, int target) {
        return lower_bound(nums.begin(), nums.end(), target)-nums.begin();
}

int main() {
    int m, target;
    cin >> m;
    vector<int>a(m);
    for(int i = 0; i < m; i++)
        cin >> a[i];
    cin >> target;
    cout << searchInsert(a, target);
}
