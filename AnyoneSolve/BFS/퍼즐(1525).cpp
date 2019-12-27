#include <iostream>
#include <string>
#include <queue>
#include <map>

using namespace std;

int dx[] = {0, 0, -1, 1};
int dy[] = {-1, 1, 0, 0};

int main(void)
{
    int n = 3;
    int start = 0;

    for(int i = 0; i < n; ++i)
    {
        for(int j = 0; j < n; ++j)
        {
            int temp;
            cin >> temp;

            if(temp == 0)
                temp = 9;
        }
        start = start * 10 + temp;
    }    

    queue<int> q;
    map<int, int> dist;
    dist[start] = 0;
    q.push(0);

    while(!q.empty())
    {
        int now_num = q.front();
        string now = to_string(now_num);
        q.pop();

        int z = now.find('9');
        int x = z / 3;
        int y = z % 3;

        for(int i = 0; i < 4; ++i)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if(nx < 0 || nx >= n && ny < 0 || ny >= n)
                continue;
            
            string next = now;
            swap(next[x * 3 + y], next[nx * 3 + ny]);

            int num = stoi(next);

            if(dist.count(num) == 0)
            {
                dist[num] = dist[now_num] + 1;
                q.push(num);
            }
        }
    }
}