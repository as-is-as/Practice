#include <iostream>

using namespace std;

int N;
int map[10][10];
int tempArray[10];

bool CheckFunc(int index)
{
    int sum = 0;

    for(int i = index; i >= 0; --i)
    {
        sum += tempArray[i];

        if(map[i][index] == 0)
        {
            if(sum != 0)    return false;
        }
        else if(map[i][index] < 0)
        {
            if(sum >= 0)    return false;
        }
        else 
            if(sum <= 0)    return false;
    }
    return true;
}
bool Go(int index)
{
    if(index == N)
        return true;
    if(map[index][index] == 0)
    {
        return CheckFunc(index) && Go(index + 1);
    }

    for(int i = 1; i <= 10; ++i)
    {
        tempArray[index] = map[index][index] * i;
        if(CheckFunc(index) && Go(index + 1))
            return true;
    }
    return false;
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin >> N;

    for(int i = 0; i < N; ++i)
    {
        char tempChar;
        for(int j = i; j < N; ++j)
        {
            cin >> tempChar;
            if(tempChar == '-') map[i][j] = -1;
            else if(tempChar == '+') map[i][j] = + 1;
            else map[i][j] = 0;
        }
    }
    Go(0);
    for(int i = 0; i < N; ++i)
    {
        cout << tempArray[i] << " ";
    }
    return 0;
}