#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int dp[10001];

int main()
{
	int n, k;
	scanf("%d %d", &n, &k);

	vector<int> coin(n);

	for (int i = 0; i < n; i++)
	{
		scanf("%d", &coin[i]);
	}

	sort(coin.begin(), coin.end());

	dp[0] = 1;

	for (int i = 0; i < n; i++)
	{
		for (int j = coin[i]; j <= k; j++)
		{
			dp[j] += dp[j - coin[i]];
		}
	}

	printf("%d", dp[k]);

	return 0;
}