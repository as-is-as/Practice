#include <iostream>
#include <algorithm>
#include <cstring>
#include <climits>

using namespace std;

int sumBook[501][501];
int k;

int getMinValue(int start, int end)
{
    if(start == end)
        return 0;
    if(sumBook[start][end] != INT_MAX)
        return sumBook[start][end]; 
        
    int sum = 0;
    for(int i=start; i<=end; ++i)
    {
        sum += sumBook[i][i];
    }
    for(int i=start; i<end; ++i)
    {
        sumBook[start][end] = min(sumBook[start][end], getMinValue(start, i) + getMinValue(i + 1, end));
    }

    return sumBook[start][end] += sum;
}
int main(void)
{
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    int t;
    cin >> t;

    while (t--)
    {
        cin >> k;
        int sum = 0;


        for(int i=1; i<=k; ++i)
        {
           for(int j=1; j<=k; ++j){
               sumBook[i][j] = INT_MAX;
           }
        }

        for (int i = 1; i <= k; ++i)
        {
            cin >> sumBook[i][i];
        }
        for(int i=1; i<k; ++i)
        {
            sumBook[i][i+1] = sumBook[i][i] + sumBook[i+1][i+1];
        }
        
        int minValue = getMinValue(1, k);
        cout << minValue << '\n';
    }
    return 0;
}