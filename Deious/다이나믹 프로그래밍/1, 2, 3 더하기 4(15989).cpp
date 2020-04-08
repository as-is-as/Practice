#include <cstdio>

int main()
{
	int count, num;
	int nums[] = { 1,2,3 };
	scanf("%d", &count);

	while (count--)
	{
		int d[10001] = { 0, };
		d[0] = 1;
		scanf("%d", &num);

		for (int i = 0; i < 3; i++)
		{
			for (int j = nums[i]; j <= num; j++)
			{
				d[j] += d[j - nums[i]];
			}
		}

		printf("%d\n", d[num]);
	}

	return 0;
}