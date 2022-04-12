#include<iostream>
#include<vector>
using namespace std;

vector<int> searchRange(vector<int>& nums, int target) {
        int start = 0, end = nums.size()-1;
        vector<int> res{-1, -1};
        while(start <= end){
            int mid = start + (end-start)/2;
            if(nums[mid] == target){
                res[0] = mid;
                end = mid-1;
            }
            else if(nums[mid] < target)
                start = mid + 1;
            else
                end = mid-1;
        }
        start = 0, end = nums.size()-1;
        while(start <= end){
            int mid = start + (end-start)/2;
            if(nums[mid] == target){
                res[1] = mid;
                start = mid+1;
            }
            else if(nums[mid] < target)
                start = mid+1;
            else
                end = mid-1;
        }
        return res;
    }

int main() {
    int m, target;
    cin >> m;
    vector<int>a(m);
    for(int i = 0; i < m; i++)
        cin >> a[i];
    cin >> target;
    cout << searchRange(a, target);
}
