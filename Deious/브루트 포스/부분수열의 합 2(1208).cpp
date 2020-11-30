#include <cstdio>
#include <vector>
#include <bitset>
#include <algorithm>

using namespace std;

int nums[40];

int main()
{
	int n, s;
	scanf("%d %d", &n, &s);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &nums[i]);
	}

	vector<int> left(1 << n / 2), right(1 << n - n / 2);

	for (int i = 0; i < 1 << n / 2; i++)
	{
		bitset<20> bit(i);
		for (int j = 0; j < n / 2; j++)
		{
			if (bit[j]) left[i] += nums[j];
		}
	}

	for (int i = 0; i < 1 << n - n / 2; i++)
	{
		bitset<20> bit(i);
		for (int j = 0; j < n - n / 2; j++)
		{
			if (bit[j]) right[i] += nums[j + n / 2];
		}
	}

	sort(left.begin(), left.end());
	sort(right.begin(), right.end());

	int start = 0, end = (1 << n - n / 2) - 1;
	long long ans = 0;

	while (true)
	{
		if (start >= 1 << n / 2 || end < 0) break;

		int next = left[start] + right[end];
		if (next > s) end--;
		else if (next < s) start++;
		else
		{
			long long leftCount = 1, rightCount = 1;
			while (start + 1 < 1 << n / 2 && left[start] == left[start + 1])
			{
				leftCount++;
				start++;
			}
			while (end - 1 >= 0 && right[end] == right[end - 1])
			{
				rightCount++;
				end--;
			}

			ans += leftCount * rightCount;
			start++;
			end--;
		}
	}

	if (s == 0) ans--;
	printf("%lld\n", ans);
	return 0;
}