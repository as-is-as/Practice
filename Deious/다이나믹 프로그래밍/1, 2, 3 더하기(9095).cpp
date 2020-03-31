#include <iostream>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int count;
	cin >> count;

	while (count--)
	{
		int d[11] = {0,};
		d[0] = 1;

		int num;
		cin >> num;

		for (int i = 1; i <= num; i++)
		{
			if (i - 1 >= 0)
			{
				d[i] += d[i - 1];
			}
			if (i - 2 >= 0)
			{
				d[i] += d[i - 2];
			}
			if (i - 3 >= 0)
			{
				d[i] += d[i - 3];
			}
		}
		cout << d[num] << "\n";
	}

	return 0;
}