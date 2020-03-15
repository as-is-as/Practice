#include <iostream>

using namespace std;
long long d[101];
int n;
int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;

    d[1] = 1;
    d[2] = 2;
    d[3] = 3;

    for(int i=4; i<=100; ++i)
    {   
        d[i] = d[i-1] + 1;

        for(int j=3; j<i; ++j)
        {
            long long tempNum = d[i - j] * (j - 1);
            if(d[i] < tempNum)
                d[i] = tempNum;
        }
    }

    cout << d[n] << '\n';
    return 0;
}