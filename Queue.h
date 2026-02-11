typedef struct {
	 NodePtr headPtr,tailPtr;
	int size;
}Queue;


void enqueue_struct(Queue* q, int x){
  Node *new_node=(Node*) malloc(sizeof(Node));
if(new_node){ 
  new_node->data = x;
  new_node->nextPtr = NULL;
  
  if(q->tailPtr == NULL) {
      // Queue is empty
      q->headPtr = new_node;
      q->tailPtr = new_node;
  } else {
      // Add to the end of queue
      q->tailPtr->nextPtr = new_node;
      q->tailPtr = new_node;
  }
  q->size++;
 }
}


int dequeue_struct(Queue *q){
   NodePtr t=q->headPtr;
   if(t){
   int value= t->data;
   q->headPtr = t->nextPtr;
   
   if(q->headPtr == NULL) {
       q->tailPtr = NULL;
   }
   
   q->size--;
   free(t);
   return value;
   }
   printf("Empty queue\n");
   return -1;
}

