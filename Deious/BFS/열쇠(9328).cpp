#include <iostream>
#include <queue>
#include <string>

using namespace std;

char map[102][102];
bool check[102][102];
bool key[26];

int h, w, answer;

int dx[] = {0, 0, -1, 1};
int dy[] = {1, -1, 0, 0};

bool InRange(int x, int y)
{
    return x >= 0 && x <= h + 1 && y >= 0 && y <= w + 1;
}

int main(void)
{
    int a;
    cin >> a;

    while (a--)
    {
        int answer = 0;
        cin >> h >> w;

        for(int i = 0; i < 26; i++)
        {
            key[i] = false;
        }

        for (int i = 0; i <= 101; i++)
        {
            for (int j = 0; j <= 101; j++)
            {
                map[i][j] = '.';
                check[i][j] = false;
            }
        }

        for (int i = 1; i <= h; i++)
        {
            for(int j = 1; j <= w; j++)
            {
                cin >> map[i][j];
            }
        }

        string alphabet;
        cin >> alphabet;

        for (int i = 0; i < alphabet.size(); i++)
        {
            if (alphabet[i] >= 'a' && alphabet[i] <= 'z')
            {
                key[alphabet[i] - 'a'] = true;
            }
        }

        queue<pair<int, int>> q;
        queue<pair<int, int>> door[26];
        q.push(make_pair(0, 0));
        check[0][0] = true;

        while (!q.empty())
        {
            int x = q.front().first;
            int y = q.front().second;
            q.pop();

            for (int i = 0; i < 4; i++)
            {
                int nx = x + dx[i];
                int ny = y + dy[i];

                if (InRange(nx, ny) && !check[nx][ny])
                {
                    check[nx][ny] = true;

                    if (map[nx][ny] == '.')
                    {
                        q.push(make_pair(nx, ny));
                    }
                    else if (map[nx][ny] >= 'a' && map[nx][ny] <= 'z')
                    {
                        q.push(make_pair(nx, ny));

                        if (!key[map[nx][ny] - 'a'])
                        {
                            key[map[nx][ny] - 'a'] = true;

                            while (!door[map[nx][ny] - 'a'].empty())
                            {
                                q.push(door[map[nx][ny] - 'a'].front());
                                door[map[nx][ny] - 'a'].pop();
                            }
                        }
                    }
                    else if (map[nx][ny] >= 'A' && map[nx][ny] <= 'Z')
                    {
                        if (key[map[nx][ny] - 'A'])
                        {
                            q.push(make_pair(nx, ny));
                        }
                        else
                        {
                            door[map[nx][ny] - 'A'].push(make_pair(nx, ny));
                        }
                    }
                    else if (map[nx][ny] == '$')
                    {
                        q.push(make_pair(nx, ny));
                        answer++;
                    }
                }
            }
        }
        cout << answer << "\n";
    }

    return 0;
}