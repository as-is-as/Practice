#include <iostream>
#include <string>
#include <cmath>

using namespace std;

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    string tempStr;
    int strLength;
    int totalCount = 0;
    cin >> tempStr;

    strLength = tempStr.size();

    for(int i = 0; i < strLength - 1; ++i)
    {
        totalCount += pow(10, i) * 9 * (i + 1);
    }
    

    int tempNum = stoi(tempStr) -  pow(10, strLength - 1) + 1;
    totalCount += tempNum * strLength;

    cout << totalCount << '\n';

    return 0; 
}