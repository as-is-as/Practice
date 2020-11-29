#include <cstdio>
#include <vector>

using namespace std;

bool dec[4000001];

int main()
{
	int n, answer = 0;
	scanf("%d", &n);
	dec[0] = true;
	dec[1] = true;

	for (int i = 2; i <= n; i++)
	{
		if (!dec[i])
		{
			for (int j = i + i; j <= n; j += i)
			{
				dec[j] = true;
			}
		}
	}

	vector<int> v;

	for (int i = 1; i <= n; i++)
	{
		if (!dec[i]) v.push_back(i);
	}

	for (int i = 0; i < v.size(); i++)
	{
		int num = 0;
		for (int j = i; j < v.size(); j++)
		{
			num += v[j];
			if (num == n)
			{
				answer++;
				break;
			}
			else if (num > n) break;
		}
	}

	printf("%d", answer);

	return 0;
}