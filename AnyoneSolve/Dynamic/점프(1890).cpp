#include <iostream>

using namespace std;

int map[100][100];
long long d[100][100];
int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	for(int i=0; i<n; ++i)
	{
		for(int j=0; j<n; ++j)
		{
			cin >> map[i][j];
		}
	}

	d[0][0]=1;

	for(int i=0; i<n; ++i)
	{
		for(int j=0; j<n; ++j)
		{
			if(map[i][j] == 0)
				continue;
			if(map[i][j] + j < n )
				d[i][map[i][j]+j] += d[i][j];
			if(map[i][j] + i < n)
				d[i + map[i][j]][j] += d[i][j];
		}
	}

	cout << d[n-1][n-1] << '\n';
	return 0;
}