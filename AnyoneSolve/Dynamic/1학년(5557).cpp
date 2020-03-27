#include <iostream>
using namespace std;

unsigned long long tempList[101][21];
int numList[101];

int main(void)
{
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;
    for(int i=1; i<=n; ++i)
    {
        cin >> numList[i];
    }

    tempList[1][numList[1]] = 1;

    for(int i=1; i<n-1; ++i)
    {
        for(int j=0; j<=20; ++j)
        {
            if(tempList[i][j] != 0)
            {
                if(j + numList[i + 1] <= 20)
                    tempList[i+1][j + numList[i + 1]] += tempList[i][j];
                if(j - numList[i + 1] >= 0)
                    tempList[i+1][j - numList[i + 1]] += tempList[i][j];
            }
        }
    }
    cout << tempList[n-1][numList[n]] << '\n';
}