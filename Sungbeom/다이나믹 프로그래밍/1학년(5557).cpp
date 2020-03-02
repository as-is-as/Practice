#include <cstdio>

int nums[100];
long long d[101][21];

int main(void)
{
	int N;
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
		scanf("%d", &nums[i]);

	d[1][nums[0]] = 1;
	for (int i = 1; i < N; i++)
	{
		for (int j = 0; j <= 20; j++)
		{
			if (d[i][j])
			{
				if (j - nums[i] >= 0) d[i + 1][j - nums[i]] += d[i][j];
				if (j + nums[i] <= 20) d[i + 1][j + nums[i]] += d[i][j];
			}
		}
	}

	printf("%lld\n", d[N - 1][nums[N - 1]]);
	return 0;
}