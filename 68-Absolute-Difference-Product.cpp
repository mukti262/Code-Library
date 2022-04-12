#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> transpose(vector<vector<int>>M, int N){

for(int i = 0; i < N; i++)
{
	for(int j = 0; j < i + 1; j++)
	{
	int temp = M[i][j];
	M[i][j] = M[j][i];
	M[j][i] = temp;
	}
}
return M;

}

int matOne(vector<vector<int>>M, int N)
{

vector<int>max1;
vector<int>min1;

for(int r = 0; r < N; r++)
{
	max1.push_back(*max_element(M[r].begin(), M[r].end()));
	min1.push_back(*min_element(M[r].begin(), M[r].end()));
}

int res = 0;

// Multiply and add both array
for(int i = 0; i < N; i++){
	res += max1[i]*min1[i];
}

// Return res
return res;
}

// Driver code
int main()
{

// Original matrix
vector<vector<int>>M = {{3, 2, 5},{7, 5, 4},{7, 2, 9}};

// N size of matrix
int N = M.size();

// Call matOne function for rows
int R = matOne(M, N);

// Transpose the matrix
vector<vector<int>>T = transpose(M, N);

// Call matOne function for column
int C = matOne(T, N);

// Print the absolute difference
cout << abs(R - C) << endl;
}

// This code is contributed by shinjanpatra

