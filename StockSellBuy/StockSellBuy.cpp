#include <iostream>
#include <vector>
using namespace std;

#define FEE 2

struct Interval
{
	Interval(int a, int b)
	{
		buy = a;
		sell = b;
	}
	int buy;
	int sell;
};

int getBigger(int a, int b)
{
	return (a > b) ? a : b;
}

unsigned maxIndex(const vector<int>& nums, unsigned startIndex, unsigned endIndex)
{
	if (startIndex>endIndex)
	{
		return endIndex;
	}
	while (startIndex < endIndex-1 && nums[startIndex] < nums[startIndex+1])
	{
		startIndex++;
		
	}
	if (startIndex == endIndex - 1  && nums[startIndex]<nums[endIndex])
	{
		return endIndex ;
	}
	return startIndex;
}

unsigned minIndex(const vector<int>& nums, unsigned startIndex, unsigned endIndex)
{
	if (startIndex>endIndex)
	{
		return endIndex;
	}
	while (startIndex < endIndex - 1 && nums[startIndex] > nums[startIndex + 1])
	{
		startIndex++;
	}

	return startIndex;
}

int getProfit(const vector<int>& inputNums,vector<Interval>& intervals)
{
	int profit = 0;

	for (size_t i = 0; i < intervals.size(); i++)
	{
		profit += inputNums[intervals[i].sell] - inputNums[intervals[i].buy] - FEE;
	}

	return profit;
}


int getMaxProfit(const vector<int>& inputNums, int startIndex,vector<Interval>& bought,int profit)
{
	int intervalSize = 0;
	int i = 0;
	int end = inputNums.size() - 1;

	if (startIndex >= end)
	{
		return profit;
	}

	int min = minIndex(inputNums, startIndex, end);

	if (min == end)
	{
		return profit;
	}

	int firstMax = maxIndex(inputNums, min + 1, end);
	int secondMax = maxIndex(inputNums, firstMax+1, end);

	if (firstMax == secondMax)
	{
		bought.push_back(Interval(min, firstMax));
		int profit = getProfit(inputNums, bought);
		bought.pop_back();
		return profit;
	}
	else
	{
		bought.push_back(Interval(min, firstMax));
		int firstProfit = getMaxProfit(inputNums, firstMax + 1, bought, getProfit(inputNums, bought));
		bought.pop_back();
		bought.push_back(Interval(min, secondMax));
		int secondProfit = getMaxProfit(inputNums, secondMax + 1, bought, getProfit(inputNums, bought));
		profit += getBigger(firstProfit, secondProfit);
	}

	return profit;
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
	vector<Interval> starter;

	cout << getMaxProfit(inputNums,0,starter,0) << endl;
}
