#ifndef __QUEUE_PAIR_H__
#define __QUEUE_PAIR_H__

#define MAX_QUEUE_SIZE 100 * 100

typedef struct _Pair {
	int first;
	int second;
} Pair;

typedef struct _Queue {
	Pair* pair;
	int size;
	void (*push)();
	void (*pop)();
	Pair (*front)();
	int (*empty)();
} Queue;

Pair make_pair(int first, int second);

void push(Pair pair, Queue* queue);
void pop(Queue* queue);
Pair front(Queue* queue);
int empty(Queue* queue);

Queue* new_queue_pair();
void destroy_queue_pair(Queue* queue);

#endif
