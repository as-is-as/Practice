#include <iostream>
#include <map>
#include <queue>
#include <tuple>
#include <vector>
#include <algorithm>
using namespace std;

int main(void)
{
	cin.tie(0);
	ios_base::sync_with_stdio(false);
	int tempA, tempB, tempC;
	cin >> tempA >> tempB >> tempC;

	map<tuple<int, int, int>, int> tempM;
	queue<tuple<int, int, int>> tempQ;

	tempQ.push(make_tuple(0, 0, tempC));
	tempM.insert(make_pair(make_tuple(0, 0, tempC), 1));

	while (!tempQ.empty())
	{
		int a, b, c;
		tie(a, b, c) = tempQ.front();

		//cout << a << " " << b << " " << c << endl;
		tempQ.pop();
		if (a != 0)
		{
			// b
			if (b != tempB)
			{
				if (tempB <= a + b)
				{
					if (tempM.count(make_tuple(a + b - tempB, tempB, c)) == 0)
					{
						tempQ.push(make_tuple(a + b - tempB, tempB, c));
						tempM.insert(make_pair(make_tuple(a + b - tempB, tempB, c), 1));
					}
				}
				else
				{
					if (tempM.count(make_tuple(0, a + b, c)) == 0)
					{
						tempQ.push(make_tuple(0, a + b, c));
						tempM.insert(make_pair(make_tuple(0, a + b, c), 1));
					}
				}
			}
			// c
			if (c != tempC)
			{
				if (tempC <= a + c)
				{
					if (tempM.count(make_tuple(a + c - tempC, b, tempC)) == 0)
					{
						tempQ.push(make_tuple(a + c - tempC, b, tempC));
						tempM.insert(make_pair(make_tuple(a + c - tempC, b, tempC), 1));
					}
				}
				else
				{
					if (tempM.count(make_tuple(0, b, a + c)) == 0)
					{
						tempQ.push(make_tuple(0, b, a + c));
						tempM.insert(make_pair(make_tuple(0, b, a + c), 1));
					}
				}
			}
		}
		if (b != 0)
		{
			// a
			if (a != tempA)
			{
				if (tempA <= a + b)
				{
					if (tempM.count(make_tuple(tempA, a + b - tempA, c)) == 0)
					{
						tempQ.push(make_tuple(tempA, a + b - tempA, c));
						tempM.insert(make_pair(make_tuple(tempA, a + b - tempA, c), 1));
					}
				}
				else
				{
					if (tempM.count(make_tuple(a + b, 0, c)) == 0)
					{
						tempQ.push(make_tuple(a + b, 0, c));
							tempM.insert(make_pair(make_tuple(a + b, 0, c), 1));
					}
				}
			}
			// c
			if (c != tempC)
			{
				if (tempC <= b + c)
				{
					if (tempM.count(make_tuple(a, b + c - tempC, tempC)) == 0)
					{
						tempQ.push(make_tuple(a, b + c - tempC, tempC));
						tempM.insert(make_pair(make_tuple(a, b + c - tempC, tempC), 1));
					}
				}
				else
				{
					if (tempM.count(make_tuple(a, 0, b + c)) == 0)
					{
						tempQ.push(make_tuple(a, 0, b + c));
						tempM.insert(make_pair(make_tuple(a, 0, b + c), 1));
					}
				}
			}
		}
		if (c != 0)
		{
			// a
			if (a != tempA)
			{
				if (tempA <= a + c)
				{
					if (tempM.count(make_tuple(tempA, b, a + c - tempA)) == 0)
					{
						tempQ.push(make_tuple(tempA, b, a + c - tempA));
						tempM.insert(make_pair(make_tuple(tempA, b, a + c - tempC), 1));
					}
				}
				else
				{
					if (tempM.count(make_tuple(a + c, b, 0)) == 0)
					{
						tempQ.push(make_tuple(a + c, b, 0));
						tempM.insert(make_pair(make_tuple(a + c, b, 0), 1));
					}
				}
			}
			// b
			if (b != tempB)
			{
				if (tempB <= b + c)
				{
					if (tempM.count(make_tuple(a, tempB, b + c - tempB)) == 0)
					{
						tempQ.push(make_tuple(a, tempB, b + c - tempB));
						tempM.insert(make_pair(make_tuple(a, tempB, b + c - tempB), 1));
					}
				}
				else
				{
					if (tempM.count(make_tuple(a, b + c, 0)) == 0)
					{
						tempQ.push(make_tuple(a, b + c, 0));
						tempM.insert(make_pair(make_tuple(a, b + c, 0), 1));
					}
				}
			}
		}
	}

	vector<int> tempV;
	for (auto it = tempM.begin(); it != tempM.end(); ++it)
	{
		int a, b, c;
		tie(a, b, c) = it->first;

		//cout << a << " " << b << " " << c << endl;
		if (a == 0)	tempV.push_back(c);
	}

	sort(tempV.begin(), tempV.end());
	for (int i = 0; i < tempV.size(); ++i)
	{
		cout << tempV[i] << " ";
	}
}