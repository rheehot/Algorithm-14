#include <stdio.h>
#include <string.h>
#define MAX_STACK_SIZE 10001

int top = -1;
int stack[MAX_STACK_SIZE];

void push(int item){
    if(isFull()) return; //stack 가득 찼을 때
    else
        stack[++top] = item;
}

void pop(){
    if(isEmpty())
        printf("-1\n");
    else 
        printf("%d\n", stack[top--]);
}

void size(){
    printf("%d\n", top + 1);
}

void Top(){
    if(isEmpty())
	    printf("-1\n");
	else 
	    printf("%d\n", stack[top]);
}

int isFull() {
	if (top == MAX_STACK_SIZE - 1)
	    return 1;
	else
	    return 0;
}

int isEmpty(){
	if (top == -1)
	    return 1;
	else
	    return 0;
}

