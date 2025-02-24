#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

int main(void)
{
    /*
    int data, n, sum = 0, ssum = 0;

    for (n = 0; n < 5; n++){
        scanf_s("%d", &data);
        sum += data;
        ssum += pow(data, 2);
    }

    printf("합=%5d\n", sum);
    printf("제곱합=%10d\n", ssum);
    printf("평균=%lf\n", sum / 5.);

    /*
        int data, n, i, sum = 0, ssum = 0;
        double mean = 0;

        printf("데이터의 개수를 입력하세요: ");
        scanf_s("%d", &n);

        for (i = 0; i < n; i++) {
            printf("데이터를 입력하세요: ");
            scanf_s("%d", &data);
            sum += data;
            ssum += pow(data, 2);
        }

        mean = (double)sum / n; // 평균 계산

        printf("입력한 데이터의 개수는 %2d개 입니다.\n", n);
        printf("합계 = %d\n", sum);
        printf("평균 = %.2lf\n", mean);
        printf("제곱합 = %d\n", ssum);
        printf("분산 = %.2lf\n", (ssum - n * pow(mean, 2)) / (n - 1));
        printf("표준편차 = %.2lf\n", sqrt((ssum - n * pow(mean, 2)) / (n - 1)));

        return 0; // main 함수의 반환 값 추가
        */

        /*
        int i;
        srand(time(NULL));
        for (i = 1; i <= 10; i++)
        {
            printf("%7lf\n", (double)rand() / RAND_MAX);
        }
        return 0;
    }*/

        /*
            srand(time(NULL));

            for (int i = 0; i < 10; i++) {
                for (int j = 0; j < 10; j++) {
                    int random_number = rand() % 10000;
                    printf("%4d ", random_number);
                }
                printf("\n");
            }

            return 0;
            */

    srand(time(NULL));
    printf("--------------------------------------------------------------\n");
    for (int i = 1; i <= 400; i++) {
        printf("%d", rand() % 10);
        if (i % 4 == 0)
            printf("  ");
        if (i % 40 == 0)
            printf("\n");
    }
    return 0;
}
