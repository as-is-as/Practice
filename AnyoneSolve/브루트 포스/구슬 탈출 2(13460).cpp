#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
char game_map[10][10];
bool move_map[10][10][2];

int n, m;

int mov_x[] = { 0, 0, -1, 1 };
int mov_y[] = { -1, 1, 0, 0 };

int min_move = 11;
bool min_check = false;
void Go(const pair<int, int> blue_marble, const pair<int, int> red_marble, int move_count, bool red_out)
{
	if (move_count > 10 || min_move <= move_count)
	{
		return;
	}
	if (red_out)
	{
		min_check = true;
		min_move = min(min_move, move_count);
		return;
	}

	pair<int, int> blue_marble_pos = blue_marble;
	pair<int, int> red_marble_pos = red_marble;
	for (int i = 0; i < 4; ++i)
	{
		int b_index = 0;
		int r_index = 0;
		bool move_check[2] = { false, false };
		bool red_out_check = false;

		while (true)
		{
			int blue_x = blue_marble_pos.first + b_index * mov_x[i];
			int blue_y = blue_marble_pos.second + b_index * mov_y[i];
			int red_x = red_marble_pos.first + r_index * mov_x[i];
			int red_y = red_marble_pos.second + r_index * mov_y[i];
			

			if (blue_x >= 0 && blue_x < n && blue_y >= 0 && blue_y < m)
			{
				if (!move_check[0])
				{
					if (game_map[blue_x][blue_y] == '#')
					{
						move_check[0] = true;
						--b_index;
						if ((red_marble_pos.first + r_index * mov_x[i] == blue_marble_pos.first + b_index * mov_x[i])
							&& (red_marble_pos.second + r_index * mov_y[i] == blue_marble_pos.second + b_index * mov_y[i]))
						{
							move_check[1] = true;
							--r_index;
						}
						
					}
					else if (game_map[blue_x][blue_y] == 'O')
						break;
					else
						++b_index;
				}
			}
			if (red_x >= 0 && red_x < n && red_y >= 0 && red_y < m)
			{
				if (!move_check[1]) 
				{
					if (game_map[red_x][red_y] == '#')
					{
						move_check[1] = true;
						 

						if ((red_marble_pos.first + r_index * mov_x[i] == blue_marble_pos.first + b_index * mov_x[i])
							&& (red_marble_pos.second + r_index * mov_y[i] == blue_marble_pos.second + b_index * mov_y[i]))
						{
							move_check[0] = true;
							b_index -= 3;
						}
						--r_index;
					}
					else if (game_map[red_x][red_y] == 'O')
					{
						move_check[1] = true;
						red_out_check = true;
					}
					else
						++r_index;
				}
			}

			if (move_check[0] && move_check[1])
			{
				blue_x = blue_marble_pos.first + b_index * mov_x[i];
				blue_y = blue_marble_pos.second + b_index * mov_y[i];
				red_x = red_marble_pos.first + r_index * mov_x[i];
				red_y = red_marble_pos.second + r_index * mov_y[i];



				if (!move_map[blue_x][blue_y][0] || !move_map[red_x][red_y][1] && min_move > move_count)
				{
					pair<int, int> move_blue = make_pair(blue_x, blue_y);
					pair<int, int> move_red = make_pair(red_x, red_y);

					move_map[blue_x][blue_y][0] = true;
					move_map[red_x][red_y][1] = true;

					Go(move_blue, move_red, move_count + 1, red_out_check);
					move_map[blue_x][blue_y][0] = false;
					move_map[red_x][red_y][1] = false;
				}
				break;
			}
		}

	}
}
int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

	cin >> n >> m;
	pair<int, int> blue_marble;
	pair<int, int> red_marble;

	for (int i = 0; i < n; ++i)
	{
		string temp_str;
		cin >> temp_str;
		for (int j = 0; j < temp_str.length(); ++j)
		{
			game_map[i][j] = temp_str[j];

			if (temp_str[j] == '#' || temp_str[j] == '.' || temp_str[j] == 'O')
				continue;
			if (temp_str[j] == 'B')
			{
				blue_marble.first = i;
				blue_marble.second = j;
				move_map[i][j][0] = true;
			}
			else if (temp_str[j] == 'R')
			{
				red_marble.first = i;
				red_marble.second = j;
				move_map[i][j][1] = true;
			}
		}
	}
	Go(blue_marble, red_marble, 0, false);
    if(min_move == 11) min_move = -1;
	cout << min_move << '\n';
}