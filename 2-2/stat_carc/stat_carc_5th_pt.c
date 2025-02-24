#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

/*
int main(void) {
	int i;
	int n_head = 0, n_tail = 0;
	srand(time(NULL));

	for (i = 1; i <= 50; i++) {
		if (rand() % 2 == 0)
			n_head += 1;
		else
			n_tail += 1;
	}
	printf("¾Õ¸é¼ö : %d\n", n_head);
	for (i = 0; i < n_head; i++) {
		printf("¡á");
	}
	printf("\nµÞ¸é¼ö : %d\n", n_tail);
	for (i = 0; i < n_tail; i++) {
		printf("¡á");
	}
}
*/
/*
int main(void) {
	int i;
	int n_head = 0, n_tail = 0;
	double real_number;
	double p_head = 0.3;

	srand(time(NULL));

	for (i = 1; i <= 50; i++) {
		real_number = (double)rand() / RAND_MAX;

		if (real_number < p_head)
			n_head += 1;
		else
			n_tail += 1;
	}
	printf("¾Õ¸é¼ö : %d\n", n_head);
	for (i = 0; i < n_head; i++) {
		printf("¡á");
	}
	printf("\nµÞ¸é¼ö : %d\n", n_tail);
	for (i = 0; i < n_tail; i++) {
		printf("¡á");
	}
}
*/

int main(void) {
	int i, int_random;
	int n_1 = 0, n_2 = 0, n_3 = 0, n_4 = 0, n_5 = 0, n_6 = 0;
	double mean;
	srand(time(NULL));

	for (i = 1; i <= 100; i++) {
		int_random = rand()%6 + 1;
		if (int_random == 1)
			n_1 += 1;
		else if(int_random == 2)
			n_2 += 1;
		else if (int_random == 3)
			n_3 += 1;
		else if (int_random == 4)
			n_4 += 1;
		else if (int_random == 5)
			n_5 += 1;
		else if (int_random == 6)
			n_6 += 1;
	}
	printf("1 : %d\n", n_1);
	for (i = 0; i < n_1; i++) {
		printf("¡á");
	}
	printf("\n2 : %d\n", n_2);
	for (i = 0; i < n_2; i++) {
		printf("¡á");
	}
	printf("\n3 : %d\n", n_3);
	for (i = 0; i < n_3; i++) {
		printf("¡á");
	}
	printf("\n4 : %d\n", n_4);
	for (i = 0; i < n_4; i++) {
		printf("¡á");
	}
	printf("\n5 : %d\n", n_5);
	for (i = 0; i < n_5; i++) {
		printf("¡á");
	}
	printf("\n6 : %d\n", n_6);
	for (i = 0; i < n_6; i++) {
		printf("¡á");
	}

	mean = ((n_1 * 1 + n_2*2 + n_3*3 + n_4*4 + n_5*5 + n_6*6) / 100);
	printf("\nÆò±Õ: %.2lf", mean);
}