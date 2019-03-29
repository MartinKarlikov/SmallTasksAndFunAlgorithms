#include <iostream>
#include <string>

using namespace std;

string getSharedSequence(const string& first, const string& second)
{
	bool ** matrix = new bool*[first.size()];

	for (size_t i = 0; i < first.size(); ++i)
	{
		matrix[i] = new bool[second.size()];
	}

	for (size_t i = 0; i < first.size(); ++i)
	{
		for (size_t j = 0; j < second.size(); ++j)
		{
			matrix[i][j] = (first[i] == second[j]) ? 1 : 0;
		}
	}

	string res;
	unsigned lastCol = 0;
	
	for (size_t i =0; i < first.size(); ++i)
	{
		
		for (size_t j = lastCol; j < second.size(); ++j)
		{
			if (matrix[i][j])
			{
				res.push_back(first[i]);
				lastCol = j+1;
				break;
			}
		}
	}

	return res;
}

string getSequence(const string& first, const string& second)
{
	string firstSequnce = getSharedSequence(first, second);

	string secondSequence = getSharedSequence(second, first);

	return (firstSequnce.size() > secondSequence.size()) ? firstSequnce : secondSequence;

}

int main()
{
	string first = "epidemiologist";

	string second = "refrigeration";

	string third = "supercalifragilisticexpialodocious";

	string firstRes = getSequence(second, first);

	cout << getSequence(firstRes, third) << endl;
}
