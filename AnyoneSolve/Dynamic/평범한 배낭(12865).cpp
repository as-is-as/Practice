#include <iostream>
#include <algorithm>

using namespace std;


int w[101], v[101];
int d[101][100001];
int main(void)
{
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    int n, k;
    cin >> n >> k;

    for(int i=1; i<=n; ++i)
    {
        cin >> w[i] >> v[i];
    }

    for(int i=1; i<=n; ++i)
    {
        for(int j=1; j<=k; ++j)
        {
            d[i][j] = d[i-1][j];

            if(j >= w[i])
            {
                d[i][j] = max(d[i][j], d[i -1][j - w[i]] + v[i]);
            }
        }
    }
    int ans = 0;
    for(int i=1; i<=n; ++i)
    {
        ans = max(ans, d[i][k]);
    }

    cout << ans << '\n';
}