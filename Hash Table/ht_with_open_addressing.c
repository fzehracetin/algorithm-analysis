#include <stdio.h>
#include <stdlib.h>

/* Hash table insert, delete and search operations 
 * in open addresing mode with linear probing.
 * */
 
void search (int key, int* ht, int m) {
	int adr,  i = 0;
	adr = key % m;
	
	while( (ht[adr]) && (ht[adr] != key) && (i < m) ) {
		adr = (adr + 1) % m; //linear probing
		i++;
	}
	
	if ( ht[adr] == key) 
		printf("Key is in the %dth address. \n", adr);
	else
		printf("Key is not in the hash table. \n");
}

void insert (int key, int* ht, int m) {
	int adr, i = 0;
	adr = key % m;
	
	while( (ht[adr] != NULL) && (i < m) ) {
		adr = (adr + 1) % m; //linear probing
		i++;
	}
	
	if (ht[adr] == NULL) {
		ht[adr] = key;
		printf("Element inserted %dth address. \n", adr);
	} 
	else {
		printf("Table is full! \n");
	}
}

int main(int argc, char **argv)
{
	int m;
	printf("Enter size of the hash table\n");
	scanf("%d", &m);
	int* ht = (int*) malloc(sizeof(int));
	int* flag = (int*) calloc(1, sizeof(int)); //for delete operation.
	
	
	return 0;
}
