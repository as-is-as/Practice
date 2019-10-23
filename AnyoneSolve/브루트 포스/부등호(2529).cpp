#include <iostream>
#include <string>
#include <vector>

using namespace std;

int k;
vector<char> inequality(9);
vector<string> tempStr;
bool check[10];

bool CheckFunc(char tempA, char tempB, char op)
{
	if(op == '<')
		return tempA < tempB ? true : false;
	else
		return tempA > tempB ? true : false;
}
void Go(int index, string num)
{
	if(index == k + 1)
	{
		tempStr.push_back(num);
		return;
	}

	for(int i = 0; i <= 9; ++i)
	{
		if(check[i])	continue;

		if(index == 0 || CheckFunc(num[index - 1], i + '0', inequality[index - 1]))
		{
			check[i] = true;
			Go(index + 1, num + to_string(i));
			check[i] = false;
		}
	}
}
int main(void)
{
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	cin >> k;
	for(int i = 0; i < k; ++i)
	{
		cin >> inequality[i];
	}
	Go(0, "");

	cout << tempStr.back() << '\n';
	cout << tempStr.front() << '\n';
	return 0;
}