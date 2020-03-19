#include <iostream>

using namespace std;

int candyMap[1001][1001];
int totalCandy[1001][1001];

int MaxCheck(int a, int b, int c)
{
	return a > b ? (a > c ? a : c ) : b > c ? b : c;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int N, M;

	cin >> N >> M;

	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= M; j++)
		{
			cin >> candyMap[i][j];
		}
	}

	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= M; j++)
		{
			totalCandy[i][j] = MaxCheck(totalCandy[i - 1][j], totalCandy[i - 1][j - 1], totalCandy[i][j - 1]) + candyMap[i][j];
		}
	}

	cout << totalCandy[N][M] << "\n";

	return 0;
}