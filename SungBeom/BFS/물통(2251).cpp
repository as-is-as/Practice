#include <cstdio>
#include <queue>
#include <set>
using namespace std;

bool check[201][201];

int main(void)
{
	int A, B, C;
	scanf("%d %d %d", &A, &B, &C);

	queue<pair<int, int>> q; q.push(make_pair(0, 0));
	check[0][0] = true;
	set<int> volume;
	while (!q.empty())
	{
		pair<int, int> current = q.front(); q.pop();
		if (current.first == 0) volume.insert(C - current.first - current.second);
		int nextA, nextB;

		if (current.first + current.second > B)
		{
			nextA = current.first + current.second - B; nextB = B;
			if (!check[nextA][nextB]) { q.push(make_pair(nextA, nextB)); check[nextA][nextB] = true; }
		}
		else
		{
			nextA = 0; nextB = current.first + current.second;
			if (!check[nextA][nextB]) { q.push(make_pair(nextA, nextB)); check[nextA][nextB] = true; }
		}

		nextA = 0; nextB = current.second;
		if (!check[nextA][nextB]) { q.push(make_pair(nextA, nextB)); check[nextA][nextB] = true; }

		if (current.first + current.second > A)
		{
			nextA = A; nextB = current.first + current.second - A;
			if (!check[nextA][nextB]) { q.push(make_pair(nextA, nextB)); check[nextA][nextB] = true; }
		}
		else
		{
			nextA = current.first + current.second; nextB = 0;
			if (!check[nextA][nextB]) { q.push(make_pair(nextA, nextB)); check[nextA][nextB] = true; }
		}

		nextA = current.first; nextB = 0;
		if (!check[nextA][nextB]) { q.push(make_pair(nextA, nextB)); check[nextA][nextB] = true; }

		if (A > C - current.second)
		{
			nextA = C - current.second; nextB = current.second;
			if (!check[nextA][nextB]) { q.push(make_pair(nextA, nextB)); check[nextA][nextB] = true; }
		}
		else
		{
			nextA = A; nextB = current.second;
			if (!check[nextA][nextB]) { q.push(make_pair(nextA, nextB)); check[nextA][nextB] = true; }
		}

		if (B > C - current.first)
		{
			nextA = current.first; nextB = C - current.first;
			if (!check[nextA][nextB]) { q.push(make_pair(nextA, nextB)); check[nextA][nextB] = true; }
		}
		else
		{
			nextA = current.first; nextB = B;
			if (!check[nextA][nextB]) { q.push(make_pair(nextA, nextB)); check[nextA][nextB] = true; }
		}
	}

	for (set<int>::iterator iter = volume.begin(); iter != volume.end(); iter++)
		printf("%d ", *iter);
	return 0;
}