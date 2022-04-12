#include <bits/stdc++.h>
using namespace std;

// Function to find the minimum difference
long long minDist(int* arr, int r, int N,
				long long k)
{
	if (r == N)
		return k;
	else
		return min(abs(minDist(arr, r + 1,
							N, k
									+ arr[r])),
				abs(minDist(arr, r + 1,
							N, k
									- arr[r])));
}

// Driver code
int main()
{
	int arr[] = { 1, 2, 1, 3 };
	int N = sizeof(arr) / sizeof(arr[0]);
	cout << minDist(arr, 0, N, 0);
	return 0;
}

