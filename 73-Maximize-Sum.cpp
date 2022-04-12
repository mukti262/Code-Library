#include <bits/stdc++.h>
using namespace std;

// Function to generate previous smaller
// element for each array element
vector<int> findPrevious(vector<int> a, int n)
{
	vector<int> ps(n);

	// The first element has no
	// previous smaller
	ps[0] = -1;

	// Stack to keep track of elements
	// that have occurred previously
	stack<int> Stack;

	// Push the first index
	Stack.push(0);

	for(int i = 1; i < n; i++)
	{

		// Pop all the elements until the previous
		// element is smaller than current element
		while (Stack.size() > 0 &&
			a[Stack.top()] >= a[i])
			Stack.pop();

		// Store the previous smaller element
		ps[i] = Stack.size() > 0 ?
				Stack.top() : -1;

		// Push the index of the current element
		Stack.push(i);
	}

	// Return the array
	return ps;
}

// Function to generate next smaller element
// for each array element
vector<int> findNext(vector<int> a, int n)
{
	vector<int> ns(n);

	ns[n - 1] = n;

	// Stack to keep track of elements
	// that have occurring next
	stack<int> Stack;
	Stack.push(n - 1);

	// Iterate in reverse order
	// for calculating next smaller
	for(int i = n - 2; i >= 0; i--)
	{

		// Pop all the elements until the
		// next element is smaller
		// than current element
		while (Stack.size() > 0 &&
			a[Stack.top()] >= a[i])
			Stack.pop();

		// Store the next smaller element
		ns[i] = Stack.size() > 0 ?
				Stack.top() : n;

		// Push the index of the current element
		Stack.push(i);
	}

	// Return the array
	return ns;
}

// Function to find the maximum sum by
// subtracting same value from all
// elements of a Subarray
int findMaximumSum(vector<int> a, int n)
{

	// Stores previous smaller element
	vector<int> prev_smaller = findPrevious(a, n);

	// Stores next smaller element
	vector<int> next_smaller = findNext(a, n);

	int max_value = 0;
	for(int i = 0; i < n; i++)
	{

		// Calculate contribution
		// of each element
		max_value = max(max_value, a[i] *
					(next_smaller[i] -
						prev_smaller[i] - 1));
	}

	// Return answer
	return max_value;
}

// Driver Code
int main()
{
	int n = 3;
	vector<int> a{ 80, 48, 82 };

	cout << findMaximumSum(a, n);

	return 0;
}

