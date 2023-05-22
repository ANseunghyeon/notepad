#include <stdio.h>

int main()
{
	char korea[6] = {'K', 'O', 'R', 'E', 'A'};
	char yonsei[7] = {'Y', 'O', 'N', 'S', 'E', 'I'};
	
	int kpnt =0;
	int ypnt =0;
	
	char input[500000];
	scanf("%s", input);
	
	for(int i=0; input[i]!='\0'; i++)
	{
		if(korea[kpnt] == input[i])
		{
			kpnt++;
			if(kpnt == 5)
			{
				printf("KOREA");
				break;
			}
		}
		if(yonsei[ypnt] == input[i])
		{
			ypnt++;
			if(ypnt == 6)
			{
				printf("YONSEI");
				break;
			}
		}
	}
}