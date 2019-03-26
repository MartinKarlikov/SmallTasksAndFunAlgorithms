#include <iostream>

using namespace std;

#define N 5
#define M 6

int modifiedBinarySearch(int matrix[N][M], int rowNum, int startIndex, int endIndex, int num)
{

	int middle = (startIndex + endIndex) / 2;

	if (startIndex == endIndex )
	{
		return startIndex;
	}
	if (matrix[rowNum][middle] > num)
	{
		return modifiedBinarySearch(matrix, rowNum, startIndex, middle, num);
	}
	else
	{
		return modifiedBinarySearch(matrix, rowNum, middle + 1, endIndex, num);
	}

	return -1;

}

unsigned getGreaterThan(int matrix[N][M], int numX, int numY)
{
	int num = matrix[numX][numY];

	unsigned countOfGreater = 0;

	int currX = 0;

	int currY = M - 1;

	while (currX < N)
	{

		currY = modifiedBinarySearch(matrix, currX, 0, currY, num);

		if (currY == 0)
		{
			break;
		}
		countOfGreater += M - ((matrix[currX][currY]>num)?currY:currY+1);
		++currX;
	}

	countOfGreater += (N - currX)*M;

	return countOfGreater;

}

int main()
{


	int matrix[N][M] = { {1, 3, 7, 10, 15, 20},
	{2, 6, 9, 14, 22, 25},
	{3, 8, 10, 15, 25, 30},
	{10, 11, 12, 23, 30, 35},
	{20, 25, 30, 35, 40, 45} };

	int smallerX, smallerY, greaterX, greaterY;
	cin >> smallerX >> smallerY >> greaterX >>greaterY;


	cout << N*M - getGreaterThan(matrix, smallerX, smallerY) -1 << endl;
	cout << getGreaterThan(matrix, greaterX, greaterY) << endl;
}
