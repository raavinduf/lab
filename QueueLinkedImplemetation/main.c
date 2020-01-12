#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int data;
    struct node *next;
}Node;

typedef struct queue{
    int count;
    Node *front;
    Node *rear;
}Q;

void createQueue(Q *q){
    q->count=0;
    q->front=NULL;
    q->rear=NULL;
}


int isQueueEmpty(Q *q){
    if(q->count==0)
        return 1;
    return 0;
}

void enqueue(Q *q,int k){
    Node *np;
    np=(Node*)malloc(sizeof(Node));
    np->data=k;
    if(isQueueEmpty(q)){
        q->front=np;
        q->rear=np;
    }
    else{
        q->rear->next=np;
        q->rear=np;
    }
    q->count++;
}

void traverse(Q *q){
    Node *np;
    np=(Node*)malloc(sizeof(Node));
    np=q->front;
    int i;
    printf("\n");
    for (i=0;i<q->count;i++){
        printf("%d\t",np->data);
        np=np->next;
    }
    free(np);
}

int dequeue(Q *q){
    Node *np;
    if(isQueueEmpty(q)){
        return 0;
    }
    np=q->front;
    q->front=q->front->next;
    free(np);
    q->count--;
    return 0;
}

int bubbleSort(Q *q){
    Node *np1,*np2;
    np1=(Node*)malloc(sizeof(Node));
    np2=(Node*)malloc(sizeof(Node));
    int i,j;
    np1=q->front;
    np2=q->front;
    //printf("Hello");
    int swap;
    for (i=0;i<q->count-1;i++){
            np1=np1->next;
        for(j=0;j<q->count-i-1;j++){
            if(np2->data>np1->data){
                swap=np2->data;
                np2->data=np1->data;
                np1->data=swap;
               // printf("\n%d",swap);
            }
            np1=np1->next;
            np2=np2->next;
        }
        np1=q->front;
        np2=q->front;

    }
    return 0;
}

int main()
{
    Q q;
    createQueue(&q);
    enqueue(&q,5);
    enqueue(&q,8);
    enqueue(&q,3);
    traverse(&q);
    //traverse(&q);

    enqueue(&q,9);
    enqueue(&q,2);
    enqueue(&q,8);
    traverse(&q);
    //dequeue(&q);
    //traverse(&q);
    bubbleSort(&q);
    traverse(&q);

}
