#include <iostream>
#include <algorithm>
#include <vector>
// 각각의 부분 배열의 합 생성
// 부분 배열의 합을 통해 결과 탐색

using namespace std;
long long tempArrayA[1001];
long long tempArrayB[1001];
long long t;
int n, m;
vector<long long> tempVectorA;
vector<long long> tempVectorB;

void getValue(vector<long long> &tempVector, long long tempArray[], int index)
{
    for (int i = 0; i < index; ++i)
    {
        long long tempValue = 0;
        for (int j = i; j < index; ++j)
        {
            tempValue += tempArray[j];
            tempVector.push_back(tempValue);
        }
    }
}
int main(void)
{
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    cin >> t;
    // get tempA
    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        cin >> tempArrayA[i];
    }
    getValue(tempVectorA, tempArrayA, n);

    // get tempB
    cin >> m;
    for (int i = 0; i < m; ++i)
    {
        cin >> tempArrayB[i];
    }
    getValue(tempVectorB, tempArrayB, m);

    sort(tempVectorA.begin(), tempVectorA.end());
    sort(tempVectorB.begin(), tempVectorB.end());

    int tempAIndex = 0;
    int tempBIndex = tempVectorB.size() - 1;
    long long count = 0;
    while (true)
    {
        if (tempAIndex >= tempVectorA.size() || tempBIndex < 0)
            break;
        long long tempValue = tempVectorA[tempAIndex] + tempVectorB[tempBIndex];
        if (tempValue == t)
        {
            long long valueA = 1;
            long long valueB = 1;
            while (true)
            {
                if (tempAIndex + valueA < tempVectorA.size() && tempVectorA[tempAIndex] == tempVectorA[tempAIndex + valueA])
                    ++valueA;
                else
                    break;
            }
            while (true)
            {
                if (tempBIndex - valueB >= 0 && tempVectorB[tempBIndex] == tempVectorB[tempBIndex - valueB])
                    ++valueB;
                else
                    break;
            }
            count += (valueA * valueB);
            tempAIndex += valueA;
            tempBIndex -= valueB;
        }
        else if (tempValue < t)
        {
            ++tempAIndex;
        }
        else
        {
            --tempBIndex;
        }
    }

    cout << count << '\n';
    return 0;
}
