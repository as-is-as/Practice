#include <cstdio>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

int main(void)
{
	int k;
	scanf("%d", &k);

	char inequality[10];
	for (int i = 0; i < k; i++)
		scanf(" %c", &inequality[i]);

	vector<int> nums(10);
	for (int i = 0; i < 10; i++)
		nums[i] = 9 - i;

	do
	{
		bool check = true;
		for (int i = 0; i < k; i++)
		{
			if (inequality[i] == '<' && nums[i] < nums[i + 1]) continue;
			else if (inequality[i] == '>' && nums[i] > nums[i + 1]) continue;
			else
			{
				check = false;
				break;
			}
		}
		if (check)
		{
			for (int i = 0; i < k + 1; i++)
				printf("%d", nums[i]);
			printf("\n");
			break;
		}
	} while (prev_permutation(nums.begin(), nums.end()));

	for (int i = 0; i < 10; i++)
		nums[i] = i;

	do
	{
		bool check = true;
		for (int i = 0; i < k; i++)
		{
			if (inequality[i] == '<' && nums[i] < nums[i + 1]) continue;
			else if (inequality[i] == '>' && nums[i] > nums[i + 1]) continue;
			else
			{
				check = false;
				break;
			}
		}
		if (check)
		{
			for (int i = 0; i < k + 1; i++)
				printf("%d", nums[i]);
			printf("\n");
			break;
		}
	} while (next_permutation(nums.begin(), nums.end()));

	return 0;
}