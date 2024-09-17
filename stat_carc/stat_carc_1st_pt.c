#include <stdio.h>
#include <limits.h>
#include <float.h>

void main(){
    
    printf("컴퓨터의 int형 메모리 크기는 %d입니다\n", sizeof(int));
    int number = 2147483647;
    int aaa = 2147483647+1;
    printf("int = %d\n", number);
    printf("int = %d\n", aaa);
    
    int a = 97; // 'a'의 ASCII 값
    int b = 98; // 'b'의 ASCII 값
    int c = 99; // 'c'의 ASCII 값
    printf("%c\n", a);
    printf("%c\n", b);
    printf("%c\n", c);

    printf("int의 최소값 (INT_MIN): %d\n", INT_MIN);
    printf("int의 최대값 (INT_MAX): %d\n", INT_MAX);

    printf("double의 최대값 (LDBL_MAX) : %d\n", LDBL_MAX);
    printf("float의 최대값 (FLT_MAX) : %d\n", FLT_MAX);
    
}