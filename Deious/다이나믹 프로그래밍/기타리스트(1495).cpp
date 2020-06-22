#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int n, s, m, ans;
int musicList[101];
int check[101][1001];

int checkVolume(int musicNum, int volume)
{
	if (volume < 0 || volume > m)
	{
		return -2;
	}

	if (musicNum == n) return check[musicNum][volume] = volume;

	if (check[musicNum][volume] != -1) return check[musicNum][volume];

	check[musicNum][volume] = max(checkVolume(musicNum + 1, volume + musicList[musicNum]), checkVolume(musicNum + 1, volume - musicList[musicNum]));

	return check[musicNum][volume];
}

int main()
{
	scanf("%d %d %d", &n, &s, &m);

	for (int i = 0; i < n; i++)
	{
		scanf("%d", &musicList[i]);
	}

	memset(check, -1, sizeof(check));

	ans = checkVolume(0, s);

	if (ans == -2)
	{
		printf("%d", -1);
	}
	else
	{
		printf("%d", ans);
	}

	return 0;
}