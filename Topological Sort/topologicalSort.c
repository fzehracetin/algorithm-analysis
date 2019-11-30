#include <stdio.h>
#include <stdlib.h>

#define n 6

typedef struct adjacency {
	char u;
	struct adjacency* next;
}adjacency;

typedef struct {
	char que[n];
	int rear;
	int front;
}queue;

void initialize_queue(queue* q) {
	q->rear = 0;
	q->front = 0;
}

void enqueue(queue *q, char x) {
	q->que[q->rear++] = x;
}

char dequeue(queue *q) {
	if (q->front < q->rear)
		return q->que[q->front++];
	else 
		return '\0';
}

adjacency* node_maker (char c) {
	adjacency* a = (adjacency*) malloc(sizeof(adjacency));
	a->u = c;
	a->next = NULL;
	return a;
}

void indegree_changer(int i, int* indegree, adjacency* a, int selection) {
	int j;
	adjacency* node;
	if (a[i].next) {
			j = 0;
			while ((j < n) && (a[j].u != a[i].next->u)) {
				j++;
			}			
			if ((a[j].u == a[i].next->u) && (selection == 0))
				indegree[j]++;	
			else if ((a[j].u == a[i].next->u) && (selection == 1))
				indegree[j]--;
			node = a[i].next;
		}
		while (node->next) {
			j = 0;
			while ((j < n) && (a[j].u != node->next->u)) {
				j++;
			}			
			if ((a[j].u == node->next->u) && (selection == 0))
				indegree[j]++;	
			else if ((a[j].u == node->next->u) && (selection == 1))	
				indegree[j]--;
			node = node->next;
		}
}

void indegree_maker (int* indegree, adjacency* a) {
	int i;
	for (i = 0; i < n; i++) {
		indegree_changer(i, indegree, a, 0);
	}
	print(indegree);
}

void insert_zeros_to_queue(queue *q, adjacency* a, int* indegree) {
	int i;
	for (i = 0; i < n; i++) {
		if (indegree[i] == 0) {
			indegree[i] = -1;
			enqueue(q, a[i].u);
		}
	}
}

void topological_sort(adjacency* a, queue *q, int *indegree) {
	char ch;
	int i;
	insert_zeros_to_queue(q, a, indegree);
	ch = dequeue(q);
	while(ch != '\0') {
		printf("%c", ch);
		i = 0;
		while((i < n) && (a[i].u != ch)) {
			i++;
		}
		indegree_changer(i, indegree, a, 1);
		insert_zeros_to_queue(q, a, indegree);
		ch = dequeue(q);	
	}printf("\n");
}

void print(int* indegree) {
	int i;
	for(i = 0; i < n; i++) {
		printf("indegree[%d]: %d\n", i, indegree[i]);
	}	
}
int main(int argc, char **argv)
{
	adjacency* a = (adjacency*) calloc(n, sizeof(adjacency));
	int* indegree = (int*) calloc(n, sizeof(int));
	queue q;
	initialize_queue(&q);
	
	a[0].u = 'A';
	a[0].next = node_maker('B');
	a[0].next->next = node_maker('D');	
	a[1].u = 'B';
	a[1].next = node_maker('C');	
	a[2].u = 'C';
	a[2].next = node_maker('D');
	a[2].next->next = node_maker('E');	
	a[3].u = 'D';
	a[3].next = node_maker('E');	
	a[4].u = 'E';
	a[4].next = NULL;	
	a[5].u = 'F';
	a[5].next = NULL;
	
	indegree_maker(indegree, a);
	topological_sort(a, &q, indegree);
	
	return 0;
}
