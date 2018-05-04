#include <iostream>
#include <List>
#include <set>

using namespace std;

typedef list<int> subset;

//All subsets
static set<subset> allSubs;

void RecursiveAdd(subset& a)
{
	if (a.size() == 6)
	{
		return;
	}
	subset::iterator it;
	it = a.end();
	it--;

	int temp1 = *it;
	it--;

	int temp2 = *it;

	subset temp = a;

	for (int i = temp2 + 1; i < temp1; ++i)
	{

		it = temp.end();
		it--;
		temp.insert(it, i);
		allSubs.insert(allSubs.end(), temp);
		RecursiveAdd(temp);
		temp = a;

	}
}

int main()
{
	subset temp;

	//example input
	int arr[] = { 1,2,3,4,5,6 };


	//We need to break it down into subsets consisting of two elements.
	//Sum greater than the chosen number ofcourse

	int starter = 1;
	int chosenNum;

	// in this case the chosen number must be between 1 and 6
	cin >> chosenNum;

	while (starter < 5)
	{
		//the input array could have any size
		//this one is fixed for example purposes 
		for (int i = 6; i > starter - 1; --i)
		{
			if (starter + arr[i] > chosenNum && starter != arr[i])
			{

				//creating a pair
				temp.push_back(starter);
				temp.push_back(arr[i]);

				//inserting into the main storage for all the subsets
				allSubs.insert(allSubs.end(), temp);
				temp.clear();
			}
		}
		starter++;

	}

	//Now we spin the pairs trough the Recursive generetor that will give us the subsets of higher rank
	set<subset>::iterator it1;

	subset tempSubHigherRank = *it1;
	for (it1 = allSubs.begin(); it1 != allSubs.end(); ++it1)
	{
		RecursiveAdd(tempSubHigherRank);
	}

	subset tempSubFirstRank;
	for (int i = chosenNum + 1; i <= 6; ++i)
	{
		tempSubFirstRank.push_back(i);
		allSubs.insert(allSubs.end(), tempSubFirstRank);
		tempSubFirstRank.clear();
	}

	//Print

	subset::iterator it2;

	for (it1 = allSubs.begin(); it1 != allSubs.end(); ++it1)
	{
		subset temp = *it1;
		for (it2 = temp.begin(); it2 != temp.end(); ++it2)
		{
			cout << *it2 << " ";

		}
		cout << endl;
	}



}