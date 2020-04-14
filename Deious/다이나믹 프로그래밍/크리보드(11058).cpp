#include <cstdio>
#include <algorithm>

using namespace std;

long long dp[101];

int main()
{
	long long n;
	scanf("%lld", &n);

	for (int i = 1; i <= n; i++)
	{
		dp[i] = i;
	}

	if (n < 7)
	{
		printf("%lld", dp[n]);
		return 0;
	}

	for (int i = 7; i <= n; i++)
	{
		dp[i] = max(dp[i - 4] * 3, dp[i - 5] * 4);
	}

	printf("%lld", dp[n]);

	return 0;
}