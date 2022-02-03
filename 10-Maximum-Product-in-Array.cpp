#include<iostream>
#include<vector>
using namespace std;

int findMaxProduct(vector<int>& a, int n){
    int prev_min_product = a[0];
    int prev_max_product = a[0];
    int ans = a[0];
    int curr_min_product, curr_max_product;
    for(int i = 1; i < n; i++){
        curr_min_product = min(a[i], min(a[i] * prev_min_product, a[i] * prev_max_product));
        curr_max_product = max(a[i], max(a[i] * prev_min_product, a[i] * prev_max_product));
        ans = max(ans, curr_max_product);
        prev_min_product = curr_min_product;
        prev_max_product = curr_max_product;
    }
    return ans;
}

int main(){
    vector<int> a;
    int n, x;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> x;
        a.push_back(x);
    }
    cout << findMaxProduct(a, n);
}

