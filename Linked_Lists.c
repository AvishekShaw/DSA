#include<stdlib.h>
#include <stdio.h>

struct Node{ int element; struct Node *next;};

int main(){
	struct Node *header=NULL, *ptr; 
	
	// create linked list
	int i,n;
	printf("input no. of elements :\n");
	scanf("%d",&n);
	for (i=0;i<n;i++){
		ptr = (struct Node *)malloc(sizeof(struct Node));
		ptr-> next = header; header=ptr;
		printf("input the next element: \n");
		scanf("%d", &(ptr->element));
	}

	// print linked list
	printf("The elements in the list are: \n");
	for (ptr = header; ptr!=NULL; ptr=ptr->next){
		printf("%5d", ptr -> element );
	}
	printf("\n");

	// search linked list
	int x;
	printf("Enter the element to be found: \n");
	scanf("%d", &x);
	int found =0;
	for (ptr=header; ptr!=NULL; ptr = ptr->next){
		if (ptr->element==x){ found =1; break;}
	}
	if (found) {printf("%5d found \n", x);}
	else {printf("%5d not found \n", x);}

	// deletion in linked list
	struct Node *prev;
	printf("The element to be deleted : \n");
	scanf("%d",&x);
	prev = header; ptr = header;
	if (ptr -> element ==x){
		if (ptr == header){
			header = ptr -> next;
			free(ptr);
			ptr = header; prev = header;
		}
		else {
			prev->next = ptr->next;
			free(ptr); ptr = ptr-> next;
		}
	}
	else {
		prev = ptr;
		ptr = ptr -> next;
	}

	// print linked list
	printf("The elements in the list are: \n");
	for (ptr = header; ptr!=NULL; ptr=ptr->next){
		printf("%5d", ptr -> element );
	}
	printf("\n");
}