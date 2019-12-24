#include <cstdio>

int W[101], V[101];
int d[101][100001];

int main(void)
{
	int N, K;
	scanf("%d %d", &N, &K);
	for (int i = 1; i <= N; i++)
		scanf("%d %d", &W[i], &V[i]);

	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= K; j++)
			if (j - W[i] >= 0 && d[i - 1][j] < d[i - 1][j - W[i]] + V[i]) d[i][j] = d[i - 1][j - W[i]] + V[i];
			else d[i][j] = d[i - 1][j];

	printf("%d\n", d[N][K]);
	return 0;
}