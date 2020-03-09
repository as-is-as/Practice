#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, s;
    cin >> n >> s;
    vector<int> temp_vector(n);

    for(int i=0; i<n; ++i)
    {
        cin >> temp_vector[i];
    }

    int first_len = n / 2;
    vector<int> first_vector(1 << first_len);
    for(int i=0; i<(1<<first_len); ++i)
    {
        for(int j=0; j<first_len; ++j)
        {
            if(i & (1 << j))
            {
                first_vector[i] += temp_vector[j];
            }
        }
    }

    int second_len = n - first_len;
    vector<int> second_vector(1 << second_len);
    for(int i=0; i<(1<<second_len); ++i)
    {
        for(int j=0; j<second_len; ++j)
        {
            if(i & (1 << j))
            {
                second_vector[i] += temp_vector[j + first_len];
            }
        }
    }

    sort(first_vector.begin(), first_vector.end());
    sort(second_vector.begin(), second_vector.end(), greater<int>());

    first_len = (1 << first_len);
    second_len = (1 << second_len);

    int first_pos = 0;
    int second_pos = 0;
    long long result_count = 0;
    while(first_pos < first_len && second_pos < second_len)
    {
        if(first_vector[first_pos] + second_vector[second_pos] == s)
        {
            ++first_pos;
            ++second_pos;

            long long f_count = 1;
            long long s_count = 1;
            while(first_pos < first_len && first_vector[first_pos] == first_vector[first_pos -1])
            {
                ++first_pos;
                ++f_count;
            }
            while(second_pos < second_len && second_vector[second_pos] == second_vector[second_pos -1])
            {
                ++second_pos;
                ++s_count;
            }
 
            result_count += f_count * s_count;
        }
        else if(first_vector[first_pos] + second_vector[second_pos] < s)
            ++first_pos;
        else
            ++second_pos;
    }


    if(s == 0) --result_count;
    cout << result_count << '\n';
}