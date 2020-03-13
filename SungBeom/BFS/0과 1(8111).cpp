#include <iostream>
#include <string>
#include <queue>
#include <set>
using namespace std;

int main(void)
{
	int T;
	cin >> T;

	while (T--)
	{
		int N;
		cin >> N;

		queue<int> q;
		queue<string> real;
		set<int> remains;
		q.push(1 % N); real.push("1");
		remains.insert(1);

		string ans = "";
		while (!q.empty())
		{
			int current = q.front(); q.pop();
			string realCurrent = real.front(); real.pop();
			if (current % N == 0)
			{
				ans = realCurrent;
				break;
			}

			int next = current * 10 % N;
			if (remains.insert(next).second) { q.push(next); real.push(realCurrent + "0"); }
			next = (current * 10 + 1) % N;
			if (remains.insert(next).second) { q.push(next); real.push(realCurrent + "1"); }
		}

		if (ans == "") cout << "BRAK\n";
		else cout << ans << '\n';
	}

	return 0;
}