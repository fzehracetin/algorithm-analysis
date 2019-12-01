#include <stdio.h>
#include <stdlib.h>

typedef struct {
	int weight;
	int value;
}item;

int max(int a, int b) {
	if (a > b)
		return a;
	else
		return b;
}

void initialize_matrix (int** mtr, int w, int m) {
	int i;
	for(i = 0; i < w + 1; i++) {
		mtr[0][i] = 0;
	}
	for(i = 0; i < m + 1; i++) {
		mtr[i][0] = 0;
	}
}

void knapsack (int** mtr, item* items, int m, int w) {
	int i, j, weight, value, dif;
	for(i = 1; i < m + 1; i++) { //satir: item, sutun: weight
		weight = items[i].weight;
		value = items[i].value;
		for (j = 1; j < w + 1; j++) {
			if ( j >= weight) {
				dif = j - weight; // w - weight i
				mtr[i][j] = max(value + mtr[i-1][dif], mtr[i-1][j]);
			}
			else {
				mtr[i][j] = mtr[i-1][j];
			}
		}
	}
}

void print(int** mtr, int w, int m) {
	int i, j;
	printf("Matris \n");
	for(i = 0; i < m + 1; i++) {
		for(j = 0; j < w + 1; j++) {
			printf("%d ", mtr[i][j]);
		}printf("\n");
	}
}

int main(int argc, char **argv)
{
	int m = 4;
	int w = 5;
	int i;
	item* items = (item*) malloc(m*sizeof(item));
	items[1].weight = 2;
	items[1].value = 12;
	items[2].weight = 1;
	items[2].value = 10;
	items[3].weight = 3;
	items[3].value = 20;
	items[4].weight = 2;
	items[4].value = 15;
	
	int** mtr = (int**) calloc(m + 1, sizeof(int*));
	for(i = 0; i < m + 1; i++) {
		mtr[i] = (int*) calloc(w + 1, sizeof(int));
	}
	initialize_matrix(mtr, w, m);
	knapsack(mtr, items, m, w);
	print(mtr, w, m);
	return 0;
}
