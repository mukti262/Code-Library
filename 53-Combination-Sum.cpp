#include<iostream>
#include<vector>
using namespace std;

void solve(vector<vector<int>>& res, vector<int> v, vector<int> c, int target, int index){
        if(target == 0){
            res.push_back(v);
            return;
        }
        for(int i = index; i < c.size(); i++){
            if(c[i] > target)
                break;
            v.push_back(c[i]);
            solve(res, v, c, target-c[i], i);
            v.pop_back();
        }
    }

vector<vector<int>> combinationSum(vector<int>& c, int target) {
        int n = c.size();
        vector<vector<int>> res;
        if(n == 0) return res;
        sort(c.begin(), c.end());
        vector<int> v;
        solve(res, v, c, target, 0);
        return res;
}

int main() {
    int m, target;
    cin >> m;
    vector<int>a(m);
    for(int i = 0; i < m; i++)
        cin >> a[i];
    cin >> target;
    cout << combinationSum(a, target);
}
