#include <iostream>
#include <vector>
#include <climits>
using namespace std;


int K;
bool check[10];
vector<char> tempO(10);
vector<string> tempV;
int maxResult = INT_MIN;
int minResult = INT_MAX;


bool CheckFunc(char tempA, char tempB, char inequality)
{
    if(inequality == '>')
        return tempA > tempB;
    else
        return tempA < tempA;
}
void Go(int index, string num)
{
    if(index == K + 1)
    {
        tempV.push_back(num);
        return;
    }
    
    for(int i = 0; i <= 9; ++i)
    {
        if(check[i]) continue;

        if(index == 0 || CheckFunc(num[index - 1], i + '0', tempO[index - 1]))
        {
            check[i] = true;
            Go(index + 1, num + to_string(i));
            check[i] = false;
        }
    }
}

int main(void)
{
    cin >> K;
    for(int i = 0; i < K; ++i)
    {
        cin >> tempO[i];
    }

    cout << tempV.back() << '\n';
    cout << tempV.front() <<'\n';
}