#include <stdio.h>

int main() {
	int c;
	double a, b, d, result;
	printf("1: 삼각형의 넓이, 2: 사각형의 넓이, 3: 사다리꼴의 넓이\n");
	printf("1~3 사이의 숫자를 입력하시오: ");
	scanf_s("%d", &c);
	
	switch (c)
	{
	case 1:
		printf("삼각형의 밑변: ");
		scanf_s("%lf", &a);
		printf("삼각형의 높이: ");
		scanf_s("%lf", &b);
		result = (a * b) / 2;
		printf("삼각형의 넓이 = %.1lf\n", result);
		break;
	
	case 2:
		printf("사각형의 밑변: ");
		scanf_s("%lf", &a);
		printf("사각형의 높이: ");
		scanf_s("%lf", &b);
		result = a * b;
		printf("사각형의 넓이 = %.1lf\n", result);
		break;
	
	case 3:
	
		printf("사다리꼴의 밑변: ");
		scanf_s("%lf", &a);
		printf("사다리꼴의 윗변: ");
		scanf_s("%lf", &b);
		printf("사다리꼴의 높이: ");
		scanf_s("%lf", &d);
		result = d * (a + b) / 2;
		printf("사다리꼴의 넓이 = %.1lf\n", result);
		break;
	
	}
	return 0;
}
