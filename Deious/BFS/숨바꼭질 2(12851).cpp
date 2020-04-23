#include <iostream>
#include <queue>

using namespace std;

int check[100001];
int route[100001];
bool visit[100001];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int a, b;
	cin >> a >> b;

	queue<int> q;
	q.push(a);

	for (int i = 0; i < 100001; i++)
	{
		check[i] = 1000000;
	}

	check[a] = 0;
	route[a] = 1;
	visit[a] = true;

	while (!q.empty())
	{
		int now = q.front();
		q.pop();

		if (now - 1 >= 0 && check[now - 1] > check[now] + 1 && !visit[now - 1])
		{
			check[now - 1] = true;
			check[now - 1] = check[now] + 1;
			route[now - 1] = route[now];
			q.push(now - 1);
		}
		else if (now - 1 >= 0 && check[now - 1] == check[now] + 1)
		{
			route[now - 1] += route[now];
		}

		if (now + 1 <= 100000 && check[now + 1] > check[now] + 1 && !visit[now + 1])
		{
			check[now + 1] = true;
			check[now + 1] = check[now] + 1;
			route[now + 1] = route[now];
			q.push(now + 1);
		}
		else if (now + 1 <= 100000 && check[now + 1] == check[now] + 1)
		{
			route[now + 1] += route[now];
		}

		if (now * 2 <= 100000 && check[now * 2] > check[now] + 1 && !visit[now * 2])
		{
			check[now * 2] = true;
			check[now * 2] = check[now] + 1;
			route[now * 2] = route[now];
			q.push(now * 2);
		}
		else if (now * 2 <= 100000 && check[now * 2] == check[now] + 1)
		{
			route[now * 2] += route[now];
		}
	}

	cout << check[b] << "\n" << route[b];

	return 0;
}