#include <cstdio>
#include <climits>
#include <vector>
#include <algorithm>
using namespace std;

int stats[20][20];

int main(void)
{
	int N;
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			scanf("%d", &stats[i][j]);

	vector<int> p(N);
	for (int i = 0; i < N / 2; i++) p[i] = 0;
	for (int i = N / 2; i < N; i++) p[i] = 1;

	int min = INT_MAX;
	do
	{
		vector<int> team1, team2;
		int num1 = 0, num2 = 0;
		for (int i = 0; i < N; i++)
			if (p[i] == 0) team1.push_back(i);
			else team2.push_back(i);

		for (int i = 0; i < N / 2; i++)
			for (int j = 0; j < N / 2; j++)
			{
				num1 += stats[team1[i]][team1[j]];
				num2 += stats[team2[i]][team2[j]];
			}

		int statGap = num1 - num2;
		if (statGap < 0) statGap = -statGap;
;		if (min > statGap) min = statGap;
	} while (next_permutation(p.begin() + 1, p.end()));

	printf("%d\n", min);
	return 0;
}