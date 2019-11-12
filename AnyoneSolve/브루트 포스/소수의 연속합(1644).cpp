#include <iostream>
#include <vector>
#include <algorithm>

#define PRIME_SIZE 4000000

using namespace std;

bool prime_number[PRIME_SIZE + 1];
vector<int> prime_number_vector;

void get_prime_number()
{

    for (int i = 2; i <= PRIME_SIZE; ++i)
    {
        if (!prime_number[i])
            for (int j = i * i; j <= PRIME_SIZE; j += i)
            {
                prime_number[j] = true;
            }
    }

    for (int i = 2; i * i <= PRIME_SIZE; ++i)
    {
        if (!prime_number[i])
            prime_number_vector.push_back(i);
    }
}
int main(void)
{
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    int n;
    int continue_length = 0;
    cin >> n;

    get_prime_number();

    int vector_size = prime_number_vector.size();
    int start_pos = 0;
    for (int i = 0; i < vector_size; ++i)
    {
        int temp_num = 0;
        bool get_check = false;
        
        if (prime_number_vector[i] > n)
            break;

        for (int j = i; j >= start_pos; --j)
        {
            temp_num += prime_number_vector[j];

            if (temp_num >= n)
            {
                if (temp_num == n)
                {
                    ++continue_length;
                }
                ++start_pos;
            }
        }
    }
    cout << continue_length << '\n';
}