#include <iostream>
#include <deque>
#include <cstring>
#include <vector>
#include <climits>
using namespace std;

char prison_map[102][102];
int prison[102][102][3];

int h, w;
int movX[] = {0,0,-1,1};
int movY[] = {-1,1,0,0};
vector<pair<int,int>> prisoner;

void BFS()
{
	int index = 0;
	while(!prisoner.empty())
	{
		int x = prisoner.back().first;
		int y = prisoner.back().second;
		prisoner.pop_back();

		deque<pair<int, int>> tempQ;
		prison[x][y][index] = 0;
		tempQ.push_front(make_pair(x, y));

		while(!tempQ.empty())
		{
			int tempX = tempQ.front().first;
			int tempY = tempQ.front().second;
			
			tempQ.pop_front();

			for(int i=0; i<4; ++i)
			{
				int setX = tempX + movX[i];
				int setY = tempY + movY[i];

				if(setX>=0 && setX<=h+1 && setY>=0 && setY<=w+1)
				{
					if(prison_map[setX][setY] == '*')
						continue;
					if(prison[setX][setY][index] == -1 && prison_map[setX][setY] == '#')
					{	
						prison[setX][setY][index] = prison[tempX][tempY][index] + 1;
						tempQ.push_back(make_pair(setX, setY));
					}
					else if(prison[setX][setY][index] == -1)
					{
						prison[setX][setY][index] = prison[tempX][tempY][index];
						tempQ.push_front(make_pair(setX, setY));	
					}
				}
			}
		}
		++index;
	}
}
int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int t;
	cin >> t;

	while (t--)
	{
		cin >> h >> w;

		memset(prison, -1, sizeof(prison));
		prisoner.push_back(make_pair(0,0));
		for (int i = 0; i <= h + 1; ++i)
		{
			if (i == 0 || i == h + 1)
			{
				for (int j = 0; j <= w + 1; ++j)
				{
					prison_map[i][j] = '.';
				}
			}
			else
			{
				prison_map[i][0] = '.';
				prison_map[i][w+1] = '.';
				for (int j = 1; j <= w; ++j)
				{
					cin >> prison_map[i][j];
					if(prison_map[i][j] == '$')	prisoner.push_back(make_pair(i, j));
				}
			}
		}
		BFS();

		int minValue = INT_MAX;
		for(int i=1; i<=h; ++i)
		{
			for(int j=1; j<=w; ++j)
			{
				if(prison_map[i][j] == '*')
					continue;

				int tempSum = prison[i][j][0]+prison[i][j][1]+prison[i][j][2];	
				if(prison_map[i][j] == '#') tempSum -= 2;
				if(minValue > tempSum) minValue = tempSum;
			}
		}
		cout << minValue << '\n';
	}
	return 0;
}