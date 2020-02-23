#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<int> temp_vector_a;
vector<int> temp_vector_b;


long long get_upper_bound(const long target_value)
{
    int pos = -1;
    int left = 0;
    int right = temp_vector_b.size();


    while(left < right)
    {
        int mid = (left + right) / 2;

        if(temp_vector_b[mid] <= target_value)
            left = mid + 1;
        else
            right = mid;
    }
    return left;
}
long long get_lower_bound(const long target_value)
{
    int pos = -1;
    int left = 0;
    int right = temp_vector_b.size();


    while(left < right)
    {
        int mid = (left + right) / 2;

        if(temp_vector_b[mid] < target_value)
            left = mid + 1;
        else
            right = mid;
    }
    return left;
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n; 
    cin >> n;

    vector<int> temp_a(n), temp_b(n), temp_c(n), temp_d(n);

    for(int i=0; i<n; ++i)
    {
        cin >> temp_a[i] >> temp_b[i] >> temp_c[i] >> temp_d[i];
    }

    for(int i=0; i<n; ++i)
    {
        for(int j=0; j<n; ++j)
        {
            temp_vector_a.push_back(temp_a[i] + temp_b[j]);
            temp_vector_b.push_back(temp_c[i] + temp_d[j]);
        }
    }

    sort(temp_vector_b.begin(), temp_vector_b.end());

    long long ans = 0;
    for(auto it = temp_vector_a.begin(); it != temp_vector_a.end(); ++it)
    {
        ans += get_upper_bound(-*it) - get_lower_bound(-*it);
    }
    cout << ans << '\n';
    return 0;
}