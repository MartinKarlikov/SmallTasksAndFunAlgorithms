#include <iostream>
#include <list>
#include <algorithm>
using namespace std;

struct interval
{
	interval(double _start,double _end)
	{
		start = _start;
		end = _end;
	}
	double start;
	double end;
};

interval* intersect(interval first, interval second)
{


	if (first.end >= second.start)
	{
		return new interval(second.start, first.end);
	}


	return nullptr;
}

bool compare(interval* first, interval* second)
{
	return (first->end < second->end);
}



int main()
{
	list<interval*> intervals;
	
	unsigned numOfIntervals;
	cin >> numOfIntervals;

	double currStart;
	double currEnd;

	while (numOfIntervals > 0)
	{
		cin >> currStart;
		cin >> currEnd;

		interval* currInterval = new interval(currStart, currEnd);

		intervals.push_back(currInterval);
		numOfIntervals--;
	}

	intervals.sort(compare);

	list<interval*>::iterator it = intervals.begin();

	list<interval*> result;

	for (; it != intervals.end(); ++it)
	{

		if (result.empty())
		{
		result.push_back((*it));
		continue;
		}

		interval* last = result.back();

		interval* currIntersect = intersect(*last, *(*it));

		if (currIntersect)
		{
		delete last;
		result.pop_back();
		result.push_back(currIntersect);
		}
		else
		{
			result.push_back((*it));
		}
	}

	it = result.begin();

	for (; it != result.end(); ++it)
	{
		cout << (*it)->start << " ";
	}
	cout << endl;

	for (it = result.begin(); it != result.end(); ++it)
	{
		delete (*it);
	}
}
