#include<iostream>
#include <vector>
using namespace std;

void findLongest(int s, vector<int> v){
    int sum = 0, left = 0, right = 0, li, ri;
    while(right < v.size()){
        sum += v[right];
        while(sum > s && left < right)
            sum -= v[left++];
        if(sum == s && (ri-li) < (right - left)){
            li = left+1;
            ri = right+1;
        }
        right++;
    }
    cout << li << " to " << ri;
}

int main(){
    vector<int> v{1, 2, 3, 4, 5, 0, 0, 5, 9, 1, 0, 0, 0};
    findLongest(15, v);
    return 1;
}
