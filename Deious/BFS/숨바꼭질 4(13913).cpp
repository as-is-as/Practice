#include <iostream>
#include <queue>
#include <vector>

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
	vector<int> v;
	q.push(a);

	for (int i = 0; i < 100001; i++)
	{
		check[i] = 1000000;
	}

	check[a] = 0;
	visit[a] = true;

	while (!q.empty())
	{
		int now = q.front();
		q.pop();

		if (now == b)
		{
			cout << check[b] << "\n";
			
			v.push_back(b);

			for (int i = b; i != a; i = route[i])
			{
				v.push_back(i);
			}

			v.push_back(a);

			vector<int>::iterator iter;
			
			for (iter = v.end() - 1; iter != v.begin(); iter--)
			{
				cout << *iter << " ";
			}
			cout << "\n";
		}

		if (now - 1 >= 0 && now - 1 <= 100000 && check[now - 1] > check[now] + 1 && !visit[now -1])
		{
			visit[now - 1] = true;
			route[now - 1] = now;
			check[now - 1] = check[now] + 1;
			q.push(now - 1);
		}

		if (now + 1 >= 0 && now + 1 <= 100000 && check[now + 1] > check[now] + 1 && !visit[now + 1])
		{
			visit[now + 1] = true;
			route[now + 1] = now;
			check[now + 1] = check[now] + 1;
			q.push(now + 1);
		}

		if (now * 2 <= 100000 && check[now * 2] > check[now] + 1 && !visit[now * 2])
		{
			visit[now * 2] = true;
			route[now * 2] = now;
			check[now * 2] = check[now] + 1;
			q.push(now * 2);
		}
	}

	return 0;
}