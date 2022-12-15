#include "monty.h"
// A complete working program to
// demonstrate all stack operations using
// a doubly linked list
stack_t *top = NULL;

// Check if stack is empty
bool isEmpty(stack_t **start)
{
	if (*start == NULL)
		return true;
	return false;
}

// pushes element onto stack
void push(stack_t **start, int d)
{

	stack_t *n;
	n = malloc(sizeof(stack_t));
	n->n = d;
	if (isEmpty(start)) {
		n->prev = NULL;
		n->next = NULL;

		// As it is first node if stack
		// is empty
		*start = n;
		top = n;
	}
	else {
		top->next = n;
		n->next = NULL;
		n->prev = top;
		top = n;
	}
}

// Pops top element from stack
void pop(stack_t **start)
{
	stack_t* n;
	n = top;
	if (isEmpty(start))
		printf("Stack is empty");
	else if (top == *start) {
		top = NULL;
		*start = NULL;
		free(n);
	}
	else {
		top->prev->next = NULL;
		top = n->prev;
		free(n);
	}
}

// Prints top element of the stack
void topelement(stack_t **start)
{
	if (isEmpty(start))
		printf("Stack is empty");
	else
		printf(
			"The element at top of the stack is : %d \n",
			top->n);
}

// Determines the size of the stack
void stacksize(stack_t **start)
{
	int c = 0;
	if (isEmpty(start))
		printf("Stack is empty");
	else {
		stack_t* ptr = *start;
		while (ptr != NULL) {
			c++;
			ptr = ptr->next;
		}
	}
	printf("Size of the stack is : %d \n ", c);
}

// Determines the size of the stack
void printstack(stack_t **start)
{
	if (isEmpty(start))
		printf("Stack is empty");
	else {
		stack_t* ptr = *start;
		printf("Stack is : ");
		while (ptr != NULL) {
			printf("%d ", ptr->n);
			ptr = ptr->next;
		}
		printf("\n");
	}
}
/*
// Driver code
int main()
{
	stack_t *start = NULL;
	push(&start,2);
	push(&start,5);
	push(&start,12);
	printstack(&start);
	topelement(&start);
	stacksize(&start);
	pop(&start);
	printf("\nElement popped from the stack \n");
	topelement(&start);
	pop(&start);
	printf("\nElement popped from the stack \n");
	stacksize(&start);
	return 0;
}
*/

