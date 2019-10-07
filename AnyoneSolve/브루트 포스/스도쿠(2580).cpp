#include <vector>
#include <cstdio>
#include <iostream>
using namespace std;

int map[9][9];
bool endCheck = false;
vector<pair<int, int>> zero_pos;

void GetResult(vector<pair<int,int>>::iterator it)
{
	if (it == zero_pos.end())
	{
		endCheck = true;
		return;
	}
	int tempX, tempY;
	int num_check[10];
	fill_n(num_check, 10, 0);

	tempX = it->first;
	tempY = it->second;

	// check line
	for (int i = 0; i < 9; ++i)
	{
		++num_check[map[i][tempY]];
		++num_check[map[tempX][i]];
	}
	int x = tempX / 3;
	int y = tempY / 3;
	for (int i = 0; i < 3; ++i)
	{
		for (int j = 0; j < 3; ++j)
		{
			++num_check[map[x * 3 + i][y * 3 + j]];
		}
	}

	for(int i = 1; i < 10; ++i)
	{
		if (num_check[i] == 0)
		{
			map[tempX][tempY] = i;
			GetResult(++it);

			if (endCheck)	return;
			map[tempX][tempY] = 0;
		}
	}
}

int main(void)
{
	for (int i = 0; i < 9; ++i)
	{
		for (int j = 0; j < 9; ++j)
		{
			scanf("%d", &map[i][j]);
			if (map[i][j] == 0)  zero_pos.push_back(make_pair(i, j));
		}
	}
	GetResult(zero_pos.begin());

	for (int i = 0; i < 9; ++i)
	{
		for (int j = 0; j < 9; ++j)
			printf("%d ", map[i][j]);
		printf("\n");
	}
}