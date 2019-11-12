#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

bool alphabet[26];

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	alphabet['a' - 'a'] = true;
	alphabet['c' - 'a'] = true;
	alphabet['i' - 'a'] = true;
	alphabet['n' - 'a'] = true;
	alphabet['t' - 'a'] = true;

	int n, k;
	cin >> n >> k;

	vector<string> temp_v;
	int string_count = 0;
	if (k < 5)
		cout << 0 << '\n';
	else
	{
		vector<char> temp_v2;
		vector<int> user_permutation;

		for (int i = 0; i < n; ++i)
		{
			string temp_str;
			cin >> temp_str;

			temp_v.push_back(temp_str);
		}

		for (vector<string>::iterator it = temp_v.begin(); it != temp_v.end(); ++it)
		{
			for (int i = 0; i < (*it).length(); ++i)
			{
				if (alphabet[(*it)[i] - 'a'])
					continue;

				temp_v2.push_back((*it)[i]);
				alphabet[(*it)[i] - 'a'] = true;
			}
		}

		int index = k - 5;
		int num = 1;
		for (vector<char>::iterator it = temp_v2.begin(); it != temp_v2.end(); ++it)
		{
			alphabet[(*it) - 'a'] = false;

			if (index == 0)
				num = 0;
			user_permutation.push_back(num);
			--index;
		}

		do
		{
			for (int i = 0; i < user_permutation.size(); ++i)
			{
				if (user_permutation[i] == 1)
					alphabet[temp_v2[i] - 'a'] = true;
			}

			int temp_count = 0;
			for (vector<string>::iterator it = temp_v.begin(); it != temp_v.end(); ++it)
			{
				bool check_value = false;
				for (int i = 4; i < (*it).length() - 4; ++i)
				{
					if (!alphabet[(*it)[i] - 'a'])
					{
						check_value = true;
						break;
					}
				}
				if (!check_value)
					++temp_count;
			}
			for (int i = 0; i < user_permutation.size(); ++i)
			{
				if (user_permutation[i] == 1)
					alphabet[temp_v2[i] - 'a'] = false;
			}
			string_count = max(string_count, temp_count);
		} while (prev_permutation(user_permutation.begin(), user_permutation.end()));

		cout << string_count << '\n';
	}
}