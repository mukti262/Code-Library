#include<iostream>
#include<vector>
using namespace std;

int twoCitySchedCost(vector<vector<int>>& costs) {
        vector<pair<int, int>> v;
        int n = costs.size();
        for(int i = 0; i < n; i++)
            v.push_back({costs[i][0]-costs[i][1], i});
        sort(v.begin(), v.end());
        vector<pair<int, int>> :: iterator it = v.begin();
        int sum = 0;
        for(int i = 0; i < (n/2); i++){
            sum += costs[it->second][0];
            it++;
        }
        for(int i = (n/2); i < n; i++){
            sum += costs[it->second][1];
            it++;
        }
        return sum;
}

int main() {
    int n;
    cin >> n;
    vector<vector<int>>m;
    for(int i = 0; i < n; i++) {
        vector<int>arr(2);
        for(int j = 0; j < 2; j++)
            cin >> arr[j];
        m.push_back(arr);
    }
    cout << twoCitySchedCost(m);
}
