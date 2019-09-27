#include <cstdio>
#include <stack>
#include <queue>
using namespace std;

int d[10000][2];
char dslr[10000];

int main(void)
{
	int T;
	scanf("%d", &T);

	while (T--)
	{
		int A, B;
		scanf("%d %d", &A, &B);

		for (int i = 0; i < 10000; i++)
			d[i][0] = d[i][1] = dslr[i] = 0;

		queue<int> q;
		d[A][0] = 1; d[A][1] = -1; q.push(A);
		while (!q.empty())
		{
			int current = q.front(); q.pop();
			if (current == B) break;

			int next = (current * 2) % 10000;
			if (d[next][0] == 0)
			{
				d[next][0] = d[current][0] + 1;
				d[next][1] = current;
				dslr[next] = 'D';
				q.push(next);
			}
			next = (current + 9999) % 10000;
			if (d[next][0] == 0)
			{
				d[next][0] = d[current][0] + 1;
				d[next][1] = current;
				dslr[next] = 'S';
				q.push(next);
			}
			next = current / 1000;
			next += (current % 1000) * 10;
			if (d[next][0] == 0)
			{
				d[next][0] = d[current][0] + 1;
				d[next][1] = current;
				dslr[next] = 'L';
				q.push(next);
			}
			next = (current % 10) * 1000;
			next += current / 10;
			if (d[next][0] == 0)
			{
				d[next][0] = d[current][0] + 1;
				d[next][1] = current;
				dslr[next] = 'R';
				q.push(next);
			}
		}

		stack<char> path;
		int next = d[B][1];
		path.push(dslr[B]);
		while (d[next][1] != -1)
		{
			path.push(dslr[next]);
			next = d[next][1];
		}
		while (!path.empty()) { printf("%c", path.top()); path.pop(); }
		printf("\n");
	}

	return 0;
}