#include <stdio.h>

int fact(int n);
void main()
{
	int n;
	printf("정수 입력 후 Enter>");
	scanf_s("%d", &n);
	printf("1부터 %d까지 곱: %d\n", n, fact(n));
}

int fact(int n)
{
	if (n == 1)
		return 1;
	return n * fact(n - 1);
}
