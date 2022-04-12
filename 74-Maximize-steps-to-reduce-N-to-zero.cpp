#include <bits/stdc++.h>
using namespace std;

// Function to find
// the minimum number of steps
int minSteps(int N)
{
	if (N == 1 || N == 2 || N == 3)
		return -1;
	return (N / 2);
}

// Driver code
int main()
{
	int N;
	N = 5;
	cout << minSteps(N);
	return 0;
}

