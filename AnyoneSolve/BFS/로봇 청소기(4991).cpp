#include <queue>
#include <vector>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <tuple>
#include <map>

using namespace std;

char room_map[21][21];
int room_move[21][21];

int h, w;
int mov_x[] = {0, 0, -1, 1};
int mov_y[] = {-1, 1, 0, 0};

int get_short_distance(int pos_x, int pos_y, vector<pair<int, int>> &dirty_pos, map<tuple<int, int, int, int>, int> &d_pos)
{
    int user_x = pos_x;
    int user_y = pos_y;
    int move_value = 0;

    for (int i = 0; i < dirty_pos.size(); ++i)
    {

        int dirty_x = dirty_pos[i].first;
        int dirty_y = dirty_pos[i].second;

        if (d_pos.count(make_tuple(user_x, user_y, dirty_x, dirty_y)) || d_pos.count(make_tuple(dirty_x, dirty_y, user_x, user_y)))
        {
            room_move[dirty_x][dirty_y] = d_pos[make_tuple(user_x, user_y, dirty_x, dirty_y)];
        }
        else
        {
            memset(room_move, -1, sizeof(room_move));
            bool check_move = false;

            queue<pair<int, int>> temp_q;
            temp_q.push(make_pair(user_x, user_y));
            room_move[user_x][user_y] = 0;

            while (!temp_q.empty())
            {
                int temp_x = temp_q.front().first;
                int temp_y = temp_q.front().second;
                temp_q.pop();

                for (int i = 0; i < 4; ++i)
                {
                    int x = temp_x + mov_x[i];
                    int y = temp_y + mov_y[i];

                    if (x >= 0 && x < h && y >= 0 && y < w)
                    {
                        if (room_map[x][y] == 'x')
                            continue;
                        if (room_move[x][y] == -1)
                        {
                            room_move[x][y] = room_move[temp_x][temp_y] + 1;
                            temp_q.push(make_pair(x, y));

                            if (room_map[x][y] == '*' && x == dirty_x && y == dirty_y)
                            {
                                check_move = true;
                                d_pos.insert(make_pair(make_tuple(user_x, user_y, dirty_x, dirty_y), room_move[x][y]));
                                d_pos.insert(make_pair(make_tuple(dirty_x, dirty_y, user_x, user_y), room_move[x][y]));
                            }
                        }
                    }
                }

                if (check_move)
                    break;
            }
        }
        user_x = dirty_x;
        user_y = dirty_y;
        move_value += room_move[dirty_x][dirty_y];

        cout << room_move[dirty_x][dirty_y] << "\t";
    }
    cout << '\n';
    return move_value;
}
int main(void)
{
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    while (true)
    {
        int user_x, user_y;
        cin >> w >> h;

        if (h == 0 && w == 0)
            break;

        vector<pair<int, int>> dirty_pos;
        map<tuple<int, int, int, int>, int> d_pos;

        for (int i = 0; i < h; ++i)
        {
            for (int j = 0; j < w; ++j)
            {
                cin >> room_map[i][j];

                if (room_map[i][j] == '*')
                {
                    dirty_pos.push_back(make_pair(i, j));
                }
                else if (room_map[i][j] == 'o')
                {
                    user_x = i;
                    user_y = j;
                }
            }
        }

        sort(dirty_pos.begin(), dirty_pos.end());

        int min_value = -1;
        do
        {
            int move_value = get_short_distance(user_x, user_y, dirty_pos, d_pos);
            if(move_value == -1)    break;
            if (min_value == -1 || min_value > move_value)
            {
                min_value = move_value;
            }

        } while (next_permutation(dirty_pos.begin(), dirty_pos.end()));

        cout << min_value << '\n';
    }
}