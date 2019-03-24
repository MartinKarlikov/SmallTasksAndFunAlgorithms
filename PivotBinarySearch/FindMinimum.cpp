#include <iostream>

using namespace std;

int findMinimum(int* nums, unsigned start, unsigned end,unsigned initSize)
{
	unsigned middle = (start + end) / 2;
	
	if ((middle == initSize-1 ||nums[middle]<nums[middle+1]) &&(middle == 0 || nums[middle]<nums[middle-1]))
	{
		return nums[middle];
	}

	if (nums[start] > nums[middle])
	{
		return findMinimum(nums, start, middle - 1,initSize);
	}
	else
	{
		return findMinimum(nums, middle+1, end,initSize);
	}
}

int main()
{

	int inputLength;
	cin >> inputLength;

	int* nums = new int[inputLength];

	for (int i = 0; i < inputLength; i++)
	{
		cin>>nums[i];
	}

	cout << findMinimum(nums, 0, inputLength-1,inputLength) << endl;

	delete[] nums;

}
