#include <cstdio>
using namespace std;

int d[2001][2001];
int tempArray[2001];

int Go(int s, int e)
{
    if(s == e)  return 1;
    else if(s + 1 == e)
    {
        if(tempArray[s] == tempArray[e])    return 1;
        else return 0;
    }

    if(d[s][e] >= 0)    return d[s][e];

    if(tempArray[s] != tempArray[e])    return d[s][e] = 0;
    else    return d[s][e] = Go(s+1, e-1);
}

int main(void)
{
    int n,m;
    scanf("%d", &n);

    for(int i=1; i<=n; ++i)
    {
        scanf("%d", &tempArray[i]);
    }

    for(int i=1; i<=n; ++i)
    {
        for(int j=1; j<=n; ++j)
            d[i][j] = -1;
    }
    
    scanf("%d", &m);
    int s,e;
    while(m--)
    {
        scanf("%d %d", &s, &e);
        printf("%d\n", Go(s,e));
    }
    return 0;
}