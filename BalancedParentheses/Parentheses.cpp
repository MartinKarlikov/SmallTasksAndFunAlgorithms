#include <iostream>
#include <string>

using namespace std;

int parseParenthes(char parenthes)
{
	if (parenthes == '(')
	{
		return 1;
	}
	else
	{
		return -1;
	}
}

int main()
{
	string input;
	cin >> input;
	int counter = 0;
	int openingCounter = 0;
	bool hasOpen = false;

	string output;

	for (string::iterator it = input.begin(); it != input.end(); ++it)
	{
		int parseRes = parseParenthes(*it);
		counter += parseRes;
		
		hasOpen = (parseRes == 1) ? true : hasOpen;


		if (counter>=0 || !hasOpen)
		{
			output.push_back((*it));
		}

		if (counter < 0)
		{
			counter = 0;
			if(!hasOpen)openingCounter++;
		}
	}

	for (size_t i = 0; i < openingCounter; ++i)
	{
		output = "(" + output;
	}

	for (int i = 0; i < counter; ++i)
	{
		output.push_back(')');
	}

	cout << output << endl;
}
