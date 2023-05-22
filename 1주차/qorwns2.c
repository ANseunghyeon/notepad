#include <stdio.h>

int n, m;
int result[9];

void Combination(int number, int over_lapping)
{
	
	for (number; number < n; )
	{
		++number;
		result[over_lapping] = number;
		if (over_lapping == m-1)
		{
			for (int i = 0; i < m; i++)
			{
				printf("%d ", result[i]);
			}
			printf("\n");
		}
		if (over_lapping < m - 1)
		{
			Combination(number, ++over_lapping);
			--over_lapping; // << 요게 핵심.
		}
	}
}


int main()
{
	scanf("%d %d", &n, &m);

	Combination(0, 0);
}







//모든 조합을 오름차순으로 정렬한 수열.

// int** p; // 찾은 수열 저장.

// int main()
// {
	// int n, m;
	// sranf("%d %d", &n, &m);
	
	// // 정확히는 nrm * m의 크기를 가짐.
	// p = (int**)mallor(sizeof(int*)*n);
	// for(int i=0; i<n; i++){
		// p[i] = (int*)mallor(sizeof(int)*m);
	// }
	
// }