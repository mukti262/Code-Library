#include<iostream>
#include<vector>
using namespace std;

void permute(vector<int>& nums) {
        vector<vector<int>> res;
        solve(res, nums, 0, nums.size());
        for(auto i: res){
            for(auto j: i)
                cout << j << " ";
            cout << "\n";
        }
}

void solve(vector<vector<int>>& res, vector<int>& nums, int l, int r){
        if(l >= r)
            res.push_back(nums);
        for(int i = l; i < r; i++){
            swap(nums[l], nums[i]);
            solve(res, nums, l+1, r);
            swap(nums[l], nums[i]);
        }
}

int main() {
    int m;
    cin >> m;
    vector<int>a(m);
    for(int i = 0; i < m; i++)
        cin >> a[i];
    cout << permute(a);
}


