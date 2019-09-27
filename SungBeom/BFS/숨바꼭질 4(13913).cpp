#include <cstdio>
#include <stack>
#include <queue>
using namespace std;

int position[100001][2];

int main(void)
{
	int N, K;
	scanf("%d %d", &N, &K);

	queue<int> q;
	position[N][0] = 1; position[N][1] = -1; q.push(N);
	while (!q.empty())
	{
		int current = q.front(); q.pop();
		if (current == K) break;

		if (current - 1 >= 0 && position[current - 1][0] == 0)
		{
			position[current - 1][0] = position[current][0] + 1;
			position[current - 1][1] = current;
			q.push(current - 1);
		}
		if (current + 1 < 100001 && position[current + 1][0] == 0)
		{
			position[current + 1][0] = position[current][0] + 1;
			position[current + 1][1] = current;
			q.push(current + 1);
		}
		if (current * 2 < 100001 && position[current * 2][0] == 0)
		{
			position[current * 2][0] = position[current][0] + 1;
			position[current * 2][1] = current;
			q.push(current * 2);
		}
	}

	printf("%d\n", position[K][0] - 1);

	stack<int> path;
	int next = K;
	path.push(next);
	while (position[next][1] != -1)
	{
		path.push(position[next][1]);
		next = position[next][1];
	}
	while (!path.empty()) { printf("%d ", path.top()); path.pop(); }
	return 0;
}