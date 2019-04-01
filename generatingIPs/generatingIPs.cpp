#include <iostream>
#include <string>

using namespace std;

void generateIPs(const string& input, string& current, unsigned currIndex,unsigned sectors)
{
	if (sectors == 4 && current.size()-3 == input.size())
	{
		cout << current << endl;
		return;
	}

	string temp;

	for (size_t i = currIndex; i < currIndex+3 && i< input.size(); i++)
	{
		
		temp.push_back(input[i]);

		if (stoi(temp) <= 255 && (temp[0] != '0' || temp.size()==1))
		{
			generateIPs(input, current + temp +((sectors<3)?".":""), i+1,sectors+1);
		}
	}

	return;
}


int main()
{
	string input;
	cin >> input;
	string current;

	generateIPs(input,current,0,0);
}
