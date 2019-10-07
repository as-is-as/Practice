#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int map[20][20];

int N;
int minValue = INT_MAX;
int Go(int index, vector<int> & teamA, vector<int> & teamB)
{
    if(index == N)
    {
        if(teamA.size() != N / 2) return -1;
        if(teamB.size() != N / 2) return -1;

        int valueA = 0;
        int valueB = 0;
        for(int i = 0; i < N / 2; ++i)
        {
            for(int j = 0; j < N /2; ++j)
            {
                valueA += map[teamA[i]][teamA[j]];
                valueB += map[teamB[i]][teamB[j]];
            }
        }
        return valueA > valueB ? valueA - valueB : valueB - valueA;
    }
    if(teamA.size() > N / 2) return -1;
    if(teamB.size() > N / 2) return -1;

    teamA.push_back(index);
    int resultA = Go(index + 1, teamA, teamB);
    if(resultA != -1 && minValue > resultA)
    {
        minValue = resultA;
    }
    teamA.pop_back();
    teamB.push_back(index);
    int resultB = Go(index + 1, teamA, teamB);
    if(resultB != -1 && minValue > resultB)
    {
        minValue = resultB;
    }
    teamB.pop_back();

    return minValue;
}
int main(void)
{
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    cin >> N;
    for(int i = 0; i < N; ++i)
    {
        for(int j = 0; j < N; ++j)
        {
            cin >> map[i][j];
        }
    }

    vector<int> teamA, teamB;
    int resultValue = Go(0, teamA, teamB);

    cout << resultValue << '\n';

    return 0;
}