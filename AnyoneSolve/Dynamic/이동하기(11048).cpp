#include <iostream>
#include <algorithm>

using namespace std;

int map[1001][1001];
int d[1001][1001];
int main(void)
{
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    int N, M;
    cin >> N >> M;

    for(int i = 1; i <= N; ++i)
    {
        for(int j = 1; j <= M; ++j)
        {
            cin >> map[i][j];
        }
    }

    d[1][1] = map[1][1];
    for(int i = 2; i <= N; ++i)
    {
        d[i][1] = (d[i -1][1] + map[i][1]);
    }
    for(int i = 2; i <= M; ++i)
    {
        d[1][i] = (d[1][i -1] + map[1][i]);
    }

    for(int i = 2; i <= N; ++i)
    {
        for(int j = i; j <= M; ++j)
        {
            d[i][j] = max(d[i - 1][j], d[i][j -1]) + map[i][j];
        }
        for(int j = i; j <= N; ++j)
        {
            d[j][i] = max(d[j][i -1], d[j -1][i]) + map[j][i];
        }
    }

    cout << d[N][M] << '\n';
}