#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *next, *prev;
}NODE;

//Prototypes
NODE* addFront(NODE*);
NODE* addRear(NODE*);
void disp(NODE*);
void search(NODE*);

//Driver
int main()
{
    //Create an empty DLL
    NODE *head=NULL;
    int opt;
    while(1)
    {
        printf("\n1: FrontAdd\t2: RearAdd\t3: Disp\t");
        printf("4: Search\t5: Exit");
        printf("\nEnter an option: ");
        scanf("%d", &opt);
        switch(opt)
        {
            case 1: head=addFront(head);   break;
            case 2: head=addRear(head);   break;
            case 3: disp(head);   break;
            case 4: search(head);   break;
            case 5: exit(0);
        }
    }
    return 0;
}


//Adding a node at the front of the DLL
NODE* addFront(NODE *head)
{
    int data;
    NODE *tmp=(NODE *)malloc(sizeof(NODE));
    if(tmp==NULL)
    {
        printf("\nMalloc failure");
        exit(1);
    }

    printf("\nEnter data to add: ");
    scanf("%d", &data);
    tmp->data=data;
    tmp->prev=tmp->next=NULL;

    if(head==NULL) //Empty List
        head=tmp;
    else   //List has atleast one datanode
    {
        tmp->next=head;
        head->prev=tmp;
        head=tmp;
    }

    return(head);
}

void disp(NODE *head)
{
    if(head==NULL)
    {
        printf("\nList is empty");
        return;
    }

    printf("\nThe List contents are: ");
    while(head)
    {
        printf("%d    ", head->data);
        head=head->next;
    }
}


//Adding a node at the end of the DLL
NODE* addRear(NODE *head)
{
    int data;
    NODE *trav;
    NODE *tmp=(NODE *)malloc(sizeof(NODE));
    if(tmp==NULL)
    {
        printf("\nMalloc failure");
        exit(1);
    }

    printf("\nEnter data to add: ");
    scanf("%d", &data);
    tmp->data=data;
    tmp->prev=tmp->next=NULL;

    if(head==NULL) //Empty List
        head=tmp;
    else   //List has atleast one datanode
    {
        trav=head;
        while(trav->next)
            trav=trav->next;

        trav->next=tmp;
        tmp->prev=trav;
    }

    return(head);
}


//Search data in DLL
void search(NODE *head)
{
    int item, count=0;
    if(head==NULL)
    {
        printf("\nList is empty");
        return;
    }
    printf("\nEnter data to search: ");
    scanf("%d", &item);
    while(head)
    {
        if(item==head->data)
        {
            printf("\nData %d present at position %d", item, count+1);
            return;
        }
        else
        {
            count++;
            head=head->next;
        }
    }

    printf("\nData %d not present", item);

}