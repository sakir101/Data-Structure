#include<stdio.h>
typedef struct queue
{
    int data;
    struct queue *next;
} node;
node *front=NULL, *rear=NULL, *newnode=NULL, *temp=NULL;
void enqueue()
{
    int  x, x1;
    printf("Do you want to insert: 1.Y 2.N: ");
    scanf("%d",&x);
    if(x==1)
    {
        printf("Enter data: ");
        scanf("%d",&x1);
        newnode=(node *)malloc(sizeof(node));
        newnode->data=x1;
        newnode->next=NULL;
        if(front==NULL)
        {
            front=rear=temp=newnode;
            enqueue();
            return;
        }
        else
        {
            rear->next=newnode;
            rear=newnode;
            temp=newnode;
            enqueue();
            return;
        }
    }
    else
    {
        return;
    }
}
void dequeue()
{
    int x;
    printf("Do you want to dequeue: 1.Y 2.N: ");
    scanf("%d",&x);
    if(x==1)
    {
        printf("\n Deleted Data: %d \n", front->data);
        temp=front;
        front=front->next;
        free(temp);
        dequeue();
        return;
    }
    else
    {
        return;
    }
}
void display()
{
    temp=front;
    while(temp!=NULL)
    {
        printf("%d ->",temp->data);
        temp=temp->next;
    }
}
void peek()
{
    printf("\nPeek data: %d\n",front->data);
}
int main()
{
    int x;
    while(1)
    {
        printf("Choose one: 1.Enqueue 2.Dequeue 3.Display 4.Peek 5.Break: ");
        scanf("%d",&x);
        if(x==1)
        {
            enqueue();
            printf("\n");
        }
        else if(x==2)
        {
            dequeue();
            printf("\n");
        }
        else if(x==3)
        {
            display();
            printf("\n");
        }
        else if(x==4)
        {
            peek();
            printf("\n");
        }
        else if(x==5)
        {
            break;
        }
    }
}


