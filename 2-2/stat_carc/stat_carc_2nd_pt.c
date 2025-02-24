#include <stdio.h>

//22110670 김정운//

void main() {
    int a, b = 0;
    printf("두 개의 정수값을 입력하세요:");
    scanf_s("%d %d", &a, &b);
    printf("%d + %d = %d\n", a, b, a + b); //덧셈
    printf("%d - %d = %d\n", a, b, a - b); //뺄셈
    printf("%d * %d = %d\n", a, b, a * b); //곱셈
    printf("%d / %d = %2.1lf\n", a, b, (double)a / b); //나눗셈 소수점 첫째자리까지
}