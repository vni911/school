#include <stdio.h>
#include <math.h>
#define PI 3.141592653589793

int main(void) {
	/*
	double cel, faren;
	printf("¼·¾¾ ¿Âµµ¸¦ ÀÔ·ÂÇÏ½Ã¿À : ");
	scanf_s("%lf", &cel);
	faren = cel * 1.8 + 32.0;
	printf("¼·¾¾ %1.2lfµµ´Â È­¾¾ %1.2lfµµÀÌ´Ù\n", cel, faren);
	*/
	/*
	int x = 1, y = 10, a = 4, b = 7;
	x = x + 2;
	y = y + 2;
	printf("%d\n", x);
	printf("%d\n", y);
	printf("%d\n", a);
	printf("%d\n", a++);
	printf("%d\n", a);
	printf("%d\n", b);
	printf("%d\n", b++);
	printf("%d\n", b);
	*/
	/*
	int length, height;
	double area;
	length = 10;
	height = 5;
	area = 0.5 * height * length;
	printf("³ÐÀÌ=%lf\n", area);
	*/
	/*
	int l, h = 0;
	double area_1 = 0;
	printf("put length and height :\n");
	scanf_s("%d %d",&l, &h);
	area_1 = 0.5 * h * l;
	printf("length : %d\nheight : %d\n³ÐÀÌ = % lf\n", l, h, area_1);
	*/
	/*
	double a =	exp(5.4)*fabs(240.)*log(10.)/pow(5.,2.);
	printf("%lf", a);
	*/
	int x;
	double y;
	printf("put x, you want :");
	scanf_s("%d", &x);
	y = (1 / sqrt(2 * PI))*exp(pow(-x,2.) / 2);
	printf("Ç¥ÁØÁ¤±ÔÈ®·ü¹ÐµµÇÔ¼ö f(x)ÀÇ °ª : %lf", y);
}