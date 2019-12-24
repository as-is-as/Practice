#include <cstdio>
#include <vector>
using namespace std;

bool primeNums[4000001];

int main(void)
{
	for (int i = 2; i <= 4000000; i++)
		primeNums[i] = true;
	for (int i = 2; i <= 4000000; i++)
	{
		if (!primeNums[i]) continue;
		for (int j = 2; i*j <= 4000000; j++)
			primeNums[i*j] = false;
	}

	vector<int> primeNumsVec;
	for (int i = 2; i <= 4000000; i++)
		if (primeNums[i]) primeNumsVec.push_back(i);
	int len = primeNumsVec.size();

	int N;
	scanf("%d", &N);

	int lIndex = 0, rIndex = 0, sum = primeNumsVec[0], count = 0;
	while (true)
	{
		if (sum < N)
		{
			if (++rIndex == len) break;
			sum += primeNumsVec[rIndex];
		}
		else if (sum > N)
			sum -= primeNumsVec[lIndex++];
		else
		{
			count++;
			if (++rIndex == len) break;
			sum += primeNumsVec[rIndex];
		}
	}

	printf("%d\n", count);
	return 0;
}