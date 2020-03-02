#include <iostream>

using namespace std;

bool brokenButton[10];

int possible(int num)		// 0�̸� �Ұ���
{
	if (num == 0)
	{
		if (brokenButton[0])
		{
			return 0;
		}
		else
		{
			return 1;
		}
	}

	int length = 0;

	while (num)
	{
		if (brokenButton[num % 10])
		{
			return 0;
		}
		length++;
		num /= 10;
	}

	return length;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int a, b;
	cin >> a >> b;

	for (int i = 0; i < b; i++)
	{
		int c;
		cin >> c;
		brokenButton[c] = true;
	}

	int ans = a - 100;					// ���� ��ư�� ������ �ʴ� ���
	if (ans < 0)
	{
		ans = -ans;
	}

	for (int i = 0; i <= 1000000; i++)
	{
		int length = possible(i);

		if (length > 0)
		{
			int click = i - a;			// +,-�� ������ Ƚ��
			if (click < 0)
			{
				click = -click;
			}

			if (ans > length + click)
			{
				ans = length + click;
			}
		}
	}

	cout << ans << "\n";

	return 0;

}