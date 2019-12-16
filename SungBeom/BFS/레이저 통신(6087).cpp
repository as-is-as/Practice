#include <cstdio>
#include <queue>
#include <climits>
using namespace std;

int maps[100][100];
int moves[100][100];

int dx[] = { -1, 1, 0, 0 };
int dy[] = { 0, 0, -1, 1 };

int W, H;

bool InRange(int x, int y)
{
	return x >= 0 && x < H && y >= 0 && y < W;
}

int main(void)
{
	scanf("%d %d", &W, &H);

	queue<pair<int, int>> q;
	bool first = true;
	for (int i = 0; i < H; i++)
		for (int j = 0; j < W; j++)
		{
			scanf(" %1c", &maps[i][j]);
			if (first && maps[i][j] == 'C')
			{
				q.push(make_pair(i, j));
				first = false;
			}
			else moves[i][j] = INT_MAX;
		}

	int answer = INT_MAX;
	while (!q.empty())
	{
		pair<int, int> next = q.front(); q.pop();

		for (int i = 0; i < 4; i++)
		{
			int nx = next.first + dx[i], ny = next.second + dy[i];

			if (InRange(nx, ny) && moves[nx][ny] > moves[next.first][next.second])
			{
				if (maps[nx][ny] == '.')
				{
					q.push(make_pair(nx, ny));
					moves[nx][ny] = moves[next.first][next.second] + 1;
					nx += dx[i]; ny += dy[i];

					while (InRange(nx, ny) && moves[nx][ny] > moves[nx - dx[i]][ny - dy[i]] - 1)
					{
						if (maps[nx][ny] == '.')
						{
							q.push(make_pair(nx, ny));
							moves[nx][ny] = moves[nx - dx[i]][ny - dy[i]];
							nx += dx[i]; ny += dy[i];
						}
						else if (maps[nx][ny] == 'C')
						{
							if (answer > moves[nx - dx[i]][ny - dy[i]] - 1) answer = moves[nx - dx[i]][ny - dy[i]] - 1;
							break;
						}
						else break;
					}
				}
				else if (maps[nx][ny] == 'C' && answer > moves[next.first][next.second])
					answer = moves[next.first][next.second];
			}
		}
	}

	printf("%d\n", answer);
	return 0;
}