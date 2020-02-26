#include <cstdio>
#include <tuple>
#include <queue>
using namespace std;

int map[2][100000];
bool check[2][100000];

int main(void)
{
	int N, k;
	scanf("%d %d", &N, &k);

	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < N; j++)
		{
			scanf("%1d", &map[i][j]);
		}
	}

	queue<tuple<int, int, int>> q;
	q.push(make_tuple(0, 0, 0)); check[0][0] = true;
	int ans = 0;

	while (!q.empty())
	{
		tuple<int, int, int> current = q.front(); q.pop();
		if (get<1>(current) + k >= N || get<1>(current) + 1 >= N)
		{
			ans = 1;
			break;
		}

		int turns = get<2>(current);
		int nextLine = get<0>(current), nextSquare = get<1>(current) + 1;
		if (nextSquare < N && !check[nextLine][nextSquare] && map[nextLine][nextSquare])
		{
			q.push(make_tuple(nextLine, nextSquare, turns + 1));
			check[nextLine][nextSquare] = true;
		}

		nextSquare = get<1>(current) - 1;
		if (nextSquare > turns && !check[nextLine][nextSquare] && map[nextLine][nextSquare])
		{
			q.push(make_tuple(nextLine, nextSquare, turns + 1));
			check[nextLine][nextSquare] = true;
		}

		nextLine = (get<0>(current) + 1) % 2, nextSquare = get<1>(current) + k;
		if (nextSquare < N && !check[nextLine][nextSquare] && map[nextLine][nextSquare])
		{
			q.push(make_tuple(nextLine, nextSquare, turns + 1));
			check[nextLine][nextSquare] = true;
		}
	}

	printf("%d\n", ans);
	return 0;
}