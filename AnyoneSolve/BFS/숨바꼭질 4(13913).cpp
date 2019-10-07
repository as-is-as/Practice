// 숨바꼭질할거임
// 수빈, 동생
// 수빈 N (0 ~ 100000)
// 동생 K (0 ~ 100000)

// 수빈 걷거나 순간이동
//  - 걷기 +, -
//  - 순간 이동 2 * X

#include <iostream>
#include <queue>
#include <vector>

using namespace std;

bool check[100001];
int d[100001][2];
queue<int> tempQ;

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int N, K;
    cin >> N >> K;

    tempQ.push(N);
    d[N][1] = -1;
    check[N] = true;

    while(!tempQ.empty())
    {
        int pos = tempQ.front();
        tempQ.pop();

        if(pos * 2 <= 100000 && !check[pos * 2])
        {
            check[pos * 2] = true;
            d[pos * 2][0] = d[pos][0] + 1;
            d[pos * 2][1] = pos;
            tempQ.push(pos * 2);
        }

        if(pos + 1 <= 100000 && !check[pos + 1])
        {
            check[pos + 1] = true;
            d[pos + 1][0] = d[pos][0] + 1;
            d[pos + 1][1] = pos;
            tempQ.push(pos + 1);
        }
        if(pos - 1 >= 0 && !check[pos -1])
        {
            check[pos -1] = true;
            d[pos - 1][0] = d[pos][0] + 1;
            d[pos - 1][1] = pos;
            tempQ.push(pos - 1);
        }
    } 

    cout << d[K][0] << '\n';

    vector<int> orderV;
    int tempNum = K;
    while(true)
    {
        orderV.push_back(tempNum);

        if(d[tempNum][1] == -1)
            break;
        tempNum = d[tempNum][1];
    }

    while(!orderV.empty())
    {
        cout << orderV.back() << ' ';
        orderV.pop_back();
    }
    cout << '\n';

    return 0;
}