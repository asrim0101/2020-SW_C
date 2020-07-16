#define _CRT_SECURE_NO_WARNINGS //scanf_s 대신 scanf를 이용하기 위함
#include <stdio.h>
void main() {
 
    int num1 = 0;
    int    num2 = 0;
    char c = 0;
    printf("수식을 입력하시오:");
    scanf("%d %c %d", &num1, &c, &num2);
    switch (c) {
    case('+'):
        printf("%d", num1 + num2);
        break;
    case('-'):
        printf("%d", num1 - num2);
        break;
    case('/'):
        printf("%d", num1 / num2);
        break;
    case('*'):
        printf("%d", num1 * num2);
        break;
    }
    
}
