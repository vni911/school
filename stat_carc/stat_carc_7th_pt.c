//22110670 김정운//

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
double binomial_pmf(int n, double p, int x);
double binomial_cdf(int n, double p, int x);

void main() {
    int n;
    double p, sum = 0;
    printf("이항확률변수의 모수 n과 p를 입력하세요\n");
    scanf_s("%d %lf", &n, &p);
    printf("\n  모수 %d과 %lf의 이항분포표의 평균 = %.2lf\n", n, p, n * p);
    printf("  모수 %d과 %lf의 이항분포표의 분산 = %.2lf\n", n, p, n * p * (1 - p));
    printf("\n");
    printf("  모수 %d과 %lf의 이항분포표\n", n, p);
    printf("\n");
    for (int i = 0; i <= n; i++) {
        printf("P(X=%2d)=%.5lf   P(X<= %2d)=%.5lf\n", i, binomial_pmf(n, p, i), i, binomial_cdf(n, p, i));
        sum += binomial_pmf(n, p, i);
    }
}

double binomial_pmf(int n, double p, int x) {
    if (x == 0)
        return pow(1 - p, n);
    else
        return binomial_pmf(n, p, x - 1) * (n - x + 1) * p / (x * (1 - p));

}
double binomial_cdf(int n, double p, int x) {
    double sum = 0;
    for (int i = 0; i <= x; i++)
        sum += binomial_pmf(n, p, i);
    return sum;
}