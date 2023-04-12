#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define MAX 5
int f=0,r=-1;
struct queue{
    int id;
    char msg[20];
}q[MAX];
void insert()
{
    int x;
    char txt[20];
    if(r==MAX-1){
        printf("Queue is full");
        return;
    }
    printf("Enter the id and message:");
    scanf("%d",&x);
    gets(txt);
    r++;
    q[r].id=x;
    strcpy(q[r].msg,txt);
    printf("Message is inserted\n");
}
void delete()
{
    if(f>r)
    {
        printf("Queue is empty\n");
        f=0,r=MAX-1;
        return;
    }
    printf("%d is deleted\n",q[f++].id);
}
void display(){
    int i;
    if(f>r){
        printf("Queue is empty");
        return;
    }
    for(i=f;i<=r;i++){
        printf("%d\t %s\n",q[i].id,q[i].msg);
    }
}
int main()
{
    int c;
    printf("Enter\n1.Insert\n2.Delete\n3.Display\n4.Exit\n");
    while (1)
    {
        printf("Enter your choice:");
        scanf("%d",&c);
        switch (c)
        {
        case 1:insert();
            break;
        case 2:delete();
            break;
        case 3:display();
                break;
        case 4:exit(0);
        default:printf("invalid choice\n");
        }
    }
    
}