#include "queue_pair.h"
#include <stdlib.h>

Pair make_pair(int first, int second) {
	Pair pair;
	pair.first = first;
	pair.second = second;
	return pair;
}

void push(Pair pair, Queue* queue) {
	if (queue->size == MAX_QUEUE_SIZE) {
		return;
	}
	queue->pair[queue->size] = pair;
	queue->size += 1;
}

void pop(Queue* queue) {
	if (queue->size == 0) {
		return;
	}
	queue->pair[0] = make_pair(0, 0);
	int i;
	for (i = 1; i < queue->size; i++) {
		queue->pair[i - 1] = queue->pair[i];
	}
	queue->size -= 1;
}

Pair front(Queue* queue) {
	if (queue->size == 0) {
		return make_pair(0, 0);
	}
	return queue->pair[0];
}

int empty(Queue* queue) {
	return queue->size == 0 ? 1 : 0;
}

Queue* new_queue_pair() {
	Queue* queue = (Queue*)malloc(sizeof(Queue));
	queue->pair = (Pair*)malloc(sizeof(Pair) * MAX_QUEUE_SIZE);
	queue->size = 0;

	queue->push = push;
	queue->pop = pop;
	queue->front = front;
	queue->empty = empty;

	return queue;
}

void destroy_queue_pair(Queue* queue) {
	free(queue->pair);
	free(queue);
}
