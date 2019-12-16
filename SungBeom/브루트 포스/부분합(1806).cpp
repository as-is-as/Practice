#include <cstdio>
#include <climits>

int nums[100000];

int main(void)
{
	int N, S;
	scanf("%d %d", &N, &S);
	for (int i = 0; i < N; i++)
		scanf("%d", &nums[i]);

	int lIndex = 0, rIndex = 0, sum = nums[0];
	int min = INT_MAX;

	while (true)
	{
		if (sum < S)
		{
			if (++rIndex == N) break;
			sum += nums[rIndex];
		}
		else if (sum > S)
		{
			if (min > rIndex - lIndex + 1) min = rIndex - lIndex + 1;
			sum -= nums[lIndex++];
		}
		else
		{
			if (min > rIndex - lIndex + 1) min = rIndex - lIndex + 1;
			if (++rIndex == N) break;
			sum += nums[rIndex];
		}
	}

	if (min == INT_MAX) printf("0\n");
	else printf("%d\n", min);
	return 0;
}