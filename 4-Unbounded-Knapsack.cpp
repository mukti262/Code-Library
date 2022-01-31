#include<iostream>
using namespace std;

int knapsack(int wt[], int val[], int w, int n){
    int t[n+1][w+1];
    for(int i = 0; i <= n; i++)
        t[i][0] = 0;
    for(int j = 1; j <= w; j++)
        t[0][j] = 0;

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= w; j++){
            if(wt[i-1] <= j)
                t[i][j] = max(val[i-1] + t[i][j-wt[i-1]], t[i-1][j]);
            else
                t[i][j] = t[i-1][j];
        }
    }
    return t[n][w];
}

int main(){
    int wt[] = {1,3,4,5};
    int val[] = {3,4,5,7};
    int w = 7;
    int n = sizeof(wt)/sizeof(wt[0]);
    cout << knapsack(wt, val, w, n);
}

