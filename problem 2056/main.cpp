#include <stdio.h>

int main(void)
{
	int test, arr[8];
	scanf_s("%d", &test);

	for (int i = 1; i <= test; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			scanf_s("%d", &arr[j]);
		}
		if ((arr[5] == 2) && ((arr[6] == 2) && arr[7] == 9) || (arr[6] == 3))
			printf("#%d -1\n", i);
		else if ((arr[5] == 9 || arr[5] == 10 || arr[5] == 4 || arr[5] == 6) && (arr[6] == 3) && (arr[7] == 1))
			printf("#%d -1\n", i);
		else
			printf("#%d %d%d%d%d/%d%d/%d%d\n", i, arr[0], arr[1], arr[2], arr[3], arr[4], arr[5], arr[6], arr[7]);
	}
	return 0;
}