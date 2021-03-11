#include <stdio.h>
#include <stdlib.h>

struct stack {
	int element;
	struct stack *next;
};

int infinity = 99999999;

void MAKENULL(struct stack **s){
	*s = (struct stack *)malloc(sizeof(struct stack));
	(*s) -> next = NULL;
}

int EMPTY(struct stack **s){
	if ((*s) -> next == NULL){return 1;}
	else {return 0;}
}

int TOP(struct stack **s){
	if (EMPTY(s)) {
		printf("stack is empty");
		return infinity;
	}
	else {
		return ((*s) -> next);
	}
}

int POP(struct stack **s){
	int temp; struct stack *ptr;
	if (EMPTY(s)){
		printf("stack is empty");
		return infinity;
	}
	else{
		temp = (*s) -> element;
		ptr = *s;
		*s = (*s) -> next;
		free(ptr);
		return temp;
	}
}

void PUSH(int x, struct stack **s){
	struct stack *ptr;
	ptr = (struct stack *)malloc(sizeof(struct stack));
	ptr -> next = *s;
	ptr -> element = x;
	*s = ptr;
}

int main(){
	struct stack *s; int i,x;
	MAKENULL(&s);
	for (i=0;i<10;i++){
		PUSH(i,&s);
		printf("%5d \n",i);
	}
	while (!EMPTY(&s)){
		printf("%5d \n", POP(&s));
	}
}