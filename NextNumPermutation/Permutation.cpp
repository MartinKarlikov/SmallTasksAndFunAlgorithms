#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


unsigned switchFirstPossible(vector<int>& num)
{
	unsigned pos=0;

	for (int i = num.size()-2; i >= 0; --i)
	{
		if (num[i] < num[i+1])
		{
			pos = i;
			break;
		}
	}

	if (pos == 0)
	{
		cout << "No permutation possible"<<endl;
		return 0;
	}

	unsigned posToSwitch = pos+1;
	for (size_t i = pos+1; i < num.size(); ++i)
	{
		if (num[i] > num[pos] && num[i]<=num[posToSwitch])
		{
			posToSwitch = i;
		}
	}

	swap(num[pos], num[posToSwitch]);
	
	return pos;

}

int main()
{

	vector<int> inputArr;
	
	int input;
	cin >> input;

	unsigned powr = log10(input) + 1;

	while (input != 0)
	{
		inputArr.insert(inputArr.begin(), input % 10);

		input /= 10;

	}

	unsigned pos = switchFirstPossible(inputArr);

	if (!pos)
	{
		return 0;
	}

	vector<int>::iterator it = inputArr.begin() + pos+1;

	sort(it, inputArr.end());

	for (int a : inputArr)
	{
		cout << a;
	}
	cout << endl;

	return 0;
}
