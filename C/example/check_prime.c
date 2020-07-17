#include <stdio.h>

void check_prime(int N);

void main()
{
	int num; // 입력받는 숫자입니다.
	printf("숫자를 입력하시오: ");
	scanf_s("%d", &num);

	if (num <= 0) // 입력되는 숫자가 자연수 이어야합니다.
		printf("잘못된 입력값 입니다\n");

	else
		check_prime(num); // 자연수일 경우 프로그램을 실행합니다.

}

void check_prime(int N)
{
	int i, j, count=0; 

	for (int i = 1; i < N; i++) { // 입력받은 수를 1부터 N까지 j와 나누면서 나머지를 확인합니다.
		for (j = 2; j <= i; j++) {
			if (i % j == 0) { // 나머지가 0이면 나누어떨어지는 수를 의미하기 때문에 소수가 아닙니다.
				break;
			}
		}
		if (i == j) { // 소수를 의미합니다.
			printf("%d\n", i);
			count++; //count를 이용해 수를 셉니다.
		}
	}
	printf("\n소수는 모두 %d 개 이다.\n", count);
}
