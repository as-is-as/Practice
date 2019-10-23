#include <iostream>

using namespace std;

bool checkNum[10];

int CheckN(int N)
{
    if(N == 0)
    {
        if(checkNum[0])
            return 0;
        else   
            return 1;
    }

    int len = 0;

    while(true)
    {
        if(checkNum[N % 10])
            return 0;
        ++len;

        if(N / 10 == 0)
            break;
        N /= 10;
    }
    return len;
}
int main(void)
{
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    int N, M;
    int minLen;
    cin >> N >> M;

    for(int i = 0; i < M; ++i)
    {
        int temp;
        cin >> temp; 
        checkNum[temp] = true;
    }

    minLen = 100 - N;
    if(minLen < 0)
        minLen *= -1;

    for(int i = 0; i <= 1000000; ++i)
    {
        int len = CheckN(i);
        if(len > 0)
        {
            int tempNum = i - N;
            if(tempNum < 0)
                tempNum *= -1;
            
            if(minLen > len + tempNum)
                minLen = len + tempNum;
        }
    }

    cout << minLen <<'\n';
    return 0;
}