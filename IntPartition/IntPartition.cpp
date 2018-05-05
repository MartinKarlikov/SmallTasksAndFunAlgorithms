#include <iostream>
using namespace std;

void Partition(int n)
{

	int* parts = new (nothrow)int[n];

	int mainPart = 1;

	int index = 1;

	for (size_t i = 1; i < n; ++i)
	{

		parts[i] = 1;

	}

	parts[0] = n;

	cout << n << " = " << n << endl;

	while (index != 0)
	{

		if (parts[index - 1] == 2)
		{

			mainPart += 1;

			parts[index - 1] = 1;

			index -= 1;

		}

		else
		{

			int m = parts[index - 1] - 1;

			int b = mainPart - index + 1;

			parts[index - 1] = m;

			while (b >= m)
			{

				index += 1;

				parts[index - 1] = m;

				b -= m;

			}

			if (b == 0)
			{

				mainPart = index;

			}
			else
			{

				mainPart = index + 1;

				if (b > 1)
				{

					index += 1;

					parts[index - 1] = b;

				}
			}
		}

		cout << n << " = ";

		for (size_t i = 0; i < mainPart; ++i)
		{

			cout << parts[i];

			if (i != mainPart - 1)
			{

				cout << " + ";
			}

		}

		cout << endl;
	}

	delete[] parts;
}

int main()
{
	int n;
	cin >> n;
	Partition(n);
	return 0;
}