#include<stdio.h>
int front=-1, rear=-1, n;
int array[20];
void enqueue()
{
    int  x, x1;
    printf("Do you want to insert: 1.Y 2.N: ");
    scanf("%d",&x);
    if(x==1)
    {
        if(((rear+1)%n)==front)
        {
            printf("Overflow");
        }
        else if(front==-1)
        {
            front=0;
            rear=(rear+1)%n;
            printf("Insert value: ");
            scanf("%d",&x1);
            array[rear]=x1;
            enqueue();
            return;
        }
        else
        {
            rear=(rear+1)%n;
            printf("Insert value: ");
            scanf("%d",&x1);
            array[rear]=x1;
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
        if(front==-1)
        {
            printf("Underflow");
        }
        else if(front==rear)
        {
            printf("\nDeleted value: %d\n",array[front]);
            front=rear=-1;
            printf("Underflow");
        }
        else
        {
            int value=array[front];
            printf("\n Deleted value: %d\n",value);
            front=(front+1)%n;
            dequeue();
            return;
        }
    }
}
void display()
{
    int temp=front;
    while(temp!=rear)
    {
        printf("%d ",array[temp]);
        temp=(temp+1)%n;
    }
    printf("%d ",array[temp]);
}
void peek()
{
    printf("%d",array[front]);
}
int main()
{
    int x;
    printf("Enter queue size: ");
    scanf("%d",&n);
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

