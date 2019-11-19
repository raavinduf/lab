#include <stdio.h>
#include <stdlib.h>
#define MAXLIST 10
#define TRUE 1
#define FALSE 0

typedef struct list{
    int count;
    int data[MAXLIST];
}L;

void createList(L *li){
    li->count=0;
}

int isListEmpty(L *li){
    if(li->count==0)
        return TRUE;
    return FALSE;
}

int isListFull(L *li){
    if(li->count==MAXLIST)
        return TRUE;
    return FALSE;
}

int insert(int k,int p,L *li){
    int i;
    if(isListFull(li)){
        printf("\nList is full");
        return 0;
    }

    if(li->count==0){
        li->data[p-1]=k;
        printf("\nInsertion complete");
        return 0;
    }
    for (i=li->count-1;i>=p-1;i--){
        li->data[i+1]=li->data[i];
    }

    li->data[p-1]=k;
    li->count++;
    printf("\nInsertion complete");
    return 0;
}


int Delete(int p,L *li){
    int i;
    if(isListEmpty(li)){
        printf("\nList is empty");
        return 0;
    }
    printf("\nDeleted element is %d ",li->data[p-1]);
    if(li->count==MAXLIST){
        li->count--;
        return 0;
    }

    for(i=p-1;i<MAXLIST;i++){
        li->data[i]=li->data[i+1];
    }
    li->count--;
    return 0;
}

int retrieve(L li){
    int i;
    if(isListEmpty(&li)){
        printf("\nList is empty");
        return 0;
    }
    printf("\nElements in the list are:");
    for(i=0;i<li.count;i++)
        printf("%d\t",li.data[i]);

    return 0;
}


int main()
{
    L li;
    int k,p,n,choice;;
    createList(&li);
    printf("\n1) Insert Element");
    printf("\n2) Delete Element");
    printf("\n3) Display");
    printf("\n4) Exit");

    n=1;
    while(n){
        printf("\nSelect your choice:");
        scanf("%d",&choice);
        switch(choice){
            case 1: printf("\nEnter the element and the position respectively\n");
                    scanf("%d%d",&k,&p);
                    insert(k,p,&li);
                    break;
            case 2: printf("\nEnter the position of the element you want to delete");
                    scanf("%d",&p);
                    Delete(p,&li);
                    break;
            case 3: retrieve(li);
                    break;
            case 4: n=0;
                    break;
            default: printf("\nInvalid input");
                     break;
        }
    }

    return 0;
}
