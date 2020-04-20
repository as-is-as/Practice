#include <cstdio>

using namespace std;

int n;
int sMap[10][10];
int tempArray[10];

bool checkFunc(int index)
{
	int sum = 0;

	for (int i = index; i >= 0; i--)
	{
		sum += tempArray[i];

		if (sMap[i][index] == 0)
		{
			if (sum != 0) return false;
		}
		else if (sMap[i][index] < 0)
		{
			if (sum >= 0) return false;
		}
		else
		{
			if (sum <= 0) return false;
		}
	}

	return true;
}
bool go(int index)
{
	if (index == n) return true;

	if (sMap[index][index] == 0)
	{
		return checkFunc(index) && go(index + 1);
	}

	for (int i = 1; i <= 10; i++)
	{
		tempArray[index] = sMap[index][index] * i;

		if (checkFunc(index) && go(index + 1)) return true;
	}

	return false;
}

int main(void)
{
	scanf("%d", &n);

	for (int i = 0; i < n; i++)
	{
		char tempChar;

		for (int j = i; j < n; j++)
		{
			scanf(" %c", &tempChar);

			if (tempChar == '-')
			{
				sMap[i][j] = -1;
			}
			else if (tempChar == '+')
			{
				sMap[i][j] = 1;
			}
			else
			{
				sMap[i][j] = 0;
			}
		}
	}

	go(0);

	for (int i = 0; i < n; i++)
	{
		printf("%d ", tempArray[i]);
	}

	return 0;
}