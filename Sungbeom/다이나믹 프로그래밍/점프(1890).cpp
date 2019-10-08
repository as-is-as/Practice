#include <cstdio>

int N;
int jump[101][101];
long long d[101][101];

bool inRange(int x, int y)
{
	return x >= 1 && x <= N && y >= 1 && y <= N;
}

int main(void)
{
	scanf("%d", &N);
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= N; j++)
			scanf("%d", &jump[i][j]);

	if (inRange(1, 1 + jump[1][1])) d[1][1 + jump[1][1]] = 1;
	if (inRange(1 + jump[1][1], 1)) d[1 + jump[1][1]][1] = 1;
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			if (i == N && j == N) break;
			if (inRange(i, j + jump[i][j])) d[i][j + jump[i][j]] += d[i][j];
			if (inRange(i + jump[i][j], j)) d[i + jump[i][j]][j] += d[i][j];
		}
	}

	printf("%lld\n", d[N][N]);
	return 0;
}