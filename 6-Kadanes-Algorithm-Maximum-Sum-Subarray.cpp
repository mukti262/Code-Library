#include<iostream>
#include <vector>
using namespace std;

int arrayMaxConsecutiveSum(vector<int> v){
    int max_sum = v[0];
    int current_sum = max_sum;
    for(int i = 1; i < v.size(); i++){
        current_sum = max(v[i] + current_sum, v[i]);
        max_sum = max(current_sum, max_sum);
    }
    return max_sum;
}

int main(){
    vector<int> v{-2,2,5,-6,7};
    cout << arrayMaxConsecutiveSum(v);
}

