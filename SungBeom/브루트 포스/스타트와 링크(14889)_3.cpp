#include <cstdio>
#include <iostream>
#include <bitset>
#include <vector>
#include <climits>
using namespace std;

int main(void)
{
	int N;
	scanf("%d", &N);
	int stats[20][20];
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			scanf("%d", &stats[i][j]);

	int min = INT_MAX;
	for (int i = 0; i < (1 << N); i++)
	{
		bitset<20> bits(i);

		if (bits.count() == N / 2)
		{
			vector<int> team1, team2;
			for (int i = 0; i < N; i++)
			{
				if (bits[i] & 1) team1.push_back(i);
				else team2.push_back(i);
			}

			int stat1 = 0, stat2 = 0;
			for (int i = 0; i < N / 2 - 1; i++)
				for (int j = i + 1; j < N / 2; j++)
				{
					stat1 += stats[team1[i]][team1[j]] + stats[team1[j]][team1[i]];
					stat2 += stats[team2[i]][team2[j]] + stats[team2[j]][team2[i]];
				}

			int gap = stat1 - stat2;
			if (gap < 0) gap = -gap;
			if (min > gap) min = gap;
		}
	}

	printf("%d\n", min);
	return 0;
}