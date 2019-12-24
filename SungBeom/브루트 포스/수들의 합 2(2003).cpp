#include <cstdio>

int nums[10000];

int main(void)
{
	int N;
	long long M;
	scanf("%d %lld", &N, &M);
	for (int i = 0; i < N; i++)
		scanf("%d", &nums[i]);

	long long count = 0;
	for (int i = 0; i < N; i++)
	{
		long long num = 0;
		for (int j = i; j < N; j++)
		{
			num += nums[j];
			if (num == M) { count++; break; }
			else if (num > M) break;
		}
	}

	printf("%lld", count);
	return 0;
}