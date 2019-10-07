#include <iostream>

using namespace std;

int n;
int check_col[15];
int check_line0[29];
int check_line1[29];


bool CheckFunc(int row, int col)
{
	if(check_col[col])	return false;
	if(check_line0[row + col])	return false;
	if(check_line1[row - col + n]) return false;

	return true;
}
int Go(int row)
{
	if(row == n)
		return 1;
	
	int cnt = 0;
	for(int col = 0; col < n; ++col)
	{
		if(CheckFunc(row, col))
		{
			check_col[col] = true;
			check_line0[row + col] = true;
			check_line1[row - col + n] = true;
			cnt += Go(row + 1);
			check_col[col] = false;
			check_line0[row + col] = false;
			check_line1[row - col + n] = false;
		}
	}
	return cnt;
}
int main(void)
{
	cin >> n;
	cout << Go(0) << '\n';
	return 0;
}