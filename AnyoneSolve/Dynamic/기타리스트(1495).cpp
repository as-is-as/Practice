#include <iostream>

using namespace std;

int v[101];
int guitarList[101][1001];
int maxVolume = -1;
int n,m;

int main(void)
{
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    int s;
    cin >> n >> s >> m;

    guitarList[0][s] = 1;
    for(int i=1; i<=n; ++i)
    {
        cin >> v[i];
    }


    for(int i=0; i<n; ++i)
    {
        for(int j=0; j<=m; ++j)
        {
            if(guitarList[i][j] == 1)
            {
                if(j + v[i + 1] <= m )
                    guitarList[i+1][j + v[i+1]] = 1;
                if(j - v[i + 1] >= 0)
                    guitarList[i+1][j - v[i+1]] = 1;
            }
        }
    }
    for(int i=0; i<= m; ++i)
    {
        if(guitarList[n][i] == 1)
            maxVolume = i;
    }
    cout << maxVolume << '\n';

    return 0;
}