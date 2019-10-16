#include <cstdio>
using namespace std;

int nums[2001];
int d[2001][2001];

int main(void)
{
	int N, M;
	scanf("%d", &N);
	for (int i = 1; i <= N; i++)
		scanf("%d", &nums[i]);

	for (int i = 1; i <= N; i++) d[i][i] = 1;
	for (int i = 1; i < N; i++)
		if (nums[i] == nums[i + 1]) d[i][i + 1] = 1;
	for (int i = 2; i < N; i++)
		for (int j = 1; j <= N - i; j++)
			if (nums[j] == nums[j + i] && d[j + 1][j + i - 1]) d[j][j + i] = 1;

	scanf("%d", &M);
	while (M--)
	{
		int S, E;
		scanf("%d %d", &S, &E);
		printf("%d\n", d[S][E]);
	}

	return 0;
}