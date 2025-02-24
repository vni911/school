//22110670 김정운//

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
#define PI 3.14

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void sort(int n, int x[]) {
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (x[i] > x[j])
                swap(&x[j], &x[i]);
        }
    }
}

double integrate(double f(double x), double a, double b) {
    int n = 1000;
    double h = (b - a) / n;
    double sum = (f(a) + f(b)) / 2;

    for (int i = 1; i < n; i++)
        sum += f(a + i * h);

    sum *= h;
    return sum;
}

double std_normal_pdf(double z) {
    return (exp(-(pow(z, 2)) / 2)) / (sqrt(2 * PI));
}

double std_normal_cdf(double a) {
    if (a >= 0)
        return 0.5 + integrate(std_normal_pdf, 0, a);
    else
        return 0.5 - integrate(std_normal_pdf, 0, -a);
}

double z_value(double alpha) {
    if (alpha < 0.5) {
        double z = 0.0;
        while (std_normal_cdf(z) < 1 - alpha)
            z += 0.005;
        return z;
    }
    else {
        return -z_value(1 - alpha);
    }
}


int main(void) {
    FILE *fp, *ofp;
    fp = fopen("input.txt", "r");
    
    int data[30] = { 0 }, n = 0, sum = 0, ssum = 0, q1, q3, h_test, t_value;
    double mean = 0.0, var = 0.0, mid, alpha, p;

    while (fscanf(fp, "%d", &data[n]) == 1) {
        sum += data[n];
        ssum += data[n] * data[n];
        n++;
    }
    sort(n, data);

    for (int i = 0; i < n; i++)
        printf("%3d", data[i]);
    fclose(fp);

    
    int min = data[0];
    int max = data[n - 1];

    if (n % 2 == 0)
        mid = (data[(n / 2) - 1] + data[n / 2]) / 2.0;
    else
        mid = data[n / 2];

    q1 = (n % 4 == 0) ? (data[n / 4] + data[(n / 4) - 1]) / 2 : data[n / 4];
    q3 = (n % 4 == 0) ? (data[3 * n / 4] + data[(3 * n / 4) - 1]) / 2 : data[3 * n / 4];

    mean = (double)sum / n;
    var = (ssum - n * mean * mean) / (n - 1);
    
    printf("\n데이터의 개수 = %2d\n", n);
    printf("합계 = %d\n", sum);
    printf("제곱합 = %d\n", ssum);
    printf("평균 = %lf\n", mean);
    printf("분산 = %lf\n", var);
    printf("표준편차 = %lf\n", sqrt(var));
    printf("최솟값 = %d\n", min);
    printf("최댓값 = %d\n", max);
    printf("제 1사분위수 = %d\n", q1);
    printf("제 2사분위수(중앙값) = %.2lf\n", mid);
    printf("제 3사분위수 = %d\n", q3);
    printf("\n");
    printf("alpha 값을 입력하세요: ");
    scanf("%lf", &alpha);
    printf("신뢰도 %.2lf%%의 신뢰구간: (%.2lf, %.2lf)\n", (1-alpha) * 100, mean - z_value(alpha/2) * (sqrt(var) / sqrt(n)), mean + z_value(alpha / 2) * (sqrt(var) / sqrt(n)));
    printf("\n");
    printf("모평균에 대한 검정값을 입력하세요: ");
    scanf("%d", &t_value);
    
    double z0 = (mean - t_value) / (sqrt(var) / sqrt(n));
    while (1) {
        printf("원하는 대립가설을 선택하세요 (1.양측검정 2.우측검정 3. 좌측검정): ");
        scanf("%d", &h_test);

        if (h_test == 1) {
            if (t_value > z_value) {
                p = 2 * (1 - std_normal_cdf(z0));
                break;
            }
            else if (t_value < z_value) {
                p = 2 * std_normal_cdf(z0);
                break;
            }
        }
        else if (h_test == 2) {
            p = 1 - std_normal_cdf(z0);
            break;
        }
        else if (h_test == 3) {
            p = std_normal_cdf(z0);
            break;
        }
        else
            printf("1,2,3 중에 해당하는 대립가설을 선택하시오.\n");
    }
    

    printf("\n검정통계량 값 : %.2lf\n", z0);
    printf("p-value 값 : %.2lf\n", p);

    if (alpha >= p)
        printf("\n유의수준 a에서 H_0을 기각하여 H_1을 주장할 수 있다.\n");
    else
        printf("\n유의수준 a에서 H_0을 기각하지 못하여 H_1을 주장할 수 없다.\n");

    ofp = fopen("output.txt", "w");
    fprintf(ofp,"최솟값 = %d\n", min);
    fprintf(ofp, "제 1사분위수 = %d\n", q1);
    fprintf(ofp, "중앙값 = %.2lf\n", mid);
    fprintf(ofp, "제 3사분위수 = %d\n", q3);
    fprintf(ofp, "최댓값 = %d\n", max);
    fprintf(ofp, "신뢰도 %.2lf%%의 신뢰구간: (%.2lf, %.2lf)\n", (1 - alpha) * 100, mean - z_value(alpha / 2) * (sqrt(var) / sqrt(n)), mean + z_value(alpha / 2) * (sqrt(var) / sqrt(n)));
    fprintf(ofp, "\n검정통계량 값 : %.2lf\n", z0);
    fprintf(ofp, "p-value 값 : %.2lf\n", p);
}