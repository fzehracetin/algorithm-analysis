#include <stdio.h>
#include <stdlib.h>

/* Hash table insert, delete and search operations 
 * in open addresing mode with linear probing.
 * */
 
void print(int* ht, int *flag, int m) {
	int i;
	printf("Hash table: \n");
	for (i = 0; i < m; i++) {
		printf("%d ", ht[i]);
	}printf("\n");
	
	printf("Flags: \n");
	for (i = 0; i < m; i++) {
		printf("%d ", flag[i]);
	}printf("\n");
}
 
int search (int key, int* ht, int m, int* flag) {
	int adr,  i = 0;
	adr = key % m;
	
	while( (ht[adr] || flag[adr]) && (ht[adr] != key) && (i < m) ) {
		adr = (adr + 1) % m; //linear probing
		i++;
	}
	
	if ( ht[adr] == key) {
		printf("%d is in the %dth address. \n", key, adr);
	}
	else {
		printf("%d is not in the hash table. \n", key);
		adr = -1;
	}
	return adr;
}

void insert (int key, int* ht, int m, int* flag) {
	int adr, i = 0;
	adr = key % m;
	
	while( ( ht[adr])  && (i < m) ) {
		adr = (adr + 1) % m; //linear probing
		i++;
	}
	
	if (!ht[adr]) {
		ht[adr] = key;
		flag[adr] = 0;
		printf("%d inserted %dth address. \n", key, adr);
	} 
	else {
		printf("Table is full! \n");
	}
}

int delete(int key, int *ht, int m, int *flag) {
	int adr;
	adr = search(key, ht, m, flag);
	if (adr != -1) {
		ht[adr] = 0;
		flag[adr] = 1;
		printf("%d deleted in %dth address. \n", key, adr);
		return 1;
	}
	else {
		printf("%d is not in the hash table \n", key);
		return 0;
	}
}

int main(int argc, char **argv)
{
	int m;
	//printf("Enter size of the hash table. \n");
	//scanf("%d", &m);
	m = 13;
	int* ht = (int*) calloc(m, sizeof(int));
	int* flag = (int*) calloc(m, sizeof(int)); //for delete operation.
	insert(79, ht, m, flag);
	insert(69, ht, m, flag);
	insert(58, ht, m, flag);
	insert(72, ht, m, flag);
	delete(69, ht, m, flag);
	insert(14, ht, m, flag);
	search(58, ht, m, flag);
	insert(4, ht, m, flag);
	print(ht, flag, m);
	
	
	
	return 0;
}
