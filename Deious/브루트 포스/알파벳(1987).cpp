#include <iostream>
#include <vector>
#include <string>
using namespace std;

int ans = 0;
int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };
bool check[26];

void go(vector<vector<char>> &board, int x, int y, int cnt, int r, int c)
{
	int nx;
	int ny;
	if (cnt > ans)
	{
		ans = cnt;
	}

	for (int i = 0; i < 4; i++)
	{
		nx = x + dx[i];
		ny = y + dy[i];

		if (nx >= 0 && nx < r && ny >= 0 && ny < c)
		{
			if (check[board[nx][ny] - 'A'] == false)
			{
				check[board[nx][ny] - 'A'] = true;
				go(board, nx, ny, cnt + 1, r, c);
				check[board[nx][ny] - 'A'] = false;
			}
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int r, c;
	cin >> r >> c;

	vector<vector<char>> board(r);
	char s;

	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			cin >> s;
			board[i].push_back(s);
		}
	}

	check[board[0][0] - 'A'] = true;
	go(board, 0, 0, 1, r, c);

	cout << ans;

	return 0;
}