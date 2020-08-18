#include <cstdio>
#include <queue>
#include <string>

using namespace std;

char map[102][102];
bool check[102][102];
bool key[26];

int h, w;

int dx[] = { 0, 0, -1, 1 };
int dy[] = { 1, -1, 0, 0 };

bool InRange(int x, int y)
{
	return x >= 0 && x <= h + 1 && y >= 0 && y <= w + 1;
}

int main(void)
{
	int a;
	scanf("%d", &a);

	while (a--)
	{
		int answer = 0;

		scanf("%d %d", &h, &w);

		for (int i = 0; i <= h + 1; i++)
		{
			for (int j = 0; j <= w + 1; j++)
			{
				map[i][j] = '.';
			}
		}

		for (int i = 1; i <= h; i++)
		{
			for (int j = 1; j <= w; j++)
			{
				scanf(" %1c", &map[i][j]);
			}
		}
		string alphabet;
		scanf("%s", &alphabet);

		for (int i = 0; i < alphabet.size(); i++)
		{
			if (alphabet[i] >= 'a' && alphabet[i] <= 'z')
			{
				key[alphabet[i] - 'a'] = true;
			}
		}

		queue<pair<int, int>> q;
		queue<pair<int, int>> door[26];
		q.push(make_pair(0, 0));
		check[0][0] = true;

		while (!q.empty())
		{
			int x = q.front().first;
			int y = q.front().second;
			q.pop();

			for (int i = 0; i < 4; i++)
			{
				int nx = x + dx[i];
				int ny = y + dy[i];

				if (InRange(nx, ny) && !check[nx][ny])
				{
					check[nx][ny] = true;
					int temp = map[nx][ny] - 'a';
					int tempA = map[nx][ny] - 'A';

					if (map[nx][ny] == '.')
					{
						q.push(make_pair(nx, ny));
					}
					else if (map[nx][ny] >= 'A' && map[nx][ny] <= 'Z')
					{
						if (key[tempA])
						{
							q.push(make_pair(nx, ny));
						}
						else
						{
							door[tempA].push(make_pair(nx, ny));
						}
					}
					else if (map[nx][ny] >= 'a' && map[nx][ny] <= 'z')
					{
						q.push(make_pair(nx, ny));

						if (!key[temp])
						{
							key[temp] = true;

							while (!door[temp].empty())
							{
								q.push(door[temp].front());
								door[temp].pop();
							}
						}
					}
					else
					{
						if (map[nx][ny] == '$')
						{
							q.push(make_pair(nx, ny));
							answer++;
						}
					}
				}
			}
		}
		printf("%d", answer);
	}

	return 0;
}