#include <bits/stdc++.h>
using namespace std;

// Number of rows
const int n = 3;

// Number of columns
const int m = 6;

// Function that prints the matrix
// if it exists
void printMatrix(int arr[][m],
				string ans)
{
	if (ans == "No")
		cout << "No\n";
	else {
		// Print if matrix exists
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++)
				cout << arr[i][j] << " ";
			cout << '\n';
		}
	}
}

// Function to check if it is possible
// to create a matrix such that every
// row has A 1s & every column has B 1s
void createMatrix(int a, int b)
{
	int matrix[n][m], row[n], col[m];

	// Initialize all matrix
	// entries equal to 0
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			matrix[i][j] = 0;
		}
	}

	// Initialize the number of
	// ones required in every row
	for (int i = 0; i < n; i++)
		row[i] = a;

	// Initialize the number of
	// ones required in each column
	for (int i = 0; i < m; i++)
		col[i] = b;

	int l = 0, d = 0;

	// Check if the total number of
	// ones required in every row is
	// not equal to total number of
	// ones required in every column
	// then print No
	if (n * a != m * b)
		printMatrix(matrix, "No");

	else {

		for (int i = 0; i < n; i++) {
			int j;
			if (l == m)
				l = 0;

			for (j = l; j < m; j++) {

				if (row[i] > 0 && col[j] > 0) {

					// Fill a one if there is a
					// place to be filled
					matrix[i][j] = 1;

					// Decrease the number of
					// ones required in ith row
					row[i]--;

					// Decrease the number of
					// ones required in jth column
					col[j]--;
					d = j;
				}
			}
			l = d + 1;
			if (row[i] != 0) {

				for (j = 0; j < m; j++) {

					if (row[i] > 0 && col[j] > 0) {

						// Fill a one if there is
						// a place to be filled
						matrix[i][j] = 1;

						// Decrease the number of 1s
						// required in ith row
						row[i]--;
						// Decrease the number of 1s
						// required in jth column
						col[j]--;
						l = j + 1;
					}
					// Break the loop if no place
					// is left for ones to filled
					if (row[i] == 0)
						break;
				}
			}
		}

		// Function call to print the matrix
		printMatrix(matrix, "Yes");
	}
}

// Driver Code
int main()
{

	// Number of ones required
	// in every row
	int a = 2;

	// Number of ones required
	// in every column
	int b = 1;

	// Function call
	createMatrix(a, b);
	return 0;
}

