#include <iostream>
#include <queue>
#include <set>
#include <string>

using namespace std;

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        queue<pair<int, string>> tempQ;
        tempQ.push(make_pair(1, "1"));

        
        set<int> tempS;
        tempS.insert(1);

        while (!tempQ.empty())
        {
            int value = tempQ.front().first;
            string tempStr = tempQ.front().second;
            tempQ.pop();

            if(tempStr.length() <= 100)
            {
                if(value % n == 0)
                {
                    cout << tempStr << '\n';
                    break;
                }
                int tempValue = value % n;
                if(tempS.find(tempValue * 10 + 1) == tempS.end())
                {
                    tempS.insert(tempValue * 10 + 1);
                    tempQ.push(make_pair(tempValue * 10 + 1, tempStr + "1"));
                }
                if(tempS.find(tempValue * 10 ) == tempS.end())
                {
                    tempS.insert(tempValue * 10);
                    tempQ.push(make_pair(tempValue * 10, tempStr + "0"));
                }
            }
            else
            {
                cout << "BRAK" << '\n';
            }
        }
    }
    return 0;
}
