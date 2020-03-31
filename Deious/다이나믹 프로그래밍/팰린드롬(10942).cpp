#include <iostream>

using namespace std;

int a[2001];
int d[2001][2001];

int check(int i, int j)
{
	if (i == j)
	{
		return 1;
	}
	else if (i + 1 == j)
	{
		if (a[i] == a[j])
		{
			return 1;
		}
		else
		{
			return 0;
		}
	}

	if (d[i][j] >= 0)
	{
		return d[i][j];
	}

	if (a[i] != a[j])
	{
		return d[i][j] = 0;
	}
	else
	{
		return d[i][j] = check(i + 1, j - 1);
	}

}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int b, c;
	cin >> b;

	for (int i = 1; i <= b; i++)
	{
		cin >> a[i];
	}

	for (int i = 1; i <= b; i++)
	{
		for (int j = 1; j <= b; j++)
		{
			d[i][j] = -1;
		}
	}
	cin >> c;

	while (c--)
	{
		int e, f;
		cin >> e >> f;
		cout << check(e, f) << "\n";
	}

	return 0;
}