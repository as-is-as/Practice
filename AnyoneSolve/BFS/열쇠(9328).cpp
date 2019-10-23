#include <iostream>
#include <queue>
#include <vector>
#include <set>
#include <cstring>
#include <string>
using namespace std;

char building_map[102][102];
int building[102][102];

int movX[] = {0, 0, -1, 1};
int movY[] = {-1, 1, 0, 0};

int h, w;

int BFS(set<char> &key_case)
{
	int document_count = 0;
	queue<pair<int, int>> temp_q;
	vector<pair<int, int>> lock_case;

	temp_q.push(make_pair(0, 0));
	building[0][0] = 0;

	while (!temp_q.empty())
	{
		int tempX = temp_q.front().first;
		int tempY = temp_q.front().second;
		temp_q.pop();

		for (int i = 0; i < 4; ++i)
		{
			int x = tempX + movX[i];
			int y = tempY + movY[i];

			if (x >= 0 && x <= h + 1 && y >= 0 && y <= w + 1)
			{
				if (building_map[x][y] == '*')	continue;
				if (building[x][y] == -1)
				{
					if (building_map[x][y] == '.')
					{
						building[x][y] = 0;
						temp_q.push(make_pair(x, y));
						continue;
					}
					if (building_map[x][y] >= 'a' && building_map[x][y] <= 'z')
					{
						building[x][y] = 0;
						temp_q.push(make_pair(x, y));
						key_case.insert(building_map[x][y]);
						continue;
					}
					if (building_map[x][y] >= 'A' && building_map[x][y] <= 'Z')
					{
						if (key_case.count(building_map[x][y] + 32))
						{
							building[x][y] = 0;
							temp_q.push(make_pair(x, y));
						}
						else
						{
							building[x][y] = 1;
							lock_case.push_back(make_pair(x, y));
						}
						continue;
					}
					if (building_map[x][y] == '$')
					{
						building[x][y] = 0;
						++document_count;
						temp_q.push(make_pair(x, y));
					}
				}
			}
		}
		for (auto it = lock_case.begin(); it != lock_case.end(); ++it)
		{
			if (key_case.count(building_map[it->first][it->second] + 32) && building[it->first][it->second] == 1)
			{
				temp_q.push(make_pair(it->first, it->second));
				building[it->first][it->second] = 0;
			}
		}
	}

	return document_count;
}
int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	int t;
	cin >> t;

	while (t--)
	{
		cin >> h >> w;
		memset(building, -1, sizeof(building));
		
		for (int i = 0; i <= h + 1; ++i)
		{
			if (i == 0 || i == h + 1)
				for (int j = 0; j <= w + 1; ++j)
				{
					building_map[i][j] = '.';
				}
			else
			{
				building_map[i][0] = '.';
				building_map[i][w + 1] = '.';

				for (int j = 1; j <= w; ++j)
				{
					cin >> building_map[i][j];
				}
			}
		}

		string str_key;
		cin >> str_key;
		set<char> key_case;

		for (int i = 0; i < str_key.length(); ++i)
		{
			key_case.insert(str_key[i]);
		}
        
		int doc = BFS(key_case);

		cout << doc << '\n';
	}
	return 0;
}