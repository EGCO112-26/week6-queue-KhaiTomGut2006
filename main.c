#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Node.h"
#include "Queue.h"

int main(int argc , char **argv) {
  int i, x;
  
  Queue q;
  q.headPtr = NULL;
  q.tailPtr = NULL;
  q.size = 0;
   for(i=1; i<argc; i++){
    if(strcmp(argv[i],"x")==0){
      x = dequeue_struct(&q);
      
      if(x != -1){
        printf("dequeing %d\n", x);
      }
    }
    else {
      enqueue_struct(&q, atoi(argv[i]));
    }
  }
  return 0;
}
