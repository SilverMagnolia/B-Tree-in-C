#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_VALUE	50

int main()
{
	int arr[MAX_VALUE];
	int i,j,n;
	FILE * fptr;
	
	srand(time(NULL));
	fptr = fopen("/Users/bagjongho/Documents/BTree/ran.txt", "w");

	if(fptr == NULL)
	{
		printf("failed to open file.");
		exit(1);
	}

	i=0;
	while(i<MAX_VALUE)
	{
		Random:
			n = rand()%MAX_VALUE + 1;
			for(j=0; j<i; j++)
			{
				if(arr[j] == n)
					goto Random;
			}		
			arr[i] = n;
			fprintf(fptr, "%d\n", n);
			i++;
	}
	return 0;
}
