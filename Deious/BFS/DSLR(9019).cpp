#include <iostream>
#include <queue>
#include <string>
#include <cstring>

using namespace std;

bool visit[10001];

string Bfs(int a, int b)
{
	queue<pair<int, string>> q;
	q.push(make_pair(a, ""));

	while (!q.empty())
	{
		int n = q.front().first;
		string dslr = q.front().second;
		q.pop();

		if (n == b)
		{
			return dslr;
		}

		int num;
		num = (n * 2) % 10000;

		if (!visit[num])
		{
			visit[num] = true;
			q.push(make_pair(num, dslr + "D"));
		}

		num = n == 0 ? 9999 : n - 1;
		if (!visit[num])
		{
			visit[num] = true;
			q.push(make_pair(num, dslr + "S"));
		}

		num = (n % 1000) * 10 + (n / 1000);
		if (!visit[num])
		{
			visit[num] = true;
			q.push(make_pair(num, dslr + "L"));
		}

		num = (n % 10) * 1000 + (n / 10);
		if (!visit[num])
		{
			visit[num] = true;
			q.push(make_pair(num, dslr + "R"));
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int a;

	cin >> a;

	for (int i = 0; i < a; i++)
	{
		int b, c;

		cin >> b >> c;
		cout << Bfs(b, c) << "\n";

		memset(visit, false, sizeof(visit));
	}

	return 0;
}