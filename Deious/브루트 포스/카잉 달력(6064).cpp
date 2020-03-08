#include <iostream>

using namespace std;

void solve(int M, int N, int x, int y)
{
	x--;
	y--;

	for (int i = 0; i < N; i++)
	{
		int ans = M * i + x;

		if (ans % N == y)
		{
			cout << ans + 1 << "\n";
			return;
		}
	}
	cout << "-1\n";

	return;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int T, M, N, x, y;

	cin >> T;

	for (int i = 0; i < T; i++)
	{
		cin >> M >> N >> x >> y;
		solve(M, N, x, y);
	}

	return 0;
}