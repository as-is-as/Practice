#include <iostream>
#include <queue>
using namespace std;

int position[100001];
int d[100001];

int main(void)
{
	int N, K;
	scanf("%d %d", &N, &K);

	queue<int> q;
	position[N] = 1; q.push(N); d[N] = 1;
	int count = 0;
	while (!q.empty())
	{
		int current = q.front(); q.pop();
		if (position[K] != 0 && position[current] > position[K]) continue;

		if (current - 1 >= 0)
		{
			if (position[current - 1] == 0)
			{
				position[current - 1] = position[current] + 1;
				q.push(current - 1);
				d[current - 1] = d[current];
			}
			else if (position[current - 1] == position[current] + 1) d[current - 1] += d[current];
		}
		if (current + 1 < 100001)
		{
			if (position[current + 1] == 0)
			{
				position[current + 1] = position[current] + 1;
				q.push(current + 1);
				d[current + 1] = d[current];
			}
			else if (position[current + 1] == position[current] + 1) d[current + 1] += d[current];
		}
		if (current * 2 < 100001)
		{
			if (position[current * 2] == 0)
			{
				position[current * 2] = position[current] + 1;
				q.push(current * 2);
				d[current * 2] = d[current];
			}
			else if (position[current * 2] == position[current] + 1) d[current * 2] += d[current];
		}
	}

	printf("%d\n%d\n", position[K] - 1, d[K]);
	return 0;
}