#include <iostream>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int N, ans = 0 ,count = 1;
	cin >> N;

	while (count <= N)
	{
		ans += (N - count + 1);
		count *= 10;
	}

	cout << ans << endl;

	return 0;
}