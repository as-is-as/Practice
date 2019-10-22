#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int n, k;
int d[10001];
vector<int> coins;

int main(void)
{
	scanf("%d %d", &n, &k);

	coins.resize(n);
	for (int i = 0; i < n; i++)
		scanf("%d", &coins[i]);
	sort(coins.begin(), coins.end());
	coins.erase(unique(coins.begin(), coins.end()), coins.end());

	n = coins.size();
	for (int i = 0; i < n; i++)
		if (coins[i] <= k) d[coins[i]] = 1;
	for (int i = 0; i < n; i++)
		for (int j = coins[i] + 1; j <= k; j++)
			if (d[j - coins[i]] != 0 && (d[j] == 0 || d[j] > d[j - coins[i]] + 1)) d[j] = d[j - coins[i]] + 1;

	if (d[k] > 0) printf("%d\n", d[k]);
	else printf("-1\n");
	return 0;
}