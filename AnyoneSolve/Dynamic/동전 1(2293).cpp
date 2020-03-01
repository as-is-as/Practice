#include <iostream>
#include <vector>

using namespace std;

int d[100001] = {1,};

int main(void)
{
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    
    int n,k;
    cin >> n >> k;

    vector<int> tempV(n);
    for(int i=0; i<n; ++i)
    {
        cin >> tempV[i];
    }
    
    for(int i=0; i<n; ++i)
    {
        for(int j=1; j<=k; ++j)
        {
            if(j - tempV[i] >= 0)
                d[j] += d[j - tempV[i]];
        }
    }

    cout << d[k] << '\n';
    return 0;
}