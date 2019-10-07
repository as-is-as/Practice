#include <cstdio>
#include <queue>
#include <cstring>
#include <vector>

using namespace std;

int orderSave[10000];
char orderSaveC[10000];
bool check[10000];
int baseNum, resultNum;

void BFS()
{
	scanf("%d %d", &baseNum, &resultNum);
	queue<int> tempQ;
	
	tempQ.push(baseNum);
	check[baseNum] = true;
	int num = 0;

	while (!tempQ.empty())
	{
		int tempNum = tempQ.front();
		tempQ.pop();

		if (tempNum == resultNum)
			return;

		num = (tempNum * 2) % 10000;
		if (!check[num])
		{
			orderSave[num] = tempNum;
			orderSaveC[num] = 'D';
			check[num] = true;
			tempQ.push(num);
		}

		if (tempNum == 0)    num = 9999;
		else    num = tempNum - 1;
		if (!check[num])
		{
			orderSave[num] = tempNum;
			orderSaveC[num] = 'S';
			check[num] = true;
			tempQ.push(num);
		}

		num = (tempNum % 1000) * 10 + (tempNum / 1000);

		if (!check[num])
		{
			orderSave[num] = tempNum;
			orderSaveC[num] = 'L';
			check[num] = true;
			tempQ.push(num);
		}
		num = (tempNum / 10) + (tempNum % 10) * 1000;
		if (!check[num])
		{
			orderSave[num] = tempNum;
			orderSaveC[num] = 'R';
			check[num] = true;
			tempQ.push(num);
		}
	}
}
int main(void)
{
	int T;
	scanf("%d", &T);

	while (T--)
	{
		memset(check, false, sizeof(check));

		BFS();

		int tempNum = resultNum;
		vector<char> orderV;

		while (true)
		{
			orderV.push_back(orderSaveC[tempNum]);
			if (orderSave[tempNum] == baseNum)
				break;

			tempNum = orderSave[tempNum];
		}

		while (!orderV.empty())
		{
			printf("%c", orderV.back());
			orderV.pop_back();
		}
		printf("\n");
	}
	return 0;
}