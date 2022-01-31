#include<iostream>
using namespace std;

bool subsetSum(int arr[], int sum, int n){
    bool t[n+1][sum+1];

    for(int i = 0; i <= n; i++)
        t[i][0] = true;
    for(int j = 1; j <= sum; j++)
        t[0][j] = false;

    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= sum; j++){
            if(arr[i-1] <= j)
                t[i][j] = t[i-1][j-arr[i-1]] || t[i-1][j];
            else
                t[i][j] = t[i-1][j];
    }
    return t[n][sum];
}

int main(){
    int arr[] = {2, 3, 5, 8, 10};
    int sum = 11;
    cout << subsetSum(arr, sum, 5);
}

