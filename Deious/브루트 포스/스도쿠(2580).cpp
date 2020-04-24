#include <iostream>

using namespace std;

int board[9][9];
bool row[9][9];
bool col[9][9];
bool square[9][9];
bool ending;

void check(int cnt)
{
	int x = cnt / 9;
	int y = cnt % 9;

	if (ending) return;

	if (cnt == 81)
	{
		ending = true;

		for (int i = 0; i < 9; i++)
		{
			for (int j = 0; j < 9; j++)
			{
				cout << board[i][j] << " ";
			}
			cout << "\n";
		}

		return;
	}

	if (board[x][y] == 0)
	{
		for (int i = 1; i <= 9; i++)
		{
			if (row[x][i] == false && col[y][i] == false && square[(x / 3) * 3 + (y / 3)][i] == false)
			{
				row[x][i] = true;
				col[y][i] = true;
				square[(x / 3) * 3 + (y / 3)][i] = true;
				board[x][y] = i;
				check(cnt + 1);
				board[x][y] = 0;
				row[x][i] = false;
				col[y][i] = false;
				square[(x / 3) * 3 + (y / 3)][i] = false;
			}
		}
	}
	else check(cnt + 1);

}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			cin >> board[i][j];

			if (board[i][j] != 0)
			{
				row[i][board[i][j]] = true;
				col[j][board[i][j]] = true;
				square[(i / 3) * 3 + (j / 3)][board[i][j]] = true;
			}
		}
	}

	check(0);

	return 0;
}