#include <stdio.h>
#include <string.h>
#define MAX_N_SIZE 101

char input[MAX_N_SIZE][MAX_N_SIZE];
int n, r, g, b, rg;
char visited[MAX_N_SIZE][MAX_N_SIZE];
const int dx[4] = {1, -1, 0, 0};
const int dy[4] = {0, 0, 1, -1};

void dfs(const int x, const int y, const char* c)
{
	visited[x][y]=1;
	int nx, ny;
	
	for(int i=0; i<4; i++){
		nx = x + dx[i];
		ny = y + dy[i];
		if(nx < 0 || ny < 0 || nx >= n || ny >= n)
			continue;
		if(visited[nx][ny] == 0 && strchr(c, input[nx][ny]) != NULL)
		{
			dfs(nx, ny, c);
		}
	}
	
}

void main(){
	scanf("%d", &n);
	
	for(int i=0; i<n; i++)
	{
		scanf("%s", input[i]);
	}
	for(int i=0; i<n; i++)
	{
		for(int j=0; j<n; j++)
		{
			if(!visited[i][j])
			{
				if(input[i][j] == 'R')
				{dfs(i, j, "R"); r++;}
				else if(input[i][j] == 'G')
				{dfs(i, j, "G"); g++;}
				else if(input[i][j] == 'B')
				{dfs(i, j, "B"); b++;}
			}
		}
	}	

	for(int i=0; i<n; i++)
	{
		for(int j=0; j<n; j++)
		{
			visited[i][j] = 0;
		}
	}
	// b=0
	for(int i=0; i<n; i++)
	{
		for(int j=0; j<n; j++)
		{
			if(!visited[i][j])
			{
				if(input[i][j] == 'R' || input[i][j] == 'G')
				{dfs(i, j, "RG"), rg++;}
				else if(input[i][j] == 'B')
				{dfs(i, j, "B");} // {dfs(i, j, "B");b++;}
			}
		}
	}	
	printf("%d %d", r+g+b, rg+b);	
}