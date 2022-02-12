#include<iostream>
using namespace std;

int main(){
    int a[] = {1,2,3,4,5};
    int n = sizeof(a)/sizeof(int);
    for(int i = 0; i <= n-2; i++){
        swap(a[i], a[n-1]);
    }
    for(int i=0; i < n; i++)
        cout << a[i] << " ";
}

