#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int novels[501][501];

int MergeFiles(int start, int end)
{
	if (start == end) return 0;
	if (novels[start][end] != 0) return novels[start][end];

	vector<int> files;
	int sum = 0;
	for (int i = start; i <= end; i++)
		sum += novels[i][i];
	for (int i = start; i < end; i++)
		files.push_back(MergeFiles(start, i) + MergeFiles(i + 1, end) + sum);
		
	return novels[start][end] = *min_element(files.begin(), files.end());
}

int main(void)
{
	int T;
	scanf("%d", &T);

	while (T--)
	{
		int K;
		scanf("%d", &K);
		for (int i = 1; i <= K; i++)
			for (int j = 1; j <= K; j++)
				novels[i][j] = 0;

		for (int i = 1; i <= K; i++)
			scanf("%d", &novels[i][i]);

		printf("%d\n", MergeFiles(1, K));
	}

	return 0;
}