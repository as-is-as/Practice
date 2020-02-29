#include <cstdio>

int volume[100];
bool d[101][1001];

int main(void)
{
	int N, S, M;
	scanf("%d %d %d", &N, &S, &M);
	for (int i = 0; i < N; i++)
		scanf("%d", &volume[i]);

	d[0][S] = true;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j <= M; j++)
		{
			if (d[i][j])
			{
				if (j - volume[i] >= 0) d[i + 1][j - volume[i]] = true;
				if (j + volume[i] <= M) d[i + 1][j + volume[i]] = true;
			}
		}
	}

	int ans = -1;
	for (int i = M; i >= 0; i--)
	{
		if (d[N][i])
		{
			ans = i;
			break;
		}
	}

	printf("%d\n", ans);
	return 0;
}