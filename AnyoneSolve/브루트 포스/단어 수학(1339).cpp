#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>

using namespace std;

vector<string> inputLine;
vector<int> useNum(10);
vector<int> setNum;
bool alphabet[26];
int alphabetNum[26];

int main(void)
{
    int N;
    int alphabetCount = 0;
    int maxValue = 0;
    cin >> N;
    inputLine.resize(N);

    for(int i = 0; i < N; ++i)
    {
        cin >> inputLine[i];
    }
    
    for(vector<string>::iterator it = inputLine.begin(); it != inputLine.end(); ++it)
    {
        string temp = *it;
        for(int i = 0; i < temp.size(); ++i)
        {
            if(!alphabet[temp.at(i) - 'A'])
            {
                alphabet[temp.at(i) - 'A'] = true;
                alphabetNum[temp.at(i) - 'A'] = alphabetCount;
                ++alphabetCount;
            }
        }
    }

    int temp = 0;

    setNum.resize(alphabetCount);
    for(int i = 0; i < alphabetCount; ++i)
    {  
        setNum[i] = 9 - i;
    }
    do
    {
        int tempMax = 0;
        int tempTotal = 0;
        for(int i = 0; i < N; ++i)
        {
            string tempLine = inputLine[i];
            int tempInt;
            for(int i = 0; i < tempLine.size(); ++i)
            {
				int tempNum = 1;
				for(int j = 0; j < tempLine.size() - i - 1; ++j)
				{
					tempNum *= 10;
				}
				tempTotal += setNum[alphabetNum[tempLine.at(i) - 'A']] * tempNum;
			}
        }
        if(maxValue < tempTotal)
            maxValue = tempTotal;

    }while(prev_permutation(setNum.begin(), setNum.end()));

    cout << maxValue << '\n';
}