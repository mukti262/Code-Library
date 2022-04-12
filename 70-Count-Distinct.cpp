// C++ program for the above approach
#include <bits/stdc++.h>
using namespace std;

// Function to calculate gcd
int gcd(int A, int B)
{
	if (B == 0)
		return A;
	else
		return gcd(B, A % B);
}

// Function to find number of possible final values
int getDistinctValues(int A, int B, int C)
{

	// Find the gcd of two numbers
	int g = gcd(A, B);

	// Calculate number of distinct values
	int num_values = C / g;

	// Return values
	return num_values;
}

// Driver Code
int main()
{
	int A = 2;
	int B = 3;
	int C = 10;

	cout << (getDistinctValues(A, B, C));
	return 0;
}

// This code is contributed by subhammahato348

