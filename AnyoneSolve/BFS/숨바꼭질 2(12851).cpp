#include <iostream>
#include <queue>
using namespace std;

int map[100001][2];
int n, k;

void GetResult()
{
	queue<pair<int, int>> tempQ;
	tempQ.push(make_pair(n, 0));

	if (n == k)
	{
		map[k][0] = 0;
		map[k][1] = 1;
		return;
	}
	while (!tempQ.empty())
	{
		int mov = tempQ.front().first;
		int minTime = tempQ.front().second;
		tempQ.pop();

		if (mov * 2 <= 100000)
		{
			if (map[mov * 2][0] == 0)
			{
				map[mov * 2][0] = minTime + 1;
				map[mov * 2][1] = 1;
				tempQ.push(make_pair(mov * 2, minTime + 1));
			}
			else if (map[mov * 2][0] == minTime + 1)
			{
				map[mov * 2][0] = minTime + 1;
				++map[mov * 2][1];
				tempQ.push(make_pair(mov * 2, minTime + 1));
			}
		}
		if (mov + 1 <= 100000)
		{
			if (map[mov + 1][0] == 0)
			{
				map[mov + 1][0] = minTime + 1;
				map[mov + 1][1] = 1;
				tempQ.push(make_pair(mov + 1, minTime + 1));
			}
			else if (map[mov + 1][0] == minTime + 1)
			{
				map[mov + 1][0] = minTime + 1;
				++map[mov + 1][1];
				tempQ.push(make_pair(mov + 1, minTime + 1));
			}
		}
		if (mov - 1 >= 0)
		{
			if (map[mov - 1][0] == 0)
			{
				map[mov - 1][0] = minTime + 1;
				map[mov - 1][1] = 1;
				tempQ.push(make_pair(mov - 1, minTime + 1));
			}
			else if (map[mov - 1][0] == minTime + 1)
			{
				map[mov - 1][0] = minTime + 1;
				++map[mov - 1][1];
				tempQ.push(make_pair(mov - 1, minTime + 1));
			}
		}

	}
}

int main(void)
{
	cin >> n >> k;
	GetResult();

	cout << map[k][0] << "\n" << map[k][1];
	return 0;
}