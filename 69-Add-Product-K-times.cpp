#include <bits/stdc++.h>
using namespace std;

int prod_of_max_min(int n)
{
	int largest = 0;
	int smallest = 10;

	while (n) {

		// finds the last digit.
		int r = n % 10;

		largest = max(r, largest);
		smallest = min(r, smallest);

		// Moves to next digit
		n = n / 10;
	}

	return largest * smallest;
}

// Function to find the formed number
int formed_no(int N, int K)
{

	if (K == 1) {
		return N;
	}
	K--; // M(1) = N

	int answer = N;
	while (K--) {

		int a_current
			= prod_of_max_min(answer);

		// check if minimum digit is 0
		if (a_current == 0)
			break;

		answer += a_current;
	}

	return answer;
}

// Driver Code
int main()
{

	int N = 487, K = 100000000;

	cout << formed_no(N, K) << endl;

	return 0;
}

