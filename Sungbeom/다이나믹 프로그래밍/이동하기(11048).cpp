#include <cstdio>

int N, M;
int maze[1001][1001];

int main(void)
{
	scanf("%d %d", &N, &M);
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= M; j++)
			scanf("%d", &maze[i][j]);

	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= M; j++)
		{
			int max = maze[i - 1][j - 1];
			if (max < maze[i - 1][j]) max = maze[i - 1][j];
			if (max < maze[i][j - 1]) max = maze[i][j - 1];
			maze[i][j] += max;
		}
	}

	printf("%d\n", maze[N][M]);
	return 0;
}