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
        if(rear==(n-1))
        {
            printf("Overflow");
        }
        else if(front==-1)
        {
            front=rear=0;
            printf("Enter data: ");
            scanf("%d",&x1);
            array[rear]=x1;
            enqueue();
            return;
        }
        else
        {
            rear++;
            printf("Enter data: ");
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
     int x, data;
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
            data=array[front];
            printf("\n Deleted data: %d\n",data);
            front=rear=-1;
            dequeue;
            return;
        }
        else
        {
            data=array[front];
            printf("\n Deleted data: %d \n",data);
            front++;
            dequeue();
            return;
        }
    }
}
void display()
{
    int temp=front;
    while(temp<=rear)
    {
        printf("%d ",array[temp]);
        temp++;
    }
}
void peek()
{
    printf("Peek: %d",array[front]);
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
