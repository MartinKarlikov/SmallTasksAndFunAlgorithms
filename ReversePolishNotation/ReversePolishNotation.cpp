#include <iostream>
#include <stack>
#include <set>
#include <string>
using namespace std;

bool checker(const stack<string>& strings, int type)
{

	return (type == 1) ? strings.empty() : strings.top() == "(";

}

//gets the elements that need to be in one string and forms it
void concatInStack(stack<string>& strings, string& finalstr, int type)
{

	while (true)
	{

		string strFirst = strings.top();

		strings.pop();

		if (checker(strings, type))
		{

			finalstr = strFirst + finalstr;

			strings.push(finalstr);

			break;

		}

		string strSecond = strings.top();

		strings.pop();

		finalstr = strSecond + strFirst;

		if (checker(strings, type))
		{

			strings.push(finalstr);

			break;

		}

	}

}

//input parser function
string getSubstring(string input, int& i, char firstCmp, char secondCmp)
{

	int startPos = i;

	int offset = 1;

	while (input[i + 1] >= firstCmp && input[i + 1] <= secondCmp)
	{

		++offset;

		++i;

	}

	string num = input.substr(startPos, offset);

	return num;

}

int main()
{

	string input;
	cin >> input;

	stack<int> nums;
	stack<string> strings;

	for (int i = 0; input[i]; ++i)
	{

		if (input[i] >= '0' && input[i] <= '9')
		{

			string num = getSubstring(input, i, '0', '9');
			nums.push(stoi(num));

		}

		else if ((input[i] >= 'A' && input[i] <= 'Z'))
		{

			string str = getSubstring(input, i, 'A', 'Z');

			strings.push(str);

		}

		else if (input[i] == '(')
		{

			strings.push("(");

		}

		else
		{

			string finalstr = "";

			concatInStack(strings, finalstr, 2);

			string temp = strings.top();

			strings.pop();

			strings.pop();

			int num = nums.top();

			nums.pop();

			for (int i = 0; i < num - 1; ++i)
			{

				finalstr += temp;

			}

			strings.push(finalstr);

		}

	}

	string finalstr;

	concatInStack(strings, finalstr, 1);

	cout << strings.top() << endl;

}