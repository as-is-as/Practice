#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int N, M;

int MoveUp(vector<vector<char>>, pair<int, int>, pair<int, int>, int);
int MoveDown(vector<vector<char>>, pair<int, int>, pair<int, int>, int);
int MoveLeft(vector<vector<char>>, pair<int, int>, pair<int, int>, int);
int MoveRight(vector<vector<char>>, pair<int, int>, pair<int, int>, int);

void PrintBoard(vector<vector<char>>& board)
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
			printf("%c", board[i][j]);
		printf("\n");
	}
}

int MoveUp(vector<vector<char>> board, pair<int, int> red, pair<int, int> blue, int count)
{
	if (count > 10) return -1;

	if (red.second == blue.second && red.first > blue.first)
	{
		board[blue.first][blue.second] = '.';
		while (blue.first > 0 && board[blue.first - 1][blue.second] == '.') blue.first--;
		if (blue.first > 0 && board[blue.first - 1][blue.second] == 'O') return -1;
		board[blue.first][blue.second] = 'B';

		board[red.first][red.second] = '.';
		while (red.first > 0 && board[red.first - 1][red.second] == '.') red.first--;
		if (red.first > 0 && board[red.first - 1][red.second] == 'O') return count;
		board[red.first][red.second] = 'R';
	}
	else
	{
		board[red.first][red.second] = '.';
		while (red.first > 0 && board[red.first - 1][red.second] == '.') red.first--;
		board[red.first][red.second] = 'R';

		board[blue.first][blue.second] = '.';
		while (blue.first > 0 && board[blue.first - 1][blue.second] == '.') blue.first--;
		board[blue.first][blue.second] = 'B';

		if (red.first > 0 && board[red.first - 1][red.second] == 'O')
		{
			if (red.second == blue.second && red.first == blue.first - 1) return -1;
			else return count;
		}
	}
	if (blue.first > 0 && board[blue.first - 1][blue.second] == 'O') return -1;

	int left = MoveLeft(board, red, blue, count + 1), right = MoveRight(board, red, blue, count + 1);
	if (left != -1 && right != -1)
	{
		if (left < right) return left;
		else return right;
	}
	else if (left == -1)
		return right;
	else
		return left;
}

int MoveDown(vector<vector<char>> board, pair<int, int> red, pair<int, int> blue, int count)
{
	if (count > 10) return -1;

	if (red.second == blue.second && red.first < blue.first)
	{
		board[blue.first][blue.second] = '.';
		while (blue.first < N - 1 && board[blue.first + 1][blue.second] == '.') blue.first++;
		if (blue.first < N - 1 && board[blue.first + 1][blue.second] == 'O') return -1;
		board[blue.first][blue.second] = 'B';

		board[red.first][red.second] = '.';
		while (red.first < N - 1 && board[red.first + 1][red.second] == '.') red.first++;
		if (red.first < N - 1 && board[red.first + 1][red.second] == 'O') return count;
		board[red.first][red.second] = 'R';
	}
	else
	{
		board[red.first][red.second] = '.';
		while (red.first < N - 1 && board[red.first + 1][red.second] == '.') red.first++;
		board[red.first][red.second] = 'R';

		board[blue.first][blue.second] = '.';
		while (blue.first < N - 1 && board[blue.first + 1][blue.second] == '.') blue.first++;
		board[blue.first][blue.second] = 'B';

		if (red.first < N - 1 && board[red.first + 1][red.second] == 'O')
		{
			if (red.second == blue.second && red.first == blue.first + 1) return -1;
			else return count;
		}
	}
	if (blue.first < N - 1 && board[blue.first + 1][blue.second] == 'O') return -1;

	int left = MoveLeft(board, red, blue, count + 1), right = MoveRight(board, red, blue, count + 1);
	if (left != -1 && right != -1)
	{
		if (left < right) return left;
		else return right;
	}
	else if (left == -1)
		return right;
	else
		return left;
}

int MoveLeft(vector<vector<char>> board, pair<int, int> red, pair<int, int> blue, int count)
{
	if (count > 10) return -1;

	if (red.first == blue.first && red.second > blue.second)
	{
		board[blue.first][blue.second] = '.';
		while (blue.second > 0 && board[blue.first][blue.second - 1] == '.') blue.second--;
		if (blue.second > 0 && board[blue.first][blue.second - 1] == 'O') return -1;
		board[blue.first][blue.second] = 'B';

		board[red.first][red.second] = '.';
		while (red.second > 0 && board[red.first][red.second - 1] == '.') red.second--;
		if (red.second > 0 && board[red.first][red.second - 1] == 'O') return count;
		board[red.first][red.second] = 'R';
	}
	else
	{
		board[red.first][red.second] = '.';
		while (red.second > 0 && board[red.first][red.second - 1] == '.') red.second--;
		board[red.first][red.second] = 'R';

		board[blue.first][blue.second] = '.';
		while (blue.second > 0 && board[blue.first][blue.second - 1] == '.') blue.second--;
		board[blue.first][blue.second] = 'B';

		if (red.second > 0 && board[red.first][red.second - 1] == 'O')
		{
			if (red.first == blue.first && red.second == blue.second - 1) return -1;
			else return count;
		}
	}
	if (blue.second > 0 && board[blue.first][blue.second - 1] == 'O') return -1;

	int up = MoveUp(board, red, blue, count + 1), down = MoveDown(board, red, blue, count + 1);
	if (up != -1 && down != -1)
	{
		if (up < down) return up;
		else return down;
	}
	else if (up == -1)
		return down;
	else
		return up;
}

int MoveRight(vector<vector<char>> board, pair<int, int> red, pair<int, int> blue, int count)
{
	if (count > 10) return -1;

	if (red.first == blue.first && red.second < blue.second)
	{
		board[blue.first][blue.second] = '.';
		while (blue.second < M - 1 && board[blue.first][blue.second + 1] == '.') blue.second++;
		if (blue.second < M - 1 && board[blue.first][blue.second + 1] == 'O') return -1;
		board[blue.first][blue.second] = 'B';

		board[red.first][red.second] = '.';
		while (red.second < M - 1 && board[red.first][red.second + 1] == '.') red.second++;
		if (red.second < M - 1 && board[red.first][red.second + 1] == 'O') return count;
		board[red.first][red.second] = 'R';
	}
	else
	{
		board[red.first][red.second] = '.';
		while (red.second < M - 1 && board[red.first][red.second + 1] == '.') red.second++;
		board[red.first][red.second] = 'R';

		board[blue.first][blue.second] = '.';
		while (blue.second < M - 1 && board[blue.first][blue.second + 1] == '.') blue.second++;
		board[blue.first][blue.second] = 'B';

		if (red.second < M - 1 && board[red.first][red.second + 1] == 'O')
		{
			if (red.first == blue.first && red.second == blue.second + 1) return -1;
			else return count;
		}
	}
	if (blue.second < M - 1 && board[blue.first][blue.second + 1] == 'O') return -1;

	int up = MoveUp(board, red, blue, count + 1), down = MoveDown(board, red, blue, count + 1);
	if (up != -1 && down != -1)
	{
		if (up < down) return up;
		else return down;
	}
	else if (up == -1)
		return down;
	else
		return up;
}

int main(void)
{
	scanf("%d %d", &N, &M);

	vector<vector<char>> board(N, vector<char>(M));
	pair<int, int> red, blue, ending;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
		{
			scanf(" %c", &board[i][j]);
			if (board[i][j] == 'R') red = make_pair(i, j);
			else if (board[i][j] == 'B') blue = make_pair(i, j);
			else if (board[i][j] == 'O') ending = make_pair(i, j);
		}

	int up = MoveUp(board, red, blue, 1), down = MoveDown(board, red, blue, 1),
		left = MoveLeft(board, red, blue, 1), right = MoveRight(board, red, blue, 1);
	if (up == -1) up = 11;
	if (down == -1) down = 11;
	if (left == -1) left = 11;
	if (right == -1) right = 11;

	vector<int> nums;
	nums.push_back(up); nums.push_back(down); nums.push_back(left); nums.push_back(right);
	int min = *min_element(nums.begin(), nums.end());

	if (min == 11) printf("%d\n", -1);
	else printf("%d\n", min);
	return 0;
}