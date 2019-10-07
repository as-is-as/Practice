#include <cstdio>
#include <deque>
using namespace std;

int board[9][9];
deque<pair<int, int>> blanks;
bool ending;

void FillBlank(void)
{
	if (blanks.empty())
	{
		ending = true;
		return;
	}

	pair<int, int> blank = blanks.front();
	bool check[10];
	for (int i = 1; i < 10; i++) check[i] = true;

	for (int i = 0; i < 9; i++) check[board[blank.first][i]] = false;
	for (int i = 0; i < 9; i++) check[board[i][blank.second]] = false;
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
			check[board[i + blank.first / 3 * 3][j + blank.second / 3 * 3]] = false;

	for (int i = 1; i < 10; i++)
		if (check[i])
		{
			blanks.pop_front();
			board[blank.first][blank.second] = i;
			FillBlank();
			if (ending) return;
			board[blank.first][blank.second] = 0;
			blanks.push_front(blank);
		}
}

int main(void)
{
	for (int i = 0; i < 9; i++)
		for (int j = 0; j < 9; j++)
		{
			scanf("%d", &board[i][j]);
			if (board[i][j] == 0) blanks.push_back(make_pair(i, j));
		}

	FillBlank();

	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
			printf("%d ", board[i][j]);
		printf("\n");
	}

	return 0;
}