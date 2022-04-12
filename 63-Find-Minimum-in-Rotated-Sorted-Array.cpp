#include<iostream>
#include<vector>
using namespace std;

int findMin(vector<int>& nums) {
        int n = nums.size();
        int start = 0, end = n-1;
        while(start <= end){
            if(nums[start] <= nums[end])
                return nums[start];
            int mid = start + (end-start)/2;
            int prev = (mid -1 + n)%  n;
            int next = (mid +1) % n;
            if(nums[mid] < nums[prev] && nums[mid] < nums[next])
                return nums[mid];
            else if(nums[start] <= nums[mid])
                start = mid+1;
            else if(nums[mid] <= nums[end])
                end = mid-1;
        }
        return -1;
}

int main() {
    int m;
    cin >> m;
    vector<int>a(m);
    for(int i = 0; i < m; i++)
        cin >> a[i];
    cout << findMin(a);
}
