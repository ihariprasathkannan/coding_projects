#include<stdio.h>
#include<stdlib.h>

struct stack {
	int top;
	unsigned int capacity;
	int* data_arr;
};


int isFull(struct stack* stk) {
	if(stk->top >= stk->capacity - 1)
		return 1;
	else
		return 0;
}

int push(struct stack* stk){
	if(stk->top != -1 && stk->top >= stk->capacity - 1) {
		printf("ERROR: STACK OVERFLOW, couldn't push data capacity:%u top:%d\n", stk->capacity, stk->top);
		return -1;
	}
	int data;
	printf("Enter data to push: \t");
	scanf("%d", &data);
	stk->data_arr[++ stk->top] = data;
	return 0;
}

int pop(struct stack *stk){
	if(stk->top == -1) {
		printf("ERROR: STACK UNDERFLOW, couldn't pop data \n");
		return -1;
	}
	stk->data_arr[stk->top] = 0;
	stk->top--;
	return 0;
}

int isEmpty(struct stack *stk){
	if(stk->top == -1)
		return 1;
	else
		return 0;
}

struct stack* createStack(int capacity){
	struct stack* stk = (struct stack*)malloc(1*sizeof(struct stack));
	if(!stk){
		printf("ERROR STACK ALLOCATION FAILED\n");
		return NULL;
	}
	stk->top = -1;
	stk->capacity = capacity;
	stk->data_arr = (int*)malloc(capacity*sizeof(int));
	if(stk->data_arr == NULL){
		printf("ERROR STACK ARRAY ALLOCATION FAILED\n");
		free(stk);
		return NULL;
	}
	printf("STACK CREATION of size %u is success\n",stk->capacity);
	return stk;
}

void deleteStack(struct stack* stk){
	free(stk->data_arr);
	free(stk);
	return 0;
}

void peek(struct stack* stk) {
	if(stk->top == -1){
		printf("ERROR STACK is EMPTY\n");
		return;
	}

	printf("ELEMENT at top %d is: %d \n", stk->top, stk->data_arr[stk->top]);
	return;
}

int main(){
	int operation=0, exit=0, capacity = 0;
	struct stack *stk = NULL;
	while(!exit){
		printf("ENTER OPERATIONS TO PERFORM \n ENTER 1 to createStack\n ENTER 2 to deleteStack \n ENTER 3 to push\n");
		printf(" ENTER 4 to pop\n ENTER 5 to peek\n ENTER 6 to check is full\n ENTER 7 to check is empty\n ENTER 8 to exit\n");
		scanf("%d", &operation);
		switch(operation){
			case 1:
				if(stk != NULL){
					printf("STACK exists\n");
					break;
				}
				printf("Enter capactiry:\t");
				scanf("%d", &capacity);
				stk = createStack(capacity);
				if(stk)
					printf("Stack creation successful\n");
				break;
			case 2:
				if(stk == NULL){
                                        printf("Create stack first\n");
                                        break;
                                }
				deleteStack(stk);
				printf("Delete Success\n");
				break;
			case 3:
				if(stk == NULL){
					printf("Create stack first\n");
					break;
				}
				if(push(stk) == 0)
					printf("PUSH success\n");
				else
					printf("PUSH FAILED\n");
				break;
			case 4:
				if(stk == NULL){
                                        printf("Create stack first\n");
                                        break;
                                }
				if(pop(stk) == 0)
					printf("POP Success\n");
				else
					printf("POP Failed\n");
				break;
			case 5:
				if(stk == NULL){
                                        printf("Create stack first\n");
                                        break;
                                }
				peek(stk);
				break;
			case 6:
				if(stk == NULL){
                                        printf("Create stack first\n");
                                        break;
                                }
				if(isFull(stk) == 1)
					printf("STACK is full\n");
				else
					printf("STACK is not full\n");
				break;
			case 7:
				if(stk == NULL){
                                        printf("Create stack first\n");
                                        break;
                                }
				if(isEmpty(stk) == 1)
					printf("STACK is EMPTY\n");
				else
					printf("STACK is not empty\n");
				break;
			case 8:
				exit = 1;
				break;
			default:
				exit = 1;
				break;
		}
	}
}



