#include <iostream>
#include <queue>
#include <cstring>
#include <string>

using namespace std;

bool check[20001];

int main()
{
	int t;
	cin >> t;

	while (t--)
	{
		int n;
		bool answerCheck = false;
		cin >> n;
		queue<pair<string, int>> q;
		q.push(make_pair("1", 1));
		check[1] = true;

		while (!q.empty())
		{
			string real = q.front().first;
			int mod = q.front().second;
			int tempMod = mod * 10;
			int tempMod1 = tempMod + 1;
			q.pop();

			if (!check[tempMod % n])
			{
				if (tempMod % n == 0)
				{
					cout << real + "0" << "\n";
					answerCheck = true;
					break;
				}
				else
				{
					check[tempMod % n] = true;
					q.push(make_pair(real + "0", tempMod % n));
				}
			}

			if (!check[tempMod1 % n])
			{
				if (tempMod1 % n == 0)
				{
					cout << real + "1" << "\n";
					answerCheck = true;
					break;
				}
				else
				{
					check[tempMod1 % n] = true;
					q.push(make_pair(real + "1", tempMod1 % n));
				}
			}
		}

		memset(check, false, sizeof(check));

		if (!answerCheck) cout << "BRAK";
	}

	return 0;
}