#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
#include <algorithm>

#define MAX_MIRROR_COUNT 10001

using namespace std;

char play_default_map[100][100];
bool set_mirror[100][100][4][2]; // '/' '\'
int set_mirror_count[100][100];

int mov_x[] = {0, 0, -1, 1};
int mov_y[] = {-1, 1, 0, 0};

int mirror_count = MAX_MIRROR_COUNT;
int w, h;

// 왼쪽, 오른쪽, 아래, 위
// +90, -90
int check_direction(const int direction, const int mirror_type)
{
    int dir_pos;
    switch (direction)
    {
    case 0:
        if (mirror_type == 0)
            dir_pos = 2;
        else
            dir_pos = 3;
        break;
    case 1:
        if (mirror_type == 0)
            dir_pos = 3;
        else
            dir_pos = 2;
        break;
    case 2:
        if (mirror_type == 0)
            dir_pos = 0;
        else
            dir_pos = 1;
        break;
    case 3:
        if (mirror_type == 0)
            dir_pos = 1;
        else
            dir_pos = 0;
        break;
    }
    return dir_pos;
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> w >> h;
    vector<pair<int, int>> laser_pos;

    for (int i = 0; i < h; ++i)
    {
        for (int j = 0; j < w; ++j)
        {
            cin >> play_default_map[i][j];
            if (play_default_map[i][j] == 'C')
            {
                laser_pos.push_back(make_pair(i, j));

                for (int k = 0; k < 4; ++k)
                {
                    set_mirror[i][j][k][0] = true;
                    set_mirror[i][j][k][1] = true;
                }
            }
        }
    }
    
    queue<pair<int, int>> laser_default;
    queue<tuple<int, int, int, int>> laser_move;

    int x = laser_pos.front().first;
    int y = laser_pos.front().second;
    bool check_end = false;

    for (int i = 0; i < 4; ++i)
    {
        int index = 1;
        while (true)
        {
            int pos_x = x + mov_x[i] * index;
            int pos_y = y + mov_y[i] * index;

            if (pos_x < 0 || pos_x >= h || pos_y < 0 || pos_y >= w)
                break;
            if (play_default_map[pos_x][pos_y] == '*')
                break;
            if (play_default_map[pos_x][pos_y] == 'C')
            {
                set_mirror_count[pos_x][pos_y] = 0;
                check_end = true;
            }
            if (!set_mirror[pos_x][pos_y][i][0])
            {
                laser_move.push(make_tuple(pos_x, pos_y, i, 0));
                set_mirror[pos_x][pos_y][i][0] = true;
                if(set_mirror_count[pos_x][pos_y] == 0) set_mirror_count[pos_x][pos_y] = set_mirror_count[x][y] + 1;
                else set_mirror_count[pos_x][pos_y] = min(set_mirror_count[pos_x][pos_y], set_mirror_count[x][y] + 1);

            }
            if (!set_mirror[pos_x][pos_y][i][1])
            {
                laser_move.push(make_tuple(pos_x, pos_y, i, 1));
                set_mirror[pos_x][pos_y][i][1] = true;
                if(set_mirror_count[pos_x][pos_y] == 0) set_mirror_count[pos_x][pos_y] = set_mirror_count[x][y] + 1;
                else set_mirror_count[pos_x][pos_y] = min(set_mirror_count[pos_x][pos_y], set_mirror_count[x][y] + 1);
            }
            ++index;
        }
    }
    if (!check_end)
        while (!laser_move.empty())
        {
            int temp_x, temp_y, direction, mirror_type;
            tie(temp_x, temp_y, direction, mirror_type) = laser_move.front();
            laser_move.pop();

            int index = 1;
            int mov_dir = check_direction(direction, mirror_type);

            while (true)
            {
                int pos_x = temp_x + mov_x[mov_dir] * index;
                int pos_y = temp_y + mov_y[mov_dir] * index;

                if (pos_x < 0 || pos_x >= h || pos_y < 0 || pos_y >= w)
                    break;
                if (play_default_map[pos_x][pos_y] == '*')
                    break;
                if (play_default_map[pos_x][pos_y] == 'C')
                {
                    if (set_mirror_count[pos_x][pos_y] == 0) set_mirror_count[pos_x][pos_y] = set_mirror_count[temp_x][temp_y];
                    else set_mirror_count[pos_x][pos_y] = min(set_mirror_count[pos_x][pos_y], set_mirror_count[temp_x][temp_y] + 1);
                    break;
                }
                if (!set_mirror[pos_x][pos_y][mov_dir][0])
                {
                    laser_move.push(make_tuple(pos_x, pos_y, mov_dir, 0));
                    set_mirror[pos_x][pos_y][mov_dir][0] = true;
                    if(set_mirror_count[pos_x][pos_y] == 0) set_mirror_count[pos_x][pos_y] = set_mirror_count[temp_x][temp_y] + 1;
                    else set_mirror_count[pos_x][pos_y] = min(set_mirror_count[pos_x][pos_y], set_mirror_count[temp_x][temp_y] + 1);
                }
                if (!set_mirror[pos_x][pos_y][mov_dir][1])
                {
                    laser_move.push(make_tuple(pos_x, pos_y, mov_dir, 1));
                    set_mirror[pos_x][pos_y][mov_dir][1] = true;
                    if(set_mirror_count[pos_x][pos_y] == 0) set_mirror_count[pos_x][pos_y] = set_mirror_count[temp_x][temp_y] + 1;
                    else set_mirror_count[pos_x][pos_y] = min(set_mirror_count[pos_x][pos_y], set_mirror_count[temp_x][temp_y] + 1);
                }
                ++index;
            }
        }

    cout << set_mirror_count[laser_pos.back().first][laser_pos.back().second] << '\n';
}