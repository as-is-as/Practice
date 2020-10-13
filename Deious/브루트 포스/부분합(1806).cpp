#include <cstdio>

using namespace std;

int dp[99990];

int main()
{
	int n, s, len = 99990;
	scanf("%d %d", &n, &s);

	for (int i = 0; i < n; i++)
	{
		scanf("%d", &dp[i]);
	}

	for (int i = 0; i < n; i++)
	{
		int num = 0;
		for (int j = i; j < n; j++)
		{
			num += dp[j];
			if (num >= s)
			{
				if (len > j - i) len = j - i + 1;
				break;
			}
		}
	}

	if (len == 99990) len = 0;

	printf("%d", len);

	return 0;
}