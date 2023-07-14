#include <stdio.h>
#include <stdlib.h>


int** tomatomap;
typedef struct location{
	int x;
	int y;
	short visit;
}location;

location* tomato_location;
int front = 0, rear = 0, max;
int date = 0;

void input(const int n, const int m)
{
	max = n*m;
	tomatomap = (int**)malloc(sizeof(int *)*m);
	tomato_location = (location*)malloc(sizeof(location)*n*m);
	
	for(int i=0; i<m; i++)
	{
		tomatomap[i] = (int*)malloc(sizeof(int*)*n);
		for(int j=0; j<n; j++)
		{
			scanf("%d", &tomatomap[i][j]);
			if(tomatomap[i][j] == 1)
			{
				tomato_location[rear].x = j;
				tomato_location[rear].y = i;
				tomato_location[rear].visit = 1;
				rear++; // 처음 정보 queue에 삽입.
			}
		}
	}
}

void enque(const location newtomato)
{
	if((rear+1)%max)
		return;
	
	tomato_location[(rear++)%max] = newtomato; 
}

location deque()
{	
	return tomato_location[(top++)%max];
}

void bfs(const int n, const int m)
{
	if(top%max == rear%max)
		return;
	location newtomato = deque;
	if(newtomato.visit == 1)
		return;
	
	
}

int check(const int n, const int m)
{
	
}

int main()
{
	int n, m;
	scanf("%d %d", &n, &m);
	input(n, m);
}