#include <cstdio>
#include <cstring>
#include <queue>
#include <climits>
using namespace std;

char map[102][102];
int doors[102][102][3];
int check[102][102];

int dx[] = { -1, 1, 0, 0 };
int dy[] = { 0, 0, -1, 1 };

int h, w;

bool InRange(int x, int y)
{
	return x >= 0 && x <= h + 1 && y >= 0 && y <= w + 1;
}

int main(void)
{
	int t;
	scanf("%d", &t);

	while (t--)
	{
		scanf("%d %d", &h, &w);

		for (int i = 0; i <= h + 1; i++)
			for (int j = 0; j <= w + 1; j++)
			{
				map[i][j] = '.';
				doors[i][j][0] = doors[i][j][1] = doors[i][j][2] = 0;
			}

		pair<int, int> start[3];
		int index = 0;
		for (int i = 1; i <= h; i++)
			for (int j = 1; j <= w; j++)
			{
				scanf(" %1c", &map[i][j]);
				if (map[i][j] == '$')
				{
					start[index++] = make_pair(i, j);
					map[i][j] = '.';
				}
			}
		start[2] = make_pair(0, 0);

		for (int i = 0; i < 3; i++)
		{
			queue<pair<int, int>> q;
			q.push(start[i]);

			for (int i = 0; i <= h + 1; i++)
				for (int j = 0; j <= w + 1; j++)
					check[i][j] = false;

			check[q.front().first][q.front().second] = true;
			while (!q.empty())
			{
				queue<pair<int, int>> move;
				move.push(q.front()); q.pop();

				while (!move.empty())
				{
					pair<int, int> next = move.front(); move.pop();

					for (int j = 0; j < 4; j++)
					{
						int nx = next.first + dx[j], ny = next.second + dy[j];

						if (InRange(nx, ny) && !check[nx][ny])
						{
							check[nx][ny] = true;

							if (map[nx][ny] == '.')
							{
								doors[nx][ny][i] = doors[next.first][next.second][i];
								move.push(make_pair(nx, ny));
							}
							else if (map[nx][ny] == '#')
							{
								doors[nx][ny][i] = doors[next.first][next.second][i] + 1;
								q.push(make_pair(nx, ny));
							}
						}
					}
				}
			}
		}

		int min = INT_MAX;
		for (int i = 1; i <= h; i++)
			for (int j = 1; j <= w; j++)
			{
				if (map[i][j] == '.' && min > doors[i][j][0] + doors[i][j][1] + doors[i][j][2])
					min = doors[i][j][0] + doors[i][j][1] + doors[i][j][2];
				else if (map[i][j] == '#' && min > doors[i][j][0] + doors[i][j][1] + doors[i][j][2] - 2)
					min = doors[i][j][0] + doors[i][j][1] + doors[i][j][2] - 2;
			}
		printf("%d\n", min);
	}

	return 0;
}