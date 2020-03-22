#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;

long long d[10001] = {0,};

int main(void)
{
    int n,k;
    cin >> n >> k;
    vector<int> tempV(n);

    for(int i=0; i<n; ++i)
    {
        cin >> tempV[i];
    }
    
    sort(tempV.begin(), tempV.end());

    for(int i=1; i<=k; ++i)
    {
        d[i] = INT_MAX;
        for(int j=0; j<n; ++j)
        {
            if(i - tempV[j] >= 0 && d[i - tempV[j]] != INT_MAX)
            {    
                if(d[i] > d[i - tempV[j]] + 1)
                {    
                    d[i] = d[i - tempV[j]] + 1;
                }
            }
        }
    }
    if(d[k] == INT_MAX)     cout << "-1";
    else    cout << d[k] << '\n';
    return 0;
}