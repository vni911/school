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

    printf("��=%5d\n", sum);
    printf("������=%10d\n", ssum);
    printf("���=%lf\n", sum / 5.);

    /*
        int data, n, i, sum = 0, ssum = 0;
        double mean = 0;

        printf("�������� ������ �Է��ϼ���: ");
        scanf_s("%d", &n);

        for (i = 0; i < n; i++) {
            printf("�����͸� �Է��ϼ���: ");
            scanf_s("%d", &data);
            sum += data;
            ssum += pow(data, 2);
        }

        mean = (double)sum / n; // ��� ���

        printf("�Է��� �������� ������ %2d�� �Դϴ�.\n", n);
        printf("�հ� = %d\n", sum);
        printf("��� = %.2lf\n", mean);
        printf("������ = %d\n", ssum);
        printf("�л� = %.2lf\n", (ssum - n * pow(mean, 2)) / (n - 1));
        printf("ǥ������ = %.2lf\n", sqrt((ssum - n * pow(mean, 2)) / (n - 1)));

        return 0; // main �Լ��� ��ȯ �� �߰�
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
