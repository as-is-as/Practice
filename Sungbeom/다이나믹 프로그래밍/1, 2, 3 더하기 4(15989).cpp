#include <cstdio>

int d[10001][3];

int main(void)
{
	d[1][1] = 1; d[2][1] = 1; d[2][2] = 1; d[3][1] = 2; d[3][3] = 1;
	for (int i = 4; i <= 10000; i++)
	{
		d[i][1] = d[i - 1][1] + d[i - 1][2] + d[i - 1][3];
		d[i][2] = d[i - 2][2] + d[i - 2][3];
		d[i][3] = d[i - 3][3];
	}

	int T;
	scanf("%d", &T);

	while (T--)
	{
		int n;
		scanf("%d", &n);

		printf("%d\n", d[n][1] + d[n][2] + d[n][3]);
	}

	return 0;
}