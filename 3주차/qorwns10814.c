#include <stdio.h>
#define max 100000
// 삽입정렬을 하려다 시간초과로 합병정렬로 바꿈.
// 메모리가22088 KB

typedef struct member {
	int age;
	char name[20];
} member;

member members[max];

void input(int num)
{
	for (int i = 0; i<num; i++)
	{
		scanf("%d %s", &members[i].age, members[i].name);
	}
}

// void insert_sort(int num)
// {
// for(int i=1; i<num; i++)
// {
// int j=i;
// member t = members[i];
// for(; members[j-1].age > t.age && j>=0;)
// {
// members[j] = members[j-1];
// j--;
// }
// members[j] = t;
// }
// }
void merge(int p, int q, int r) {
	int i = p, j = q + 1, k = p;
	member tmp[max]; // 새 배열
	while (i <= q && j <= r) {
		if (members[i].age <= members[j].age) tmp[k++] = members[i++];
		else tmp[k++] = members[j++];
	}
	while (i <= q) tmp[k++] = members[i++];
	while (j <= r) tmp[k++] = members[j++];
	for (int a = p; a <= r; a++) members[a] = tmp[a];
}

void mergeSort(int p, int r) {
	int q;
	if (p<r) {
		q = (p + r) / 2;
		mergeSort(p, q);
		mergeSort(q + 1, r);
		merge(p, q, r);
	}
}


void print_members(int num)
{
	for (int i = 0; i<num; i++)
	{
		printf("%d %s", members[i].age, members[i].name);
		if (i != num - 1)
			printf("\n");
	}
}

int main()
{
	int num;
	scanf("%d", &num);
	input(num);
	mergeSort(0, num - 1);
	print_members(num);
}