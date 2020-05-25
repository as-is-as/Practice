#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int novels[501][501];

int mergeFiles(int start, int end)
{
	if (start == end) return 0;

	if (novels[start][end] != 0) return novels[start][end];

	vector<int> files;
	int sum = 0;

	for (int i = start; i <= end; i++)
	{
		sum += novels[i][i];
	}

	for (int i = start; i < end; i++)
	{
		files.push_back(mergeFiles(start, i) + mergeFiles(i + 1, end) + sum);
	}

	return novels[start][end] = *min_element(files.begin(), files.end());
}

int main(void)
{
	int a;
	scanf("%d", &a);

	while (a--)
	{
		int k;
		scanf("%d", &k);

		for (int i = 1; i <= k; i++)
		{
			for (int j = 1; j <= k; j++)
			{
				novels[i][j] = 0;
			}
		}

		for (int i = 1; i <= k; i++)
		{
			scanf("%d", &novels[i][i]);
		}

		printf("%d\n", mergeFiles(1, k));
	}

	return 0;
}