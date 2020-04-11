#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	int n;
	scanf("%d", &n);

	vector<vector<int>> v(n, vector<int>(n));

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			scanf("%d", &v[i][j]);
		}
	}

	vector<int> v1(n);

	for (int i = 0; i < n / 2; i++)
	{
		v1[i] = 1;
	}

	sort(v1.begin(), v1.end());

	int ans = 2100000000;

	do 
	{
		vector<int> team1, team2;

		for (int i = 0; i < n; i++)
		{
			if (v1[i] == 0)
			{
				team1.push_back(i);
			}
			else
			{
				team2.push_back(i);
			}
		}

		int a = 0, b = 0;

		for (int i = 0; i < n / 2; i++)
		{
			for (int j = 0; j < n / 2; j++)
			{
				if (i == j) continue;

				a += v[team1[i]][team1[j]];
				b += v[team2[i]][team2[j]];
			}
		}

		int temp = a - b;
		if (temp < 0) temp = -temp;
		if (ans > temp) ans = temp;
	} while (next_permutation(v1.begin(), v1.end()));

	printf("%d", ans);

	return 0;
}