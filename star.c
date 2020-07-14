#include <stdio.h>

void main()
{
	for (int i = 1; i <= 5; i += 1)
	{
		for (int j = 1; j <= i; j += 1)
			printf("*");
	    printf("\n");
	}

}
