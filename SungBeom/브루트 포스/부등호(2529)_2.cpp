#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int k;
char inequality[10];
vector<int> nums(10);
vector<bool> check(10);
bool ending;

void moreInequality(int left, vector<int>& ans)
{
	if (left == 0)
	{
		vector<int> ansCheck = ans;
		do
		{
			bool checkOrder = true;
			for (int i = 0; i < k; i++)
			{
				if (inequality[i] == '<' && ansCheck[i] < ansCheck[i + 1]) continue;
				else if (inequality[i] == '>' && ansCheck[i] > ansCheck[i + 1]) continue;
				else
				{
					checkOrder = false;
					break;
				}
			}
			if (checkOrder)
			{
				for (int i = 0; i < k + 1; i++)
					printf("%d", ansCheck[i]);
				printf("\n");
				ending = true;
				break;
			}
		} while (prev_permutation(ansCheck.begin(), ansCheck.end()));
	}
	else
	{
		for (int i = 9; i >= 0; i--)
		{
			if (check[i]) continue;

			check[i] = true;
			ans.push_back(i);
			moreInequality(left - 1, ans);
			if (ending) return;
			ans.pop_back();
			check[i] = false;
		}
	}
}

void lessInequality(int left, vector<int>& ans)
{
	if (left == 0)
	{
		vector<int> ansCheck = ans;
		do
		{
			bool checkOrder = true;
			for (int i = 0; i < k; i++)
			{
				if (inequality[i] == '<' && ansCheck[i] < ansCheck[i + 1]) continue;
				else if (inequality[i] == '>' && ansCheck[i] > ansCheck[i + 1]) continue;
				else
				{
					checkOrder = false;
					break;
				}
			}
			if (checkOrder)
			{
				for (int i = 0; i < k + 1; i++)
					printf("%d", ansCheck[i]);
				printf("\n");
				ending = true;
				break;
			}
		} while (next_permutation(ansCheck.begin(), ansCheck.end()));
	}
	else
	{
		for (int i = 0; i < 10; i++)
		{
			if (check[i]) continue;

			check[i] = true;
			ans.push_back(i);
			lessInequality(left - 1, ans);
			if (ending) return;
			ans.pop_back();
			check[i] = false;
		}
	}
}

int main(void)
{
	scanf("%d", &k);
	for (int i = 0; i < k; i++)
		scanf(" %c", &inequality[i]);

	vector<int> ans;
	for (int i = 0; i < 10; i++)
		nums[i] = 9 - i;
	moreInequality(k + 1, ans);

	ans.clear();
	for (int i = 0; i < 10; i++)
	{
		check[i] = false;
		nums[i] = i;
	}
	lessInequality(k + 1, ans);

	return 0;
}