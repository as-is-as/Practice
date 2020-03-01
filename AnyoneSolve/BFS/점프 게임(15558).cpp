#include <iostream>
#include <queue>
#include <tuple>

using namespace std;

char game_map[2][100001];
bool check_map[2][100001];

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, k;
    cin >> n >> k;

    for(int i=0; i<2; ++i)
    {
        cin >> game_map[i];
    }

    bool pass_check = false;
    queue<tuple<int,int,int>> temp_q;

    temp_q.push(make_tuple(0,0,0));
    check_map[0][0] = true;

    while(!temp_q.empty())
    {
        int pos_top;
        int pos_line;
        int d_block;
        tie(pos_top, pos_line, d_block) = temp_q.front();
        temp_q.pop();
        
         if(pos_top + 1 > n-1 || pos_top + k > n -1)
        {
            pass_check = true;
            break;
        }

        if( pos_top + 1 > d_block && !check_map[pos_line][pos_top + 1] && game_map[pos_line][pos_top + 1] == '1')  
        {    
            check_map[pos_line][pos_top + 1] = true;
            temp_q.push(make_tuple(pos_top + 1, pos_line, d_block + 1 ));
        }
        if(pos_top - 1 > d_block && !check_map[pos_line][pos_top - 1] && game_map[pos_line][pos_top - 1] == '1')
        {    
            check_map[pos_line][pos_top - 1] = true;
            temp_q.push(make_tuple(pos_top - 1, pos_line, d_block + 1 ));
        }
        if(pos_top + k > d_block)
        {   
            pos_line = pos_line == 0 ? 1 : 0;

            if(!check_map[pos_line][pos_top + k] && game_map[pos_line][pos_top+ k] == '1')
            {   
                check_map[pos_line][pos_top + k] = true;
                temp_q.push(make_tuple(pos_top + k, pos_line, d_block + 1));
            }
        }
    }

    if(pass_check)  cout << 1 << '\n';
    else cout << 0 << '\n';
}