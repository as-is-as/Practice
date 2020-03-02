#include <cstdio>
#include <queue>
using namespace std;

int main(void)
{
	int T;
	scanf("%d", &T);

	while (T--)
	{
		int N;
		scanf("%d", &N);

		queue<int> q;
		queue<long long> real;
		q.push(1 % N); real.push(1);
		long long ans;
		while (!q.empty())
		{
			int next = q.front(); q.pop();
			int realNext = real.front(); real.pop();
			if (next % N == 0)
			{
				ans = realNext;
				break;
			}

			q.push(next * 10 % N); real.push(realNext * 10);
			q.push((next * 10 + 1) % N); real.push(realNext * 10 + 1);
		}

		printf("%lld\n", ans);
	}

	return 0;
}