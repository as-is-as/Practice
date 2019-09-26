#include <cstdio>

int N, count;
int board[15];

bool promising(int row)
{
	for (int i = 0; i < row; i++)
		if (board[i] == board[row] || (board[i] - board[row]) == (row - i) || (board[row] - board[i]) == (row - i)) return false;

	return true;
}

void queens(int row)
{
	if (row == N) count++;
	else
	{
		for (int i = 0; i < N; i++)
		{
			board[row] = i;
			if (promising(row)) queens(row + 1);
		}
	}
}

int main(void)
{
	scanf("%d", &N);
	queens(0);

	printf("%d\n", count);
	return 0;
}