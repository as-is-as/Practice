#include <iostream>

using namespace std;

int testCase[101];
long long bracketList[2501];

int main(void)
{
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    int t;
    cin >> t;

    for(int i=1; i<=t; ++i)
    {
        cin >> testCase[i];
    }

    bracketList[0] = 1;
    bracketList[1] = 1;
    bracketList[2] = 2;

    for(int i=3; i<=2500; ++i)
    {
        long long sum = 0;
        for(int j=1; j<=i; ++j)
        {
            sum += (bracketList[j-1] * bracketList[i-j]) %  1000000007; 
        }
        bracketList[i] = sum % 1000000007;
    }

    for(int i=1; i<=t; ++i)
    {
        if(testCase[i]%2 == 0)
            cout << bracketList[testCase[i]/2] << '\n';
        else
            cout << 0 << '\n';
    }
}