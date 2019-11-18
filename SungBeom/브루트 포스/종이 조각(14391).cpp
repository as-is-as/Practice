#include <cstdio>
#include <iostream>
#include <bitset>
using namespace std;

int nums[4][4];
bool check[4][4];

int main(void)
{
	int N, M;
	scanf("%d %d", &N, &M);

	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			scanf("%1d", &nums[i][j]);

	int end = 1 << N * M, max = 0;
	for (int i = 0; i < end; i++)
	{
		int direction[4][4];
		bitset<16> bit(i);
		for (int j = 0; j < N * M; j++)
		{
			direction[j / M][j % M] = bit[N * M - 1 - j];
			check[j / M][j % M] = false;
		}

		int sum = 0;
		for (int n = 0; n < N; n++)
		{
			for (int m = 0; m < M; m++)
			{
				if (check[n][m] == false)
				{
					int num = nums[n][m], dir = direction[n][m];
					check[n][m] = true;

					if (dir == 0)
					{
						int next = m + 1;
						while (next < M && direction[n][next] == 0)
						{
							num *= 10;
							num += nums[n][next];
							check[n][next] = true;
							next++;
						}
					}
					else
					{
						int next = n + 1;
						while (next < N && direction[next][m] == 1)
						{
							num *= 10;
							num += nums[next][m];
							check[next][m] = true;
							next++;
						}
					}

					sum += num;
				}
			}
		}
		if (max < sum) max = sum;
	}

	printf("%d\n", max);
	return 0;
}