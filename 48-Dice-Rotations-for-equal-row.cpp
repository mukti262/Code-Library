#include<iostream>
#include<vector>
using namespace std;

int minDominoRotations(vector<int>& A, vector<int>& B) {
        int n = A.size();
        vector<int> countA(7, 0);
        vector<int> countB(7, 0);
        vector<int> common(7, 0);
        for(int i = 0; i < n; i++){
            countA[A[i]]++;
            countB[B[i]]++;
            if(A[i] == B[i]) common[A[i]]++;
        }
        for(int i = 0; i < 7; i++){
            if(countA[i] + countB[i] - common[i] == n)
                return n-max(countA[i], countB[i]);
        }
        return -1;
}

int main() {
    int n;
    cin >> n;
    vector<int>a(n);
    vector<int>b(n);
    for(int i = 0; i < n; i++)
        cin >> a[i];
    for(int i = 0; i < n; i++)
        cin >> b[i];
    cout << minDominoRotations(a, b);
}
