#include <iostream>

using namespace std;

int n;
int chessboard[15][15];
bool checkCol[15];
bool checkDig[40];
bool checkDig2[40];

bool check(int row, int col)
{
	if (checkCol[col]) return false;

	if (checkDig[row + col]) return false;

	if (checkDig2[row - col + n]) return false;

	return true;
}

int count(int row)
{
	if (row == n) return 1;

	int cnt = 0;

	for (int col = 0; col < n; col++)
	{
		if (check(row, col))
		{
			checkDig[row + col] = true;
			checkDig2[row - col + n] = true;
			checkCol[col] = true;
			chessboard[row][col] = true;
			cnt += count(row + 1);
			checkDig[row + col] = false;
			checkDig2[row - col + n] = false;
			checkCol[col] = false;
			chessboard[row][col] = false;
		}
	}

	return cnt;
}

int main()
{
	scanf("%d", &n);
	printf("%d", count(0));

	return 0;
}