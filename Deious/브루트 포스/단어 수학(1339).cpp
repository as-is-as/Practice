#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int length[11];
int alphabat[27];

int main()
{
	int n;
	cin >> n;
	vector<string> v(n);
	vector<int> v1(27);

	for (int i = 0; i < n; i++)
	{
		cin >> v[i];
		int count = 1;

		for (int j = v[i].length()-1; j >=0; j--)
		{
			v1[v[i][j] - 'A'] += count;
			count *= 10;
		}
	}

	sort(v1.begin(), v1.end());
	int answer = 0, num = 9;

	for (int i = v1.size() - 1; i >= 0; i--)
	{
		answer += v1[i] * num;
		num--;
	}

	cout << answer;

	return 0;
}