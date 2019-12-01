#include <stdio.h>
#include <stdlib.h>

int min (int a, int b, int c) {
	if (a < b) {
		if ( a < c)
			return a;
		else 
			return c;
	}
	else if (b < c)
		return b;
	else
		return c;
}

void initialize_matrix(int** mtr, int m, int n) {
	int i;
	for(i = 0; i < n + 1; i++) {
		mtr[0][i] = i;
	}
	for(i = 0; i < m + 1; i++) {
		mtr[i][0] = i;
	}
}

void edit_distance(int** mtr, char* word1, char* word2, int m, int n) {
	int i, j, insert, delete, change;
	for (i = 1; i < m + 1; i++) { // satir - word1
		for (j = 1; j < n + 1; j++) { // sutun - word2
			if ( word1[i] == word2[j]) 
				mtr[i][j] = mtr[i-1][j-1];
			else {
				insert = mtr[i-1][j] + 1;
				delete = mtr[i][j-1] + 1;
				change = mtr[i-1][j-1] + 1;
				mtr[i][j] = min(insert, delete, change);
			}
		}
	}
}

void print(int** mtr, int m, int n) {
	int i, j;
	printf("Matris \n");
	for(i = 0; i < m + 1; i++) {
		for(j = 0; j < n + 1; j++) {
			printf("%d ", mtr[i][j]);
		}printf("\n");
	}
}

int main(int argc, char **argv)
{
	int i, m, n;
	m = 5; n = 4;
	char word1[6] = "0maths", word2[5] = "0arts";
	
	int** mtr = (int**) calloc(m + 1, sizeof(int*)); //satir-word1
	for(i = 0; i < m + 1; i++) {
		mtr[i] = (int*) calloc(n + 1, sizeof(int)); //sutun-word2
	}
	initialize_matrix(mtr, m, n);
	edit_distance(mtr, word1, word2, m, n);
	print(mtr, m, n);
	return 0;
}
