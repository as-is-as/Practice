#include <cstdio>
#include <vector>
using namespace std;

int N;
vector<int> signs;
vector<int> nums;
vector<char> sums;
bool ending = false;

void findNums(int index)
{
	if (index == N)
	{
		ending = true;
		return;
	}

	if (!ending)
	{
		if (signs[index] == 0) findNums(index + 1);
		else if (signs[index] == 1)
		{
			for (int i = 1; i <= 10; i++)
			{
				nums[index] = i;
				if (index == 0) findNums(1);

				bool check = true;
				int gap = N;
				for (int j = 0, k = 0; j < index; j++, k += gap--)
				{
					int num = nums[j];
					for (int l = j + 1; l < index + 1; l++) num += nums[l];

					if ((num > 0 && sums[k - j + index] == '+') ||
						(num < 0 && sums[k - j + index] == '-') ||
						(num == 0 && sums[k - j + index] == '0')) continue;
					else
					{
						check = false;
						break;
					}
					if (!check) break;
				}
				if (check) findNums(index + 1);
				if (ending) return;
			}
		}
		else
		{
			for (int i = -1; i >= -10; i--)
			{
				nums[index] = i;
				if (index == 0) findNums(1);

				bool check = true;
				int gap = N;
				for (int j = 0, k = 0; j < index; j++, k += gap--)
				{
					int num = nums[j];
					for (int l = j + 1; l < index + 1; l++) num += nums[l];

					if ((num > 0 && sums[k - j + index] == '+') ||
						(num < 0 && sums[k - j + index] == '-') ||
						(num == 0 && sums[k - j + index] == '0')) continue;
					else
					{
						check = false;
						break;
					}
					if (!check) break;
				}
				if (check) findNums(index + 1);
				if (ending) return;
			}
		}
	}
}

int main(void)
{
	scanf("%d", &N);
	int len = N * (N + 1) / 2;
	sums.resize(len);
	for (int i = 0; i < len; i++)
		scanf(" %c", &sums[i]);

	signs.resize(N);
	nums.resize(N);
	int gap = N;
	for (int i = 0, j = 0; i < N; i++, j += gap--)
	{
		if (sums[j] == '+') nums[i] = signs[i] = 1;
		else if (sums[j] == '-') nums[i] = signs[i] = -1;
		else signs[i] = 0;
	}

	findNums(0);

	for (int i = 0; i < N; i++)
		printf("%d ", nums[i]);
	printf("\n");
	return 0;
}