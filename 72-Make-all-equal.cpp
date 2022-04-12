#include <bits/stdc++.h>
using namespace std;

// Function to equalize the array by
// adding or subtracting at most K
// value from each element
int equalize(int arr[], int n, int k)
{

	// Finding the minimum element
	// from the array
	int min_ele
		= *min_element(arr, arr + n);

	// Boolean variable to check if the
	// array can be equalized or not
	bool flag = true;

	// Traversing the array
	for (int i = 0; i < n; i++) {

		// Checking if the values lie
		// within the possible range
		// for each element
		if (!((arr[i] + k) >= min_ele + k
			&& min_ele + k >= (arr[i] - k))) {

			// If any value doesn't lie in
			// the range then exit the loop
			flag = false;
			break;
		}
	}

	if (flag) {

		// Value after equalizing the array
		return min_ele + k;
	}

	// Array cannot be equalized
	else
		return -1;
}

// Driver code
int main()
{
	int K = 2;
	int arr[] = { 1, 2, 3, 4, 5 };
	int N = sizeof(arr) / sizeof(arr[0]);

	cout << equalize(arr, N, K);
}

