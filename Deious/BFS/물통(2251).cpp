#include <cstdio>
#include <queue>

using namespace std;

bool ans[201];
int check[201][201];
int cap[3];
int from[] = { 0,0,1,1,2,2 };
int to[] = { 1,2,0,2,0,1 };

int main()
{
	int sum;
	scanf("%d %d %d", &cap[0], &cap[1], &cap[2]);

	sum = cap[2];

	queue<pair<int, int>> q;
	q.push(make_pair(0, 0));
	check[0][0] = true;
	ans[cap[2]] = true;

	while (!q.empty())
	{
		int cur[3];
		cur[0] = q.front().first;
		cur[1] = q.front().second;
		cur[2] = sum - cur[0] - cur[1];
		q.pop();

		for (int i = 0; i < 6; i++)
		{
			int next[3] = { cur[0], cur[1], cur[2] };
			next[to[i]] += next[from[i]];
			next[from[i]] = 0;

			if (next[to[i]] >= cap[to[i]])
			{
				next[from[i]] = next[to[i]] - cap[to[i]];
				next[to[i]] = cap[to[i]];
			}

			if (!check[next[0]][next[1]])
			{
				check[next[0]][next[1]] = true;
				q.push(make_pair(next[0], next[1]));

				if (next[0] == 0)
				{
					ans[next[2]] = true;
				}
			}
		}
	}

	for (int i = 0; i <= cap[2]; i++)
	{
		if (ans[i]) printf("%d ", i);
	}

	return 0;
}