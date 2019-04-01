#include <iostream>
#include <vector>
using namespace std;

unsigned getBigger(unsigned a, unsigned b)
{
	return (a > b) ? a : b;
}


void minDiff(const vector<unsigned>& input)
{
	unsigned sum = 0;

	for each(unsigned curr in input)
	{
		sum += curr;
	}

	sum /= 2;
	unsigned itemCnt = input.size();

	unsigned** maxVal = new unsigned*[itemCnt];

	for (size_t i = 0; i < itemCnt; i++)
	{
		maxVal[i] = new unsigned[sum +1];
	}

	for (size_t i = 0; i <= sum; i++)
	{
		maxVal[0][i] = 0;
	}
	for (size_t i = 0; i < itemCnt; i++)
	{
		maxVal[i][0] = 0;
	}

	for (size_t i = 1; i < itemCnt; i++)
	{
		for (size_t j = 1; j <= sum; j++)
		{
			if (input[i] <= j)
			{
				maxVal[i][j] = getBigger(maxVal[i - 1][j], input[i] + maxVal[i - 1][j - input[i]]);
			}
			else
			{
				maxVal[i][j] = maxVal[i - 1][j];
			}
		}
	}

	int i = itemCnt -1, w = sum;

	vector<unsigned> lSubset;
	vector<unsigned> rSubset;

	while (i>0 && w>0)
	{
		
		if (maxVal[i][w]!=maxVal[i-1][w])
		{
			lSubset.push_back(input[i]);
			w -= input[i];
			i -= 1;
		}
		else
		{
			rSubset.push_back(input[i]);
			i -= 1;
		}

	}

	for each (unsigned a in lSubset)
	{
		cout << a << " ";
	}

	cout << endl;

	for each (unsigned b in rSubset)
	{
		cout << b << " ";
	}

	cout << endl;

}


int main()
{
	unsigned a;
	vector<unsigned> input;
	input.push_back(0);

	while (cin>>a)
	{
		input.push_back(a);
	}

	minDiff(input);
}
