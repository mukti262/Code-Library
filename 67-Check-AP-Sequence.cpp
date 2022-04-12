#include<bits/stdc++.h>
using namespace std;

// Returns true if a permutation of arr[0..n-1]
// can form arithmetic progression
bool checkIsAP(int arr[], int n)
{
  if (n == 1)
    return true;

  // Sort array
  sort(arr, arr + n);

  // After sorting, difference between
  // consecutive elements must be same.
  int d = arr[1] - arr[0];
  for (int i=2; i<n; i++)
    if (arr[i] - arr[i-1] != d)
      return false;

  return true;
}

// Driven Program
int main()
{
  int arr[] = { 20, 15, 5, 0, 10 };
  int n = sizeof(arr)/sizeof(arr[0]);

  (checkIsAP(arr, n))? (cout << "Yes" << endl) :
                       (cout << "No" << endl);

  return 0;
}
