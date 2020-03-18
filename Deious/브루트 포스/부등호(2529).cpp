#include<iostream>
#include<string>
#include<vector>

using namespace std;

int Arr[10];
char Map[10];
bool Select[10];

vector<string> Answer;
vector<char> v;

bool Check(int Idx, char c)
{
	if (c == '<')
	{
		if (v[Idx] - '0' < v[Idx + 1] - '0')
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	else if (c == '>')
	{
		if (v[Idx] - '0' > v[Idx + 1] - '0')
		{
			return true;
		}
		else
		{
			return false;
		}
	}
}

bool Calculate(int k)
{
	for (int i = 0; i < k; i++)
	{
		if (Check(i, Map[i]) == false)
		{
			return false;
		}
	}

	return true;
}

void Dfs(int Cnt ,int k)
{
	if (Cnt == k + 1)
	{
		if (Calculate(k))
		{
			string s = "";
			for (int i = 0; i < v.size(); i++)
			{
				s += v[i];
			}
			Answer.push_back(s);
		}
		return;
	}

	for (int i = 0; i < 10; i++)
	{
		if (Select[i] == true)
		{
			continue;
		}

		Select[i] = true;
		v.push_back(Arr[i] + '0');
		Dfs(Cnt + 1, k);
		v.pop_back();
		Select[i] = false;
	}
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int k;
	cin >> k;

	for (int i = 0; i < k; i++)
	{
		cin >> Map[i];
	}

	for (int i = 0; i < 10; i++)
	{
		Arr[i] = i;
	}

	Dfs(0, k);
	
	cout << Answer.at(Answer.size() - 1) << "\n";
	cout << Answer.at(0) << "\n";

	return 0;
}