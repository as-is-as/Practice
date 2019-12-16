#include <cstdio>
#include <queue>
using namespace std;

vector<vector<int>> board(20, vector<int>(20));
int N, maxNum;

void Move(vector<vector<int>> nextBoard, int direction, int count)
{
	if (direction == 0)
	{
		for (int j = 0; j < N; j++)
		{
			queue<int> q;
			for (int k = 0; k < N; k++)
				if (nextBoard[k][j] != 0) q.push(nextBoard[k][j]);

			int next, index = 0;
			while (!q.empty())
			{
				int next = q.front(); q.pop();
				if (q.empty()) nextBoard[index][j] = next;
				else if (next != q.front()) nextBoard[index][j] = next;
				else
				{
					nextBoard[index][j] = next * 2;
					q.pop();
				}

				index++;
			}
			while (index < N) nextBoard[index++][j] = 0;
		}
	}
	else if (direction == 1)
	{
		for (int j = 0; j < N; j++)
		{
			queue<int> q;
			for (int k = N - 1; k >= 0; k--)
				if (nextBoard[k][j] != 0) q.push(nextBoard[k][j]);

			int next, index = N - 1;
			while (!q.empty())
			{
				int next = q.front(); q.pop();
				if (q.empty()) nextBoard[index][j] = next;
				else if (next != q.front()) nextBoard[index][j] = next;
				else
				{
					nextBoard[index][j] = next * 2;
					q.pop();
				}

				index--;
			}
			while (index >= 0) nextBoard[index--][j] = 0;
		}
	}
	else if (direction == 2)
	{
		for (int j = 0; j < N; j++)
		{
			queue<int> q;
			for (int k = N - 1; k >= 0; k--)
				if (nextBoard[j][k] != 0) q.push(nextBoard[j][k]);

			int next, index = N - 1;
			while (!q.empty())
			{
				int next = q.front(); q.pop();
				if (q.empty()) nextBoard[j][index] = next;
				else if (next != q.front()) nextBoard[j][index] = next;
				else
				{
					nextBoard[j][index] = next * 2;
					q.pop();
				}

				index--;
			}
			while (index >= 0) nextBoard[j][index--] = 0;
		}
	}
	else if (direction == 3)
	{
		for (int j = 0; j < N; j++)
		{
			queue<int> q;
			for (int k = 0; k < N; k++)
				if (nextBoard[j][k] != 0) q.push(nextBoard[j][k]);

			int next, index = 0;
			while (!q.empty())
			{
				int next = q.front(); q.pop();
				if (q.empty()) nextBoard[j][index] = next;
				else if (next != q.front()) nextBoard[j][index] = next;
				else
				{
					nextBoard[j][index] = next * 2;
					q.pop();
				}

				index++;
			}
			while (index < N) nextBoard[j][index++] = 0;
		}
	}

	if (count == 5)
	{
		int tempMaxNum = 0;
		for (int i = 0; i < N; i++)
			for (int j = 0; j < N; j++)
				if (tempMaxNum < nextBoard[i][j]) tempMaxNum = nextBoard[i][j];

		if (maxNum < tempMaxNum) maxNum = tempMaxNum;
	}
	else
		for (int i = 0; i < 4; i++)
			Move(nextBoard, i, count + 1);
}

int main(void)
{
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			scanf("%d", &board[i][j]);

	for (int i = 0; i < 4; i++)
		Move(board, i, 1);

	printf("%d\n", maxNum);
	return 0;
}