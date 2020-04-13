#include <cstdio>
#include <algorithm>

using namespace std;

int dp[10001];
int coin[101];

int main()
{
	int n, k;
	scanf("%d %d", &n, &k);

	for (int i = 1; i <= k; i++)
	{
		dp[i] = INT32_MAX;
	}

	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &coin[i]);

		for (int j = coin[i]; j <= k; j++)
		{
			dp[j] = min(dp[j], dp[j - coin[i]] + 1);
		}
	}

	if (dp[k] == INT32_MAX)
	{
		printf("%d", -1);
	}
	else
	{
		printf("%d", dp[k]);
	}

	return 0;
}