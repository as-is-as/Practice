#include <iostream>
#include <vector>

using namespace std;

int d[10001] = {1,};
int num[3] = {1,2,3};
int main(void)
{
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> tempV(n);
    for(int i=0; i<n; ++i)
    {
        cin >> tempV[i];
    }
    for(int i=0; i<3; ++i)
    {
        for(int j=1; j<=10000; ++j)
        {
            if(j - num[i] >= 0)
            {
                d[j] += d[j - num[i]];
                
            }
        }
    }
    
    for(int i=0; i<n; ++i)
    {
        cout << d[tempV[i]] << '\n';
    }

    return 0;
}