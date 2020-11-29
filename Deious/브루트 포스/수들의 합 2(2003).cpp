#include <cstdio>

using namespace std;

int dp[10000];

int main()
{
	int n, m, answer = 0;
	scanf("%d %d", &n, &m);

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
			if (num == m)
			{
				answer++;
				break;
			}
			else if (num > m) break;
		}
	}

	printf("%d", answer);
	return 0;
}