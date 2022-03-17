#include<iostream>
#include<vector>
using namespace std;

int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        if(n == 0) return 0;
        vector<int> right(n), width(n), area(n);
        int left[n];
        stack<pair<int, int>> s, s2;
        for(int i = 0; i < n; i++){
            if(s.size() == 0)
                left[i] = -1;
            else if(s.top().first < heights[i])
                left[i] = s.top().second;
            else{
                while(s.size() > 0 && s.top().first >= heights[i])
                    s.pop();
                if(s.size() == 0)
                    left[i] = -1;
                else
                    left[i] = s.top().second;
            }
            s.push({heights[i], i});
        }
        for(int i = n-1; i >= 0; i--){
            if(s2.size() == 0)
                right.push_back(n);
            else if(s2.top().first < heights[i])
                right.push_back(s2.top().second);
            else{
                while(s2.size() > 0 && s2.top().first >= heights[i])
                    s2.pop();
                if(s2.size() == 0)
                    right.push_back(n);
                else
                    right.push_back(s2.top().second);
            }
            s2.push({heights[i], i});
        }
        reverse(right.begin(), right.end());
        int mx = 0;
        for(int i = 0; i < n; i++){
            width[i] = right[i] - left[i] - 1;
            area[i] = heights[i] * width[i];
            if(area[i] > mx)
                mx = area[i];
        }
        return mx;
    }

int main() {
    int n;
    cin >> n;
    vector<int>arr(n);
    for(int i = 0; i < n; i++)
        cin >> arr[i];
    cout << largestRectangleArea(arr);
}
