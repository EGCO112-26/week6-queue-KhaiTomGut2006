#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node {
    struct node* next;
    int order_number;
    int q;
} order;

typedef struct Queue {
    order *head, *tail;
    int size;
} Queue;

void enqueue(Queue *q, int ord, int qty) {
    order *new_node = (order*)malloc(sizeof(order));
    new_node->order_number = ord;
    new_node->q = qty;
    new_node->next = NULL;

    if (q->head == NULL) {
        q->head = new_node;
        q->tail = new_node;
    } else {
        q->tail->next = new_node;
        q->tail = new_node;
    }
    q->size++;
    printf("My order is %d\n", ord);
}

order* dequeue(Queue *q) {
    if (q->head == NULL) return NULL;
    
    order *temp = q->head;
    q->head = q->head->next;
    if (q->head == NULL) {
        q->tail = NULL;
    }
    q->size--;
    return temp;
}

void clearQueue(Queue *q) {
    printf("There are %d ppl left in the queue\n", q->size);
    while (q->head != NULL) {
        order *temp = q->head;
        q->head = q->head->next;
        free(temp);
    }
    q->size = 0;
}

int main(int argc, char *argv[]) {
    Queue q;
    q.head = NULL;
    q.tail = NULL;
    q.size = 0;

    int i;
    for (i = 1; i < argc; i += 2) {
        if (i + 1 < argc) {
            int ord = atoi(argv[i]);
            int qty = atoi(argv[i+1]);
            if(ord > 0) {
                enqueue(&q, ord, qty);
            }
        }
    }

    int customer_no = 1;
    while (q.head != NULL) {
        order *current = dequeue(&q);
        
        int price_per_unit = 0;
        char menu_name[50];
        
        switch (current->order_number) {
            case 1:
                price_per_unit = 100;
                strcpy(menu_name, "Ramen");
                break;
            case 2:
                price_per_unit = 20;
                strcpy(menu_name, "Som Tum");
                break;
            case 3:
                price_per_unit = 50;
                strcpy(menu_name, "Fried Chicken");
                break;
            default:
                free(current);
                continue;
        }

        int total_price = price_per_unit * current->q;

        printf("Customer no: %d\n", customer_no++);
        printf("%s\n", menu_name);
        printf("You have to pay %d\n", total_price);

        int cash_paid = 0;
        while (1) {
            int cash_in;
            printf(":Cash:");
            scanf("%d", &cash_in);
            cash_paid += cash_in;
            
            if (cash_paid >= total_price) {
                printf("Thank you\n");
                if (cash_paid > total_price) {
                    printf("Change is:%d\n", cash_paid - total_price);
                }
                break;
            } else {
                printf("Cash:%d\n", cash_paid); 
            }
        }
        printf("============================================\n");
        free(current);
    }

    clearQueue(&q);

    return 0;
}