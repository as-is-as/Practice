#include <cstdio>

int d[12];
int Go(int n, int totalCount)
{
    if(n == 0)  return ++totalCount;
    if(n < 0)   return 0;

    if(d[n] > 0)    return d[n];

    d[n] = Go(n -1, totalCount) + Go(n -2, totalCount) + Go(n -3, totalCount);

    return d[n];
}

int main(void)
{
    int T,n;
    scanf("%d", &T);

    while(T--)
    {
        scanf("%d", &n);
        printf("%d\n", Go(n, 0));
    }
    return 0;
}