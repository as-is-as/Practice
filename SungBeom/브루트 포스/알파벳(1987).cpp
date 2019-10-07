#include <cstdio>
#include <stack>
using namespace std;

int R, C;
char board[20][20];
bool check[26];

int dx[] = { -1, 1, 0, 0 };
int dy[] = { 0, 0, -1, 1 };

int maxCount;

bool InRange(int x, int y)
{
	return x >= 0 && x < R && y >= 0 && y < C;
}

void Move(int x, int y, int count)
{
	if (maxCount < count) maxCount = count;

	for (int i = 0; i < 4; i++)
	{
		int nx = x + dx[i], ny = y + dy[i];
		if (InRange(nx, ny) && !check[board[nx][ny] - 'A'])
		{

			check[board[nx][ny] - 'A'] = true;
			Move(nx, ny, count + 1);
			check[board[nx][ny] - 'A'] = false;
		}
	}
}

int main(void)
{
	scanf("%d %d", &R, &C);
	for (int i = 0; i < R; i++)
		for (int j = 0; j < C; j++)
			scanf(" %c", &board[i][j]);

	check[board[0][0] - 'A'] = true;
	Move(0, 0, 1);

	printf("%d\n", maxCount);
	return 0;
}