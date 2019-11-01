#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main(void)
{
	int N, K;
	cin >> N >> K;

	vector<string> words(N);
	for (int i = 0; i < N; i++)
	{
		string word;
		cin >> word;
		words[i] = word;
	}

	int max = 0;
	if (K >= 5)
	{
		K -= 5;
		vector<int> v(26);
		for (int i = 0; i < K; i++) v[i] = 1;
		for (int i = K; i < 26; i++) v[i] = 0;

		do
		{
			if (v['a' - 'a'] & 1 || v['c' - 'a'] & 1 || v['i' - 'a'] & 1 || v['n' - 'a'] & 1 || v['t' - 'a'] & 1) continue;
			v['a' - 'a'] = v['c' - 'a'] = v['i' - 'a'] = v['n' - 'a'] = v['t' - 'a'] = 1;

			int cnt = 0;
			for (int i = 0; i < N; i++)
			{
				int j = 4;
				for (; j < words[i].size() - 4; j++)
					if (v[words[i][j] - 'a'] ^ 1) break;
				if (j == words[i].size() - 4) cnt++;
			}
			if (max < cnt) max = cnt;

			v['a' - 'a'] = v['c' - 'a'] = v['i' - 'a'] = v['n' - 'a'] = v['t' - 'a'] = 0;
		} while (prev_permutation(v.begin(), v.end()));
	}

	printf("%d\n", max);
	return 0;
}