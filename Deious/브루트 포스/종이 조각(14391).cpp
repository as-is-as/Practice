#include <cstdio>
#include <algorithm>

using namespace std;

int a[4][4];

int main()
{
	int n, m;
	scanf("%d %d", &n, &m);

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			scanf("%1d", &a[i][j]);
		}
	}

	int ans = 0;

	for (int s = 0; s < (1 << (n*m)); s++)
	{
		int sum = 0;
		for (int i = 0; i < n; i++)
		{
			int cur = 0;

			for (int j = 0; j < m; j++)
			{
				int k = i * m + j;
				if ((s&(1 << k)) == 0)
				{
					cur = cur * 10 + a[i][j];
				}
				else
				{
					sum += cur;
					cur = 0;
				}
			}

			sum += cur;
		}

		for (int j = 0; j < m; j++)
		{
			int cur = 0;

			for (int i = 0; i < n; i++)
			{
				int k = i * m + j;
				if ((s&(1 << k)) != 0)
				{
					cur = cur * 10 + a[i][j];
				}
				else
				{
					sum += cur;
					cur = 0;
				}
			}
			sum += cur;
		}

		ans = max(ans, sum);
	}
	
	printf("%d", ans);

	return 0;
}