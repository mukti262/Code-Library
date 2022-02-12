#include<iostream>
#include<vector>
using namespace std;

void Sort(vector<int>& v){
    int n = v.size();
    int c0 = 0; int c1 = 0; int c2 = 0;
    for(int i = 0; i < n; i++){
        if(v[i] == 0) c0++;
        else if(v[i] == 1) c1++;
        else if(v[i] == 2) c2++;
    }
    int i = 0;
    while(c0--) v[i++] = 0;
    while(c1--) v[i++] = 1;
    while(c2--) v[i++] = 2;
}

int main(){
    vector<int> v = {1,2,0,0,1,2,2,1,1,2,0};
    Sort(v);
    for(int i : v)
        cout << i << " ";
}

