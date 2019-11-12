#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<int> num_list;
vector<int> user_list;

int main(void)
{
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    int n, s;
    int num_length = 0;
    cin >> n >> s;


    num_list.resize(n);
    user_list.resize(n);

    for(int i=0; i<n; ++i)
    {
        cin >> num_list[i];
    }

    int index_pos = 0;
    for(int i=0; i<n; ++i)
    {
        int temp_num = 0;
        int increase_index = 0;
        for(int j=i; j>=index_pos; --j)
        {
            temp_num += num_list[j];
            if(temp_num >= s)
            {
                if(num_length == 0) num_length = 1 + i - j;
                else num_length = min(num_length, 1 + i - j);
                ++increase_index;
            }
        }

        if(num_length == 1) break;
        index_pos += increase_index;
    }
    
    cout << num_length << '\n';
    return 0;
}