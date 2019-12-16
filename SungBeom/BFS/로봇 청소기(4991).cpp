#include <cstdio>
#include <vector>
#include <queue>
#include <deque>
#include <map>
#include <climits>
#include <algorithm>
using namespace std;

char room[20][20];
int moves[10][20][20];
bool check[20][20];

int dx[] = { -1, 1, 0, 0 };
int dy[] = { 0, 0, -1, 1 };

int w, h;

bool InRange(int x, int y)
{
	return x >= 0 && x < h && y >= 0 && y < w;
}

int main(void)
{
	while (true)
	{
		scanf("%d %d", &w, &h);
		if (w == 0 && h == 0) break;

		deque<pair<int, int>> dirt;
		for (int i = 0; i < h; i++)
			for (int j = 0; j < w; j++)
			{
				scanf(" %1c", &room[i][j]);
				if (room[i][j] == '*') dirt.push_back(make_pair(i, j));
				else if (room[i][j] == 'o') dirt.push_front(make_pair(i, j));
			}

		for (int i = 0; i < dirt.size(); i++)
			for (int j = 0; j < h; j++)
				for (int k = 0; k < w; k++)
					moves[i][j][k] = -1;
		for (int i = 0; i < dirt.size(); i++)
			moves[i][dirt[i].first][dirt[i].second] = 0;

		map<int, pair<int, int>> location;
		for (int i = 0; i < dirt.size(); i++)
		{
			location.insert(make_pair(i, dirt[i]));

			queue<pair<int, int>> q; q.push(dirt[i]);
			for (int j = 0; j < h; j++)
				for (int k = 0; k < w; k++)
					check[j][k] = false;
			check[dirt[i].first][dirt[i].second] = true;

			while (!q.empty())
			{
				pair<int, int> next = q.front(); q.pop();

				for (int j = 0; j < 4; j++)
				{
					int nx = next.first + dx[j], ny = next.second + dy[j];

					if (InRange(nx, ny) && !check[nx][ny] && room[nx][ny] != 'x')
					{
						q.push(make_pair(nx, ny));
						check[nx][ny] = true;
						moves[i][nx][ny] = moves[i][next.first][next.second] + 1;
					}
				}
			}
		}

		bool ending = false;
		for (int i = 0; i < dirt.size(); i++)
		{
			for (int j = 0; j < dirt.size(); j++)
			{
				if (moves[i][dirt[j].first][dirt[j].second] == -1)
				{
					printf("-1\n");
					ending = true;
					break;
				}
			}
			if (ending) break;
		}
		if (ending) continue;

		vector<int> order(dirt.size() - 1);
		for (int i = 0; i < order.size(); i++) order[i] = i + 1;

		int min = INT_MAX;
		do
		{
			int dis = moves[0][location[order[0]].first][location[order[0]].second];
			for (int i = 0; i < order.size() - 1; i++)
				dis += moves[order[i]][location[order[i + 1]].first][location[order[i + 1]].second];
			if (min > dis) min = dis;
		} while (next_permutation(order.begin(), order.end()));

		printf("%d\n", min);
	}

	return 0;
}