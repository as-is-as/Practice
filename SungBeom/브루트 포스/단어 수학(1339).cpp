#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

int capital[26];

int main(void)
{
	int N;
	scanf("%d", &N);

	vector<string> str(N);
	for (int i = 0; i < N; i++)
		cin >> str[i];

	set<char> alpha;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < str[i].size(); j++)
			alpha.insert(str[i][j]);

	int len = alpha.size();
	vector<char> usedAlpha;
	for (set<char>::iterator iter = alpha.begin(); iter != alpha.end(); iter++)
		usedAlpha.push_back(*iter);

	vector<int> nums(len);
	for (int i = 0; i < len; i++)
		nums[i] = 9 - i;

	int max = 0;
	do
	{
		for (int i = 0; i < len; i++)
			capital[usedAlpha[i] - 'A'] = nums[i];

		int sum = 0;
		for (int i = 0; i < N; i++)
		{
			int num = 0;
			for (int j = 0; j < str[i].size(); j++)
			{
				num *= 10;
				num += capital[str[i][j] - 'A'];
			}
			sum += num;
		}

		if (max < sum) max = sum;
	} while (prev_permutation(nums.begin(), nums.end()));

	printf("%d\n", max);
	return 0;
}