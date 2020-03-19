#include <iostream>

using namespace std;

int gameGround[100][100];
long long moveCount[100][100];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int N;
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> gameGround[i][j];
		}
	}

	moveCount[0][0] = 1;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			for (int k = 0; k < j; k++)
			{
				if (gameGround[i][k] == (j - k))
				{
					moveCount[i][j] += moveCount[i][k];
				}
			}

			for (int k = 0; k < i; k++)
			{
				if (gameGround[k][j] == (i - k))
				{
					moveCount[i][j] += moveCount[k][j];
				}
			}
		}
	}

	cout << moveCount[N-1][N-1] << "\n";

	return 0;
}