#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int nums[4000][4];

int main(void)
{
	int n;
	scanf("%d", &n);

	for (int i = 0; i < n; i++)
		for (int j = 0; j < 4; j++)
			scanf("%d", &nums[i][j]);

	vector<int> sum1(n * n), sum2(n * n);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
		{
			sum1[i * n + j] = nums[i][0] + nums[j][1];
			sum2[i * n + j] = nums[i][2] + nums[j][3];
		}

	sort(sum1.begin(), sum1.end());
	sort(sum2.begin(), sum2.end());
	int start = 0, end = n * n - 1;
	long long ans = 0;

	while (true)
	{
		if (start >= n * n || end < 0) break;

		int next = sum1[start] + sum2[end];
		if (next > 0) end--;
		else if (next < 0) start++;
		else
		{
			long long leftCount = 1, rightCount = 1;
			while (start + 1 < n * n && sum1[start] == sum1[start + 1])
			{
				leftCount++;
				start++;
			}
			while (end - 1 >= 0 && sum2[end] == sum2[end - 1])
			{
				rightCount++;
				end--;
			}

			ans += leftCount * rightCount;
			start++;
			end--;
		}
	}

	printf("%lld\n", ans);
	return 0;
}