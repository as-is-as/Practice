#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	int n, s, answer = 0;
	scanf("%d %d", &n, &s);

	vector<int> v(n);

	for (int i = 0; i < v.size(); i++)
	{
		scanf("%d", &v[i]);
	}

	int count = n - 1;

	for (int i = 0; i < n; i++)
	{
		if (v[i] == s) answer++;
	}

	while (count--)
	{
		vector<int> v1(n);
		for (int i = n - 1; i >= count; i--) v1[i] = 1;
		do
		{
			int num = 0;
			for (int j = 0; j < v.size(); j++)
			{
				if (v1[j] == 1) num += v[j];
			}

			if (num == s) answer++;
		} while (next_permutation(v1.begin(), v1.end()));
	}

	printf("%d\n", answer);

	return 0;
}