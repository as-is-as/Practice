#include <cstdio>
#include <vector>
#include <stack>
using namespace std;

char map[102][102];
int check[102][102];
bool key[26];

int h, w;

int dx[] = { -1, 1, 0, 0 };
int dy[] = { 0, 0, -1, 1 };

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
				check[i][j] = false;
			}
		for (int i = 0; i < 26; i++) key[i] = false;

		for (int i = 1; i <= h; i++)
			for (int j = 1; j <= w; j++)
				scanf(" %c", &map[i][j]);

		char alpha;
		getchar();
		while (scanf("%c", &alpha))
		{
			if (alpha == '\n' || alpha == '0') break;
			else key[alpha - 'a'] = true;
		}

		stack<pair<int, int>> s;
		s.push(make_pair(0, 0)); check[0][0] = true;
		
		vector<pair<int, int>> doors;
		int count = 0;
		while (!s.empty())
		{
			pair<int, int> next = s.top(); s.pop();

			for (int i = 0; i < 4; i++)
			{
				int nx = next.first + dx[i], ny = next.second + dy[i];

				if (InRange(nx, ny) && !check[nx][ny])
				{
					check[nx][ny] = true;

					if (map[nx][ny] == '.')
						s.push(make_pair(nx, ny));
					else if (map[nx][ny] >= 'a' && map[nx][ny] <= 'z')
					{
						s.push(make_pair(nx, ny));
						key[map[nx][ny] - 'a'] = true;

						for (vector<pair<int, int>>::iterator it = doors.begin(); it != doors.end();)
						{
							if (key[map[it->first][it->second] - 'A'])
							{
								s.push(make_pair(it->first, it->second));
								it = doors.erase(it);
							}
							else it++;
						}
					}
					else if (map[nx][ny] >= 'A' && map[nx][ny] <= 'Z')
					{
						if (key[map[nx][ny] - 'A'])
							s.push(make_pair(nx, ny));
						else
							doors.push_back(make_pair(nx, ny));
					}
					else if (map[nx][ny] == '$')
					{
						s.push(make_pair(nx, ny));
						count++;
					}
				}
			}
		}

		printf("%d\n", count);
	}

	return 0;
}