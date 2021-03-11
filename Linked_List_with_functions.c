#include<stdlib.h>
#include<stdio.h>

struct Node { int element; struct Node *next;};

void add_element(struct Node **, int);
void print_linked_list(struct Node **);
void delete_element(struct Node **, int);

int main(){
	struct Node *header=NULL, *ptr, *prev;
	int i,n,x,found;
	printf("enter the no. of elements :\n");
	scanf("%d",&n);
	for (i=0;i<n;i++){
		printf("enter the element : \n");
		scanf("%d", &x);
		add_element(&header, x);
	}
	print_linked_list(&header);
	printf("Enter the element to be deleted: \n");
	scanf("%d", &x);
	delete_element(&header, x);
	print_linked_list(&header);
}

void add_element(struct Node **h, int x){
	struct Node *ptr;
	ptr = (struct Node *)malloc(sizeof(struct Node));
	ptr -> element = x;
	ptr -> next = *h;
	*h = ptr;
}

void print_linked_list(struct Node **h){
	struct Node *ptr = *h;
	while(ptr!=NULL){
		printf("%5d", ptr-> element);
		ptr = ptr -> next;
	}
}

void delete_element(struct Node **h, int x){
	struct Node *ptr,*prev;
	ptr = *h; prev = *h;
	while(ptr!=NULL){
		if (ptr->element == x){
			if (ptr == *h){
				*h = ptr -> next;
				free(ptr);
				ptr = *h;
				prev = *h;
			}
			else {
				prev-> next = ptr-> next;
				free(ptr);
				ptr = ptr -> next;
			}
		}
		prev = ptr;
		ptr = ptr -> next;
	}
}

