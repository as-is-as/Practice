#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;


int main(void)
{
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	int N;
	int map[20][20];
	vector<int> teamInfo;
	vector<int> tempA;
	vector<int> tempB;
	cin >> N;

	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			cin >> map[i][j];
		}
	}

	int minValue = INT_MAX;
	teamInfo.resize(N);

	for (int i = 0; i < N / 2; ++i)
	{
		teamInfo[i] = 1;
	}


	do
	{
		int valueA = 0, valueB = 0;
		int tempMin;

		for (int i = 0; i < N; ++i)
		{
			if (teamInfo[i] == 1)
				tempA.push_back(i);
			else
				tempB.push_back(i);
		}

		for (int i = 0; i < N / 2; ++i)
		{
			for (int j = 0; j < N / 2; ++j)
			{
				if (i == j)
					continue;
				valueA += map[tempA[i]][tempA[j]];
				valueB += map[tempB[i]][tempB[j]];
			}
		}
		tempMin = valueA - valueB > 0 ? valueA - valueB : valueB - valueA;
		if (minValue > tempMin)
		{
			minValue = tempMin;
		}

		tempA.clear();
		tempB.clear();

	} while (prev_permutation(teamInfo.begin(), teamInfo.end()));
	cout << minValue << '\n';
	return 0;
}