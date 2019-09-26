#include <cstdio>

int LCM(int a, int b)
{
	int lcm = a * b;

	while (b != 0)
	{
		int temp = a % b;
		a = b;
		b = temp;
	}

	lcm /= a;
	return lcm;
}

int main(void)
{
	int T;
	scanf("%d", &T);

	while (T--)
	{
		int M, N, x, y;
		scanf("%d %d %d %d", &M, &N, &x, &y);
		x -= 1; y -= 1;

		int lcm = LCM(M, N), num = y;
		while (num <= lcm && num%M != x) num += N;
		if (num > lcm) printf("-1\n");
		else printf("%d\n", num + 1);
	}

	return 0;
}