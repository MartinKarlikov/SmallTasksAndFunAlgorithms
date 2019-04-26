#include <vector>
#include <iostream>

void getMinAndMax(std::vector<int>& input, int& min, int& max)
{
	size_t compareCount = 0;

	size_t vectorSize = input.size();


	for (size_t i = 0; i <vectorSize/2; ++i)
	{
		if (input[i] > input[vectorSize-1-i])
		{
			std::swap(input[i], input[vectorSize - 1 - i]);
		}

		compareCount++;
	}

	int minIndex = (vectorSize % 2 == 0) ? vectorSize / 2 - 1 : vectorSize / 2;
	int maxIndex = vectorSize / 2;

	for (int i = minIndex -1; i >= 0; --i)
	{
		if (input[i] < input[minIndex])
		{
			minIndex = i;
		}

		compareCount++;
	}

	for (int i = maxIndex; i < vectorSize; ++i)
	{
		if (input[i] > input[maxIndex])
		{
			maxIndex = i;
		}

		compareCount++;
	}

	std::cout << compareCount << std::endl;

	min = input[minIndex];
	max = input[maxIndex];
}

int main()
{
	std::vector<int> test{ 3,8,1,2,7,6,9,1,3 };

	int min, max;

	getMinAndMax(test, min, max);

	std::cout << min << "  " << max << std::endl;
}
