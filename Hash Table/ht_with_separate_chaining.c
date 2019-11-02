#include <stdio.h>
#include <stdlib.h>

typedef struct node {
	int key;
	struct node* next;
}node;

typedef struct hash {
	int count;
	node* head;
} hash;

node* createNode(int key) {
	node* myNode = (node*) calloc(1, sizeof(node));
	if (myNode == NULL) {
		printf("Node could not allocated \n");
	}
	myNode->key = key;
	myNode->next = NULL;
	return myNode;
}

void insert (int key, hash* hashTable, int m) {
	int i;
	i = key % m;
	node* newNode = createNode(key);
	if (hashTable[i].head == NULL) {
		hashTable[i].head = newNode;
		hashTable[i].count = 1;
		printf("%d inserted in the hash table \n", key);
	}
	else {
		newNode->next = hashTable[i].head;
		hashTable[i].head = newNode;
		hashTable[i].count += 1;
		printf("%d inserted in the hash table \n", key);
	}
}

node* search (int key, hash* hashTable, int m) {
	int i = key % m;
	node* head = hashTable[i].head;
	node* current = head;
	while((current != NULL) && (current->key != key)) {
		current = current->next;
	}
	if ( ! current) {
		printf("%d is not in the hash table \n", key);
		return NULL;
	}
	else {
		printf("%d found in the hash table \n", key);
		return current;
	}
}

void delete (int key, hash* hashTable, int m) {
	int i = key % m;
	node* head = hashTable[i].head;
	node* current = head;
	if (head->key == key) {
		hashTable[i].head = hashTable[i].head->next;
		hashTable[i].count--;
		printf("%d was head in the table, deleted\n", key);
	}
	else {
		while((current->next != NULL) && (current->next->key != key)) {
			current = current->next;
		}
		if (current->next->key == key) {
			current->next = current->next->next;
			hashTable[i].count --;
			printf("%d deleted\n", key);
		}
		else
			printf("%d is not in the table!!\n", key);
	}
}

void print(int m, hash* hashTable) {
	int i;
	node* current;
	printf("Hash Table \n");
	for(i = 0; i < m; i++) {
		printf("Hash[%d]'s count: %d \n", i, hashTable[i].count);
		if (hashTable[i].count){
			printf("Elements: ");
			current = hashTable[i].head;
			printf("%d", current->key);
			current = current->next;
			while (current) {
				printf("->");
				printf("%d", current->key);
				current = current->next;
			} printf("\n");
		}
	}
}

int main(int argc, char **argv)
{
	int m, i;
	//printf("Enter the size of the hash table \n");
	//scanf("%d", &m);
	m = 7;
	hash* hashTable = (hash*) calloc (m, sizeof(hash));
	
	for (i = 0; i < m ; i++) {
		hashTable[i].head = NULL;
		hashTable[i].count = 0;
	}
	
	insert(5, hashTable, m);
	insert(6, hashTable, m);
	insert(12, hashTable, m);
	insert(1, hashTable, m);
	print(m, hashTable);
	delete(5, hashTable, m);
	delete(12, hashTable, m);
	
	search(5, hashTable, m);
	search(1, hashTable, m);

	
}
