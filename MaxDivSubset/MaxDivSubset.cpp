#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void getMaxDivSubset(const vector<int>& inputNums)
{
	vector<int> divSize(inputNums.size(),1);
	vector<int> prevDiv(inputNums.size(), -1);

	unsigned maxDivSubIndex = 0;

	for (size_t i = 0; i < inputNums.size(); ++i)
	{
		for (size_t j = 0; j < i; ++j)
		{
			if (inputNums[i]%inputNums[j] == 0)
			{
				if (divSize[i] < divSize[j] +1)
				{
					divSize[i] = divSize[j] + 1;
					prevDiv[i] = j;
				}
			}
		}

		maxDivSubIndex = (divSize[i] > maxDivSubIndex) ? i: maxDivSubIndex;
	}

	while (maxDivSubIndex != -1)
	{
		cout << inputNums[maxDivSubIndex] << " ";
		maxDivSubIndex = prevDiv[maxDivSubIndex];
	}
}

int main()
{
	vector<int> inputNums;

	unsigned countOfNums = 0;
	cin >> countOfNums;


	while (countOfNums-- > 0)
	{
		int temp;
		cin >> temp;
		inputNums.push_back(temp);
	}

	sort(inputNums.begin(), inputNums.end());
	getMaxDivSubset(inputNums);
}
