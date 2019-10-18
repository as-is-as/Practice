#include <cstdio>

long d[101];

int main(void)
{
	int N;
	scanf("%d", &N);

	d[1] = 1; d[2] = 2; d[3] = 3;
	for (int i = 4; i <= 100; i++)
	{
		d[i] = d[i - 1] + 1;
		for (int j = 2; j <= i - 3; j++)
			if (d[i] < d[j] * (i - j - 1)) d[i] = d[j] * (i - j - 1);
	}

	printf("%ld\n", d[N]);
	return 0;
}