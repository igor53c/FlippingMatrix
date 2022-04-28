// FlippingMatrix.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>

using namespace std;

int flippingMatrix(vector<vector<int>>);

int main()
{
	/*vector<vector<int>> vect{

		{ 112, 42, 83, 119},
		{ 56, 125, 56, 49},
		{ 15, 78, 101, 43},
		{ 62, 98, 114, 108}

	};*/

	vector<vector<int>> vect{
		{ 1, 2},
		{ 3, 4}
	};

	cout << flippingMatrix(vect) << endl; // 414

	return EXIT_SUCCESS;
}

int flippingMatrix(vector<vector<int>> matrix)
{
	int n = matrix.size() / 2;
	int sum = 0;

	int lenght = n * n;

	for (int i = 0; i < lenght; i++)
	{
		int a = i % n;
		int b = i / n;

		sum += 
			max(matrix[a][b],
				max(matrix[a][2 * n - 1 - b],
					max(matrix[2 * n - 1 - a][b], 
						matrix[2 * n - 1 - a][2 * n - 1 - b])
				)
			);
	}

	return sum;
}
