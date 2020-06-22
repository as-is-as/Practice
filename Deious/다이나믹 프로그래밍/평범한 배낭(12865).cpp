#include <cstdio>

int w[101];
int v[101];
int d[101][100001];

int main(void)
{
	int n, k;
	scanf("%d %d", &n, &k);

	for (int i = 1; i <= n; i++)
	{
		scanf("%d %d", &w[i], &v[i]);
	}

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= k; j++)
		{
			if (j - w[i] >= 0 && d[i - 1][j] < d[i - 1][j - w[i]] + v[i])
			{
				d[i][j] = d[i - 1][j - w[i]] + v[i];
			}
			else
			{
				d[i][j] = d[i - 1][j];
			}
		}
	}

	printf("%d\n", d[n][k]);

	return 0;
}