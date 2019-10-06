#include <cstdio>
#include <climits>
#include <vector>
using namespace std;

int N;
int stats[20][20];
vector<int> team1, team2;
int minGap = INT_MAX;

void makeTeam(int index, int left1, int left2)
{
	if (index == N)
	{
		int num1 = 0, num2 = 0;
		for (int i = 0; i < N / 2; i++)
			for (int j = 0; j < N / 2; j++)
			{
				num1 += stats[team1[i]][team1[j]];
				num2 += stats[team2[i]][team2[j]];
			}

		int statGap = num1 - num2;
		if (statGap < 0) statGap = -statGap;
		if (minGap > statGap) minGap = statGap;
	}
	else
	{
		if (left1 > 0)
		{
			team1.push_back(index);
			makeTeam(index + 1, left1 - 1, left2);
			team1.pop_back();
		}
		if (left2 > 0)
		{
			team2.push_back(index);
			makeTeam(index + 1, left1, left2 - 1);
			team2.pop_back();
		}
	}
}

int main(void)
{
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			scanf("%d", &stats[i][j]);

	makeTeam(0, N / 2, N / 2);

	printf("%d\n", minGap);
	return 0;
}