#include <bits/stdc++.h>
using namespace std;

// Function to return number of moves
// to convert matrix into chessboard
int minSwaps(vector<vector<int> >& b)
{
	// Size of the matrix
	int n = b.size();

	// Traverse the matrix
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (b[0][0] ^ b[0][j] ^ b[i][0] ^ b[i][j])
				return -1;
		}
	}

	// Initialize rowSum to count 1s in row
	int rowSum = 0;

	// Initialize colSum to count 1s in column
	int colSum = 0;

	// To store no. of rows to be corrected
	int rowSwap = 0;

	// To store no. of columns to be corrected
	int colSwap = 0;

	// Traverse in the range [0, N-1]
	for (int i = 0; i < n; i++) {
		rowSum += b[i][0];
		colSum += b[0][i];
		rowSwap += b[i][0] == i % 2;
		colSwap += b[0][i] == i % 2;
	}
	// Check if rows is either N/2 or
	// (N+1)/2 and return -1
	if (rowSum != n / 2 && rowSum != (n + 1) / 2)
		return -1;

	// Check if rows is either N/2
	// or (N+1)/2 and return -1
	if (colSum != n / 2 && colSum != (n + 1) / 2)
		return -1;

	// Check if N is odd
	if (n % 2 == 1) {

		// Check if column required to be
		// corrected is odd and then
		// assign N-colSwap to colSwap
		if (colSwap % 2)
			colSwap = n - colSwap;

		// Check if rows required to
		// be corrected is odd and then
		// assign N-rowSwap to rowSwap
		if (rowSwap % 2)
			rowSwap = n - rowSwap;
	}
	else {

		// Take min of colSwap and N-colSwap
		colSwap = min(colSwap, n - colSwap);

		// Take min of rowSwap and N-rowSwap
		rowSwap = min(rowSwap, n - rowSwap);
	}

	// Finally return answer
	return (rowSwap + colSwap) / 2;
}

// Driver Code
int main()
{

	// Given matrix
	vector<vector<int> > M = { { 0, 1, 1, 0 },
							{ 0, 1, 1, 0 },
							{ 1, 0, 0, 1 },
							{ 1, 0, 0, 1 } };

	// Function Call
	int ans = minSwaps(M);

	// Print answer
	cout << ans;
}

