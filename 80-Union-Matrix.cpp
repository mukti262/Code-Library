#include <bits/stdc++.h>
using namespace std;

void printMatrix(int n, int k)
{
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {

			if (i == j)
				cout << k << " ";

			else
				cout << "0 ";
		}
		cout << "\n";
	}
}

int main()
{
	int n = 3, k = 7;

	printMatrix(n, k);

	return (0);
}

