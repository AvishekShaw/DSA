struct Qnode {int element; struct Qnode *next;};
struct Q {struct Qnode *front, *rear};

void MAKENULL (struct Q *queue){
	queue -> front = NULL;
	queue -> rear = NULL;
}

int empty (struct Q *queue){
	if (queue -> front == NULL) return 1;
	else return 0;
}

void enqueue (struct Q *queue, int x){
	struct Qnode *node;
	node = (struct Qnode *)malloc(sizeof(struct Qnode));
	node -> element = x;
	node -> next = NULL;

	if (queue->front == NULL){
		queue -> rear = node;
		queue -> front = node;
	}
	else{
		(queue->rear)->next = node;
		queue -> rear = node;
	}
}