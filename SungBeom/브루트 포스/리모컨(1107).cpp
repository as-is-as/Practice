#include <cstdio>

bool broken[10];

int possible(int c)
{
	if (c == 0)
		if (broken[0]) return 0;
		else return 1;

	int len = 0;
	while (c > 0)
	{
		if (broken[c % 10]) return 0;
		len += 1; c /= 10;
	}

	return len;
}

int main(void)
{
	int N, M;
	scanf("%d %d", &N, &M);

	int brokenNum;
	for (int i = 0; i < M; i++)
	{
		scanf("%d", &brokenNum);
		broken[brokenNum] = true;
	}

	int min = N - 100;
	if (min < 0) min = -min;

	for (int i = 0; i <= 1000000; i++)
	{
		int c = i;
		int len = possible(c);

		if (len > 0)
		{
			int press = c - N;
			if (press < 0) press = -press;
			if (min > len + press) min = len + press;
		}
	}

	printf("%d\n", min);
	return 0;
}