#include <stdio.h>
#include <stdlib.h>

int** tri;

void input(int n)
{

	tri = (int**)malloc(sizeof(int *) * (n + 1));
	tri[0] = (int*)malloc(sizeof(int) * 1);
	for (int i = 1; i<n+1; i++)
	{
		tri[i] = (int*)malloc(sizeof(int) * (i + 1));
	}

	for (int i = 0; i<n; i++)
	{
		for (int j = 0; j<i+1; j++)
		{
			scanf("%d", &tri[i][j]);
		}
	}
}


int pre_max(int i, int j)
{
	int max, left = 1, right = 1;
	if ((i - 1)<0)
		max = 0;
	else if (j - 1 < 0)
		max = tri[i - 1][j];
	else if (j == i)
		max = tri[i - 1][j - 1];
	else if (tri[i - 1][j] > tri[i - 1][j - 1])
	{
		max = tri[i - 1][j];
	}
	else
		max = tri[i - 1][j - 1];

	return max;
}

void plus(int i, int j)
{
	tri[i][j] += pre_max(i, j);
}
int find_max(int n)
{
	int max = 0;
	for (int j = 0; j<n; j++)
	{
		if (tri[n - 1][j] > max)
			max = tri[n - 1][j];
	}
	return max;
}
int main()
{
	int n;
	scanf("%d", &n);
	input(n);
	for (int i = 0; i<n; i++)
	{
		for (int j = 0; j<i + 1; j++)
		{
			plus(i, j);
		}
	}
	printf("%d", find_max(n));
}