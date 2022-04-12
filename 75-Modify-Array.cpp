#include <bits/stdc++.h>
using namespace std;

// Function to check whether all array
// elements can be made zero or not
string isMakeZero(int arr[], int N, int K)
{
	// Stores if a power of K has
	// already been subtracted or not
	map<int, int> MP;

	// Stores all the Kth power
	vector<int> V;

	int X = 1;
	int i;

	// Iterate until X is
	// less than INT_MAX
	while (X > 0 && X < INT_MAX) {
		V.push_back(X);
		X *= K;
	}

	// Traverse the array arr[]
	for (i = 0; i < N; i++) {

		// Iterate over the range [0, M]
		for (int j = V.size() - 1; j >= 0; j--) {

			// If MP[V[j]] is 0 and V[j]
			// is less than or equal to arr[i]
			if (MP[V[j]] == 0 && V[j] <= arr[i]) {
				arr[i] -= V[j];
				MP[V[j]] = 1;
			}
		}

		// If arr[i] is not 0
		if (arr[i] != 0)
			break;
	}

	// If i is less than N
	if (i < N)
		return "No";

	// Otherwise,
	else
		return "Yes";
}

// Driver code
int main()
{

	int arr[] = { 8, 0, 3, 4, 80 };
	int N = sizeof(arr) / sizeof(arr[0]);
	int K = 2;

	cout << isMakeZero(arr, N, K);

	return 0;
}

