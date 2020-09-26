#include <iostream>
#include <queue>
#include <vector>
#include <string>

using namespace std;

int dx[] = { 0, 0, -1, 1 };
int dy[] = { 1, -1, 0, 0 };

int a, b;

bool InRange(int x, int y)
{
	return x >= 0 && x < b && y >= 0 && y < a;
}


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	queue<pair<int, int>> q;
	queue<pair<int, int>> tq;

	int w, h;
	cin >> w >> h;
	a = w, b = h;

	vector<vector<char>> v(h, vector<char>(w));
	vector<vector<int>> mv(h, vector<int>(w, 0));
	vector<vector<bool>> cv(h, vector<bool>(w, false));

	for (int i = 0; i < h; i++)
	{
		for (int j = 0; j < w; j++)
		{
			cin >> v[i][j];
			if (v[i][j] == 'C') tq.push(make_pair(i, j));
		}
	}

	q.push(make_pair(tq.front().first, tq.front().second));
	tq.pop();

	while (!q.empty())
	{
		int x = q.front().first;
		int y = q.front().second;
		cv[x][y] = true;
		q.pop();

		for (int i = 0; i < 4; i++)
		{
			int nx = x + dx[i];
			int ny = y + dy[i];

			while (InRange(nx, ny) && v[nx][ny] != '*')
			{
				if (!cv[nx][ny])
				{
					cv[nx][ny] = true;
					mv[nx][ny] = mv[x][y] + 1;
					q.push(make_pair(nx, ny));
				}

				nx += dx[i];
				ny += dy[i];
			}
		}
	}

	cout << mv[tq.front().first][tq.front().second] - 1;

	return 0;
}