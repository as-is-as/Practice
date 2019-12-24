#include <iostream>
#include <vector>

using namespace std;

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n,m;
    int get_count = 0;
    cin >> n >> m;

    vector<int> num_list(n);
    for(int i=0; i<n; ++i)
    {
        cin >> num_list[i];
    }

    int pos_index = 0;
    for(int i=0; i<n; ++i)
    {
        int temp_num = 0;
        for(int j=i; j>=pos_index; --j)
        {
            temp_num += num_list[j];
            if(temp_num >= m)
            {
                if(temp_num == m)   ++get_count;
                ++pos_index;
            }
        }
    }

    cout << get_count << '\n';
}