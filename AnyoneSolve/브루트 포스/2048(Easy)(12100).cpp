#include <iostream>
#include <algorithm>

using namespace std;

int puzzle_board[20][20][6];

int n;
int max_num = 0;

void puzzle_up(int page)
{
    for(int i=0; i<n; ++i)
    {
        int temp_pos = 0;
        for(int j=0; j<n; ++j)
        {
            if(puzzle_board[j][i][page -1] == 0) continue;
            else
            {
                puzzle_board[temp_pos][i][page] = puzzle_board[j][i][page -1];
                ++temp_pos;
            }
        }

        for(int j=temp_pos; j<n; ++j)
        {
            puzzle_board[j][i][page] = 0;
        }

        int input_pos = 0;
        int combination_count = 0;

        for(int j=0; j<n; ++j, ++input_pos)
        {
            if(j != n-1 && puzzle_board[j][i][page] == puzzle_board[j+1][i][page])
            {
                puzzle_board[input_pos][i][page] = puzzle_board[j][i][page] * 2;
                ++combination_count;
                ++j;
            }
            else
            {
                puzzle_board[input_pos][i][page] = puzzle_board[j][i][page];
            }
        }

        for(int j=0; j<combination_count; ++j)
        {
            puzzle_board[n-1-j][i][page] = 0;
        }
    }
}
void puzzle_down(int page)
{
    for(int i= n-1; i>=0; --i)
    {
        int temp_pos = n-1;
        for(int j=n-1; j>=0; --j)
        {
            if(puzzle_board[j][i][page -1] == 0) continue;
            else
            {
                puzzle_board[temp_pos][i][page] = puzzle_board[j][i][page -1];
                --temp_pos;
            }
        }
        for(int j=temp_pos; j >=0; --j)
        {
            puzzle_board[j][i][page] = 0;
        }

        int set_pos = n-1;
        int combination_count = 0;
        for(int j=n-1; j>=0; --j, --set_pos)
        {
            if(j != 0 && puzzle_board[j][i][page] == puzzle_board[j-1][i][page])
            {
                puzzle_board[set_pos][i][page] = puzzle_board[j][i][page] * 2;
                ++combination_count;
                --j;
            }
            else
            {
                puzzle_board[set_pos][i][page] = puzzle_board[j][i][page];
            }
        }

        for(int j=0; j<combination_count; ++j)
        {
            puzzle_board[j][i][page] = 0;
        }
    }
}
void puzzle_left(int page)
{
    for(int i=0; i<n; ++i)
    {
        int temp_pos = 0;
        for(int j=0; j<n; ++j)
        {
            if(puzzle_board[i][j][page -1] == 0) continue;
            else
            {
                puzzle_board[i][temp_pos][page] = puzzle_board[i][j][page-1];
                ++temp_pos;
            }
        }
        for(int j=temp_pos; j<n; ++j)
        {
            puzzle_board[i][j][page] = 0;
        }
        int input_pos = 0;
        int combination_count = 0;
        for(int j=0; j<n; ++j, ++input_pos)
        {            
            if(j != n - 1 && puzzle_board[i][j][page] == puzzle_board[i][j + 1][page])
            {
                puzzle_board[i][input_pos][page] = puzzle_board[i][j][page] * 2;
                ++combination_count;
                ++j;
            }
            else
            {
                puzzle_board[i][input_pos][page] = puzzle_board[i][j][page];
            }
        }
        for(int j=0; j<combination_count; ++j)
        {
            puzzle_board[i][n - 1 - j][page] = 0;
        }
    }
}
void puzzle_right(int page)
{
    for(int i= n-1; i>=0; --i)
    {
        int temp_pos = n-1;
        for(int j=n-1; j>=0; --j)
        {
            if(puzzle_board[i][j][page -1] == 0) continue;
            else
            {
                puzzle_board[i][temp_pos][page] = puzzle_board[i][j][page -1];
                --temp_pos;
            }
        }
        for(int j=temp_pos; j >=0; --j)
        {
            puzzle_board[i][j][page] = 0;
        }

        int set_pos = n-1;
        int combination_count = 0;
        for(int j=n-1; j>=0; --j, --set_pos)
        {
            if(j != 0 && puzzle_board[i][j][page] == puzzle_board[i][j-1][page])
            {
                puzzle_board[i][set_pos][page] = puzzle_board[i][j][page] * 2;
                ++combination_count;
                --j;
            }
            else
            {
                puzzle_board[i][set_pos][page] = puzzle_board[i][j][page];
            }
        }

        for(int j=0; j<combination_count; ++j)
        {
            puzzle_board[i][j][page] = 0;
        }
    }
}

void puzzle_move(int page)
{
    int temp_max_num = 0;
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            temp_max_num = max(temp_max_num, puzzle_board[i][j][page]);
        }
    }

    max_num = max(max_num, temp_max_num);

    if (page == 5)
        return;

    puzzle_up(page + 1);
    puzzle_move(page + 1);

    puzzle_down(page + 1);
    puzzle_move(page + 1);

    puzzle_left(page + 1);
    puzzle_move(page + 1);

    puzzle_right(page + 1);
    puzzle_move(page + 1);
    
}
int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            cin >> puzzle_board[i][j][0];
        }
    }

    puzzle_move(0);

    cout << max_num << '\n';
    return 0;
}