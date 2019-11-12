#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int paper[4][4];

int main(void)
{
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    int n,m;
    string temp_s;

    cin >> n >> m;
    for(int i=0; i<n; ++i)
    {
        cin >> temp_s;
        for(int j=0; j<temp_s.length(); ++j)
        {
            paper[i][j] = temp_s[j] -'0';
        }
    }
    int ans = 0;
    for(int s=0; s<(1<<n*m); ++s)
    {
        int sum = 0;
        for(int i=0; i<n; ++i)
        {
            int temp_sum = 0;
            for(int j=0; j<m; ++j)
            {
                int k = i*m + j;
                if((s&(1<<k)) == 0) temp_sum = temp_sum * 10 + paper[i][j];
                else
                {
                    sum += temp_sum;
                    temp_sum = 0;
                }
            }
            sum += temp_sum;
        }
        for(int i=0; i<m; ++i)
        {
            int temp_sum = 0;
            for(int j=0; j<n; ++j)
            {
                int k = j*m + i;
                if((s&(1<<k)) != 0) temp_sum = temp_sum * 10 + paper[j][i];
                else
                {
                    sum += temp_sum;
                    temp_sum = 0;
                }
            }
            sum += temp_sum;
        }

        ans = max(ans, sum);
    }
    cout << ans << '\n';
    return 0;
}