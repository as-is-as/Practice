#include <cstdio>

int main(void)
{
	int N;
	scanf("%d", &N);

	int len[10], num = 10;
	len[1] = N >= num ? 9 : N;
	for (int i = 2; i <= 9; i++) len[i] = 0;
	for (int i = 2; i <= 9; i++)
	{
		if (N - num >= 0) len[i] = N >= num * 10 ? num * 9 : N - num + 1;
		else break;

		num *= 10;
	}

	int ans = 0;
	for (int i = 1; i <= 9; i++) ans += len[i] * i;
	printf("%d\n", ans);
	return 0;
}