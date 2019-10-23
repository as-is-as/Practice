#include <cstdio>
#include <queue>
#include <map>
using namespace std;

int puzzle[3][3];
map<int, int> check;

int dx[] = { -1, 1, 0, 0 };
int dy[] = { 0, 0, -1, 1 };

bool InRange(int x, int y)
{
	return x >= 0 && x < 3 && y >= 0 && y < 3;
}

int GetValue(void)
{
	int value = 0;

	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
		{
			value *= 10;
			value += puzzle[i][j];
		}

	return value;
}

void SetValue(int value)
{
	int unit = 100000000;

	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
		{
			puzzle[i][j] = value / unit;
			value %= unit;
			unit /= 10;
		}
}

int main(void)
{
	pair<int, int> start;
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
		{
			scanf("%d", &puzzle[i][j]);
			if (puzzle[i][j] == 0) start = make_pair(i, j);
		}

	queue<pair<pair<int, int>, int>> q; q.push(make_pair(start, GetValue()));
	check.insert(make_pair(GetValue(), 0));

	bool ending = false;
	int count = 0;
	while (!q.empty())
	{
		pair<pair<int, int>, int> current = q.front(); q.pop();
		if (current.second == 123456780)
		{
			ending = true;
			break;
		}

		SetValue(current.second);
		int count = check[current.second];
		for (int i = 0; i < 4; i++)
		{
			int nx = current.first.first + dx[i], ny = current.first.second + dy[i];
			if (InRange(nx, ny))
			{
				int temp = puzzle[nx][ny];
				puzzle[nx][ny] = puzzle[current.first.first][current.first.second];
				puzzle[current.first.first][current.first.second] = temp;
				int value = GetValue();

				pair<map<int, int>::iterator, bool> in = check.insert(make_pair(value, count + 1));
				if (in.second) q.push(make_pair(make_pair(nx, ny), value));

				temp = puzzle[nx][ny];
				puzzle[nx][ny] = puzzle[current.first.first][current.first.second];
				puzzle[current.first.first][current.first.second] = temp;
			}
		}
	}

	if (ending) printf("%d\n", check[123456780]);
	else printf("-1\n");
	return 0;
}