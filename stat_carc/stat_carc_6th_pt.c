//22110670 김정운//

#include <stdio.h>
#include <math.h>
#define PI 3.141592

double integrate(double f(double x), double a, double b) {
    int n = 1000;
    double h = (b - a) / n;
    double sum = 0;

    sum = (f(a) + f(b)) / 2;
    for (int i = 1; i < n; i++)
        sum += f(a + i * h);
    sum *= h;
    return sum;
}

double std_normal_pdf(double z) {
    return (exp(-(pow(z, 2)) / 2)) / (sqrt(2 * PI));
}

double std_normal_cdf(double a) {
    double val;
    if (a >= 0) {
        val = 0.5 + integrate(std_normal_pdf, 0, a);
    }
    else if (a < 0) {
        val = 0.5 - integrate(std_normal_pdf, 0, -a);
    }
    else {
        val = 0.5;
    }
    return val;
}

int main() {
    printf("      표준정규누적분포표\n");
    printf("\n");
    printf("      ");

    for (int col = 0; col <= 9; col++) {
        printf("%6.2lf ", col / 100.0);
    }
    printf("\n-----------------------------------------------------------------------------\n");

    for (int row = -35; row <= 35; row++) {
        double row_value = row / 10.0;

        if (row == 0) {
            printf(" -0.0 | ");
            for (int col = 0; col <= 9; col++) {
                double col_value = col / 100.0;
                double a = row_value + col_value;
                printf("%6.4lf ", std_normal_cdf(-a));
            }
            printf("\n");
                
            printf("  0.0 | ");                                             
            for (int col = 0; col <= 9; col++) {
                double col_value = col / 100.0;
                double a = row_value + col_value;
                printf("%6.4lf ", std_normal_cdf(a));
            }
            printf("\n");
        }
        else {
            printf("%5.1lf | ", row_value);
            for (int col = 0; col <= 9; col++) {
                double col_value = col / 100.0;
                double a = row_value + col_value;
                printf("%6.4lf ", std_normal_cdf(a));
            }
            printf("\n");
        }
    }
    return 0;
}