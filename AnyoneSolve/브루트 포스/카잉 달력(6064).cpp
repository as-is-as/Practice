#include <iostream>
#include <algorithm>
using namespace std;

int value = 0;
int GCD(int N, int M)
{
    while(M)
    {
        int temp = N;
        N = M;
        M = temp % M;
    }
    return N;
}
int LCM(int N, int M)
{
    int gcdValue = GCD(N,M);
    return (N * M) / gcdValue; 
}
int GetYear(int N, int M, int X, int Y)
{
    int tempN = 0;
    value = LCM(N, M);
    if(N == 1 && M == 1 && X == 1 && Y == 1)
        return 1;

    while(true)
    {
        int temp = (tempN * M + X) % N;
        if(temp == 0)
            temp = N;
        if(temp == Y)
        {
            return tempN * M + X;
        }
        ++tempN;
        if(M * tempN >= value)
            break;
    }
    return -1;
}
int main(void)
{
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    int T;
    int M, N, X, Y;
    cin >> T;

    while(T--)
    {
        
        cin >> M >> N >> X >> Y;

        int year = GetYear(N, M, X, Y);

        cout << year << '\n';
    }
}