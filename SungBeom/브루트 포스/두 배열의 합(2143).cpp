#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int nNums[1000], mNums[1000];

int main(void)
{
	long long T;
	scanf("%lld", &T);
	int n, m;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) scanf("%d", &nNums[i]);
	scanf("%d", &m);
	for (int i = 0; i < m; i++) scanf("%d", &mNums[i]);

	vector<int> subArr1(n + 1), subArr2(m + 1);
	subArr1[0] = subArr1[1] = subArr2[0] = subArr2[1] = 1;
	vector<long long> arrSum1(n * (n + 1) / 2), arrSum2(m * (m + 1) / 2);

	int index = 0;
	do
	{
		int start = 0, end = 0, findIndex = 0;
		while (subArr1[findIndex] == 0) findIndex++;
		start = findIndex++;
		while (subArr1[findIndex] == 0) findIndex++;
		end = findIndex;

		for (int i = start; i < end; i++)
			arrSum1[index] += nNums[i];
		index++;
	} while (prev_permutation(subArr1.begin(), subArr1.end()));

	index = 0;
	do
	{
		int start = 0, end = 0, findIndex = 0;
		while (subArr2[findIndex] == 0) findIndex++;
		start = findIndex++;
		while (subArr2[findIndex] == 0) findIndex++;
		end = findIndex;

		for (int i = start; i < end; i++)
			arrSum2[index] += mNums[i];
		index++;
	} while (prev_permutation(subArr2.begin(), subArr2.end()));

	sort(arrSum1.begin(), arrSum1.end());
	sort(arrSum2.begin(), arrSum2.end());
	int start = 0, end = arrSum2.size() - 1;
	long long ans = 0;

	while (true)
	{
		if (start >= arrSum1.size() || end < 0) break;

		long long next = arrSum1[start] + arrSum2[end];
		if (next > T) end--;
		else if (next < T) start++;
		else
		{
			long long leftCount = 1, rightCount = 1;
			while (start + 1 < arrSum1.size() && arrSum1[start] == arrSum1[start + 1])
			{
				leftCount++;
				start++;
			}
			while (end - 1 >= 0 && arrSum2[end] == arrSum2[end - 1])
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