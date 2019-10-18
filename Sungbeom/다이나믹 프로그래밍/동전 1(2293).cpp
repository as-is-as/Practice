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

	d[0] = 1;
	for (int i = 0; i < n; i++)
		for (int j = coins[i]; j <= k; j++)
			d[j] += d[j - coins[i]];

	printf("%d\n", d[k]);
	return 0;
}