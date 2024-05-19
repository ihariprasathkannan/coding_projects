#include<stdio.h>
#include<stdlib.h>
#define QUEUE_SIZE 30

struct node{
	int val;
	struct node* next;
};

struct node* front = NULL;
struct node* rear = NULL;
int size;

int enqueue(int val){
	struct node* newNode = (struct node*)malloc(sizeof(struct node));
	newNode->val = val;
	if(size >= QUEUE_SIZE){
		printf("SIZE EXCEEDED\n");
		return -1;
	}
	if(front == NULL && rear == NULL){
		front = rear = newNode;
		size++;
		return 0;
	}
	rear->next = newNode;
	rear = newNode;
	size++;
	return 0;
}

int dequeue(){
	if(front == NULL){
		printf("QUEUE EMPTY\n");
		return -1;
	}
	struct temp = front;
	front = front->next;
	free(temp);
	size--;
	return 0;
}

int isFull(){
	if(size >= QUEUE_SIZE)
		return 1;
	else
		return 0;
}

int isEmpty(){
	if(size == 0)
		return 1;
	else
		return 0;
}
