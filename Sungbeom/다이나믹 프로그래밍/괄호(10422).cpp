#include <cstdio>

long long d[5001];

int main(void)
{
	int T;
	scanf("%d", &T);

	d[0] = d[2] = 1;
	for (int i = 4; i <= 5000; i += 2)
	{
		for (int j = 0; j < i; j += 2)
		{
			d[i] += d[j] * d[i - j - 2];
			d[i] %= 1000000007;
		}
	}

	while (T--)
	{
		int L;
		scanf("%d", &L);
		printf("%lld\n", d[L]);
	}

	return 0;
}