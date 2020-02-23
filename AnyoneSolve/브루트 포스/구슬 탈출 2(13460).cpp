#include <iostream>
#include <algorithm>
#include <queue>
#include <map>
#include <tuple>
#include <climits>

using namespace std;

char gameMap[11][11];
map<pair<pair<int, int>, pair<int, int>>, int> ballMap;
queue<tuple<pair<int, int>, pair<int, int>, int>> tempQ;

int moveX[] = {0, 0, -1, 1};
int moveY[] = {-1, 1, 0, 0};

int minMove = INT_MAX;

void ballMove(int n, int m, pair<int, int> bluePos, pair<int, int> redPos, int count, int index)
{
	int blueValue = 0;
	bool blueBallRedPass = false;
	// blue
	while (true)
	{
		int x = bluePos.first + moveX[index] * (blueValue + 1);
		int y = bluePos.second + moveY[index] * (blueValue + 1);
		if (x > 0 && x < n - 1 && y > 0 && y < m - 1)
		{
			if (gameMap[x][y] == '#')
				break;
			if (gameMap[x][y] == 'O')
				return;
			if (x == redPos.first && y == redPos.second)
				blueBallRedPass = true;
			++blueValue;
		}
		else
			break;
	}
	int redValue = 0;
	bool redBallBluePass = false;

	// red
	while (true)
	{
		int x = redPos.first + moveX[index] * (redValue + 1);
		int y = redPos.second + moveY[index] * (redValue + 1);
		if (x > 0 && x < n - 1 && y > 0 && y < m - 1)
		{
			if (gameMap[x][y] == '#')
				break;
			if (x == bluePos.first && y == bluePos.second)
				redBallBluePass = true;
			if (gameMap[x][y] == 'O')
			{
				++count;
				minMove = min(minMove, count);
				return;
			}
			++redValue;
		}
		else
			break;
	}
	if (redBallBluePass)
	{
		--redValue;
	}
	else if (blueBallRedPass)
	{
		--blueValue;
	}

	bluePos.first += moveX[index] * blueValue;
	bluePos.second += moveY[index] * blueValue;
	redPos.first += moveX[index] * redValue;
	redPos.second += moveY[index] * redValue;

	if (ballMap.find(make_pair(bluePos, redPos)) == ballMap.end())
	{
		ballMap.insert(make_pair(make_pair(bluePos, redPos), 0));
		tempQ.push(make_tuple(bluePos, redPos, count + 1));
	}
}

int main(void)
{
	cin.tie(0);
	ios_base::sync_with_stdio(false);
	int n, m;
	pair<int, int> bluePos;
	pair<int, int> redPos;
	cin >> n >> m;

	for (int i = 0; i < n; ++i)
	{
		cin >> gameMap[i];
	}

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			if (gameMap[i][j] == 'B')
			{
				bluePos = make_pair(i, j);
			}
			if (gameMap[i][j] == 'R')
			{
				redPos = make_pair(i, j);
			}
		}
	}
	ballMap.insert(make_pair(make_pair(bluePos, redPos), 0));
	tempQ.push(make_tuple(bluePos, redPos, 0));

	while (!tempQ.empty())
	{
		pair<int, int> tempBlue = get<0>(tempQ.front());
		pair<int, int> tempRed = get<1>(tempQ.front());
		int count = get<2>(tempQ.front());
		tempQ.pop();

		for (int i = 0; i < 4; ++i)
		{
			ballMove(n, m, tempBlue, tempRed, count, i);
		}
	}

	if (minMove == INT_MAX || minCount > 10)
		minMove = -1;
	cout << minMove << '\n';
	return 0;
}