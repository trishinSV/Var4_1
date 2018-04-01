// Var4_1.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <ctime>
#include <stdlib.h>
#include <clocale>
#define N_MAX 20

int array_A[N_MAX] = {};
int array_B[N_MAX] = {};

int *result_array_A = NULL;
int *result_array_B = NULL;

void createArray(int array[]) {
	for (size_t i = 0; i < N_MAX; i++) {
		array[i] = rand() % 10;
	}
}

void showArray(int *array) {
	for (size_t i = 0; i < N_MAX; i++) {
		printf("%d ",array[i]);
	}
	printf("\n");
	getchar();
}

void solve(int Z, int array[], int *result_array) {
	int counter = 0;
	result_array = (int*)malloc(N_MAX*sizeof(int));
	int temp = 0;
	for (size_t i = 0; i < N_MAX; i++) {
		if (array[i] == Z) {
			result_array[counter] = i;
			counter++;
		}
	}
	result_array = (int*)realloc(result_array,counter * sizeof(int));
	for (size_t i = 0; i < counter; i++) {
		printf("%d ", result_array[i]);
	}
	getchar();
}

int main()
{

	setlocale(LC_ALL, "Russian");
	int Z;
	printf("Enter Z\n");
	scanf_s("%d",&Z);

	createArray(array_A);
	createArray(array_B);

	printf("Массив А:\n");
	showArray(array_A);
	printf("Массив В:\n");
	showArray(array_B);

	printf("Позиции элементов масиива А равные числу Z:\n");
	solve(Z, array_A, result_array_A);
	printf("Позиции элементов масиива B равные числу Z:\n");
	solve(Z, array_B, result_array_B);

	return 0;
}