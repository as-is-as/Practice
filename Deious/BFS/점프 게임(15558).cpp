#include <cstdio>
#include <vector>
#include <queue>
#include <tuple>

using namespace std;

int v[2][100000];
bool cv[2][100000];

int main()
{
	int n, k;
	scanf("%d %d", &n, &k);

	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < n; j++)
		{
			scanf("%1d", &v[i][j]);
		}
	}

	queue<tuple<int, int, int>> q;
	q.push(make_tuple(0, 0, 0));

	while (!q.empty())
	{
		int x = get<0>(q.front());
		int time = get<1>(q.front());
		int line = get<2>(q.front());

		q.pop();

		if (x + 1 >= n || x + k >= n)
		{
			printf("1\n");
			return 0;
		}

		int temp = x + 1;

		if (temp < n && !cv[line][temp] && v[line][temp] != 0)
		{
			q.push(make_tuple(temp, time + 1, line));
			cv[line][temp] = true;
		}

		temp = x - 1;

		if (temp > time && !cv[line][temp] && v[line][temp] != 0)
		{
			q.push(make_tuple(temp, time + 1, line));
			cv[line][temp] = true;
		}

		temp = x + k;
		line = (line + 1) % 2;

		if (temp < n && !cv[line][temp] && v[line][temp] != 0)
		{
			q.push(make_tuple(temp, time + 1, line));
			cv[line][temp] = true;
		}
	}

	printf("0\n");

	return 0;
}