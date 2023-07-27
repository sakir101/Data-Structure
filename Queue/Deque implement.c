#include<stdio.h>
int n, front=-1, rear=-1;
int deque[20];
void enqueuefront()
{
    int x, x1;
    printf("Want to enqueue: 1.Y 2.N: ");
    scanf("%d",&x);
    if(x==1)
    {
        if(front==-1)
        {
            front=rear=0;
            printf("Enter data: ");
            scanf("%d",&x1);
            deque[front]=x1;
            enqueuefront();
            return;
        }
        else if((front-1)==rear || rear==(n-1))
        {
            printf("\n Overflow \n");
            return;
        }
        else if(front==0)
        {
            front=n-1;
            printf("Enter data: ");
            scanf("%d",&x1);
            deque[front]=x1;
            enqueuefront();
            return;
        }
        else
        {
            front--;
            printf("Enter data: ");
            scanf("%d",&x1);
            deque[front]=x1;
            enqueuefront();
            return;
        }
    }
    else
    {
        return;
    }
}
void enqueuerear()
{
    int x, x1;
    printf("Want to enqueue: 1.Y 2.N: ");
    scanf("%d",&x);
    if(x==1)
    {
        if(rear==-1)
        {
            front=rear=0;
            printf("Enter data: ");
            scanf("%d",&x1);
            deque[rear]=x1;
            enqueuerear();
            return;
        }
        else if((rear+1)==front || ((rear+1)%n)==front)
        {
            printf("\n Overflow \n");
            return;
        }
        else if(rear==(n-1))
        {
            rear=(rear+1)%n;
            printf("Enter data: ");
            scanf("%d",&x1);
            deque[rear]=x1;
            enqueuerear();
            return;
        }
        else
        {
            rear++;
            printf("Enter data: ");
            scanf("%d",&x1);
            deque[rear]=x1;
            enqueuerear();
            return;
        }
    }
}
void dequeuefront()
{
    int x, x1;
    printf("Want to dequeue: 1.Y 2.N: ");
    scanf("%d",&x);
    if(x==1)
    {
        if(front==-1)
        {
            printf("\n Underflow \n");
            return;
        }
        else if(front==rear)
        {
            x1=deque[front];
            printf("\n Deleted data: %d \n",x1);
            front=rear=-1;
            return;
        }
        else if(front==(n-1))
        {
            x1=deque[front];
            printf("\n Deleted data: %d \n",x1);
            front=(front+1)%n;
            dequeuefront();
            return;
        }
        else
        {
            x1=deque[front];
            printf("\n Deleted data: %d \n",x1);
            front++;
            dequeuefront();
            return;
        }
    }
}
void dequeuerear()
{
    int x, x1;
    printf("Want to dequeue: 1.Y 2.N: ");
    scanf("%d",&x);
    if(x==1)
    {
        if(rear==-1)
        {
            printf("\n Underflow \n");
            return;
        }
        else if(rear==front)
        {
            x1=deque[rear];
            printf("\n Deleted data: %d \n",x1);
            front=rear=-1;
            return;
        }
        else if(rear==0)
        {
            x1=deque[rear];
            printf("\n Deleted data: %d \n",x1);
            rear=n-1;
            dequeuerear();
            return;
        }
        else
        {
            x1=deque[rear];
            printf("\n Deleted data: %d \n",x1);
            rear--;
            dequeuerear();
            return;
        }
    }
}
void display()
{
    int temp=front;
    if(front==-1)
    {
        printf("\n Deque is empty \n");
    }
    else
    {
        while(temp!=rear)
        {
           if(temp==(n-1))
           {
               printf("%d ",deque[temp]);
               temp=(temp+1)%n;
           }
           else
           {
               printf("%d ",deque[temp]);
               temp++;
           }
        }
        printf("%d ",deque[temp]);
    }
}
int main()
{
    int x;
    printf("Enter queue size: ");
    scanf("%d",&n);
    while(1)
    {
        printf("Choose one: 1.Enqueue front 2. Enqueue rear 3. Dequeue front 4. Dequeue rear 5.Display: ");
        scanf("%d",&x);
        if(x==1)
        {
            enqueuefront();
            printf("\n");
        }
        else if(x==2)
        {
            enqueuerear();
            printf("\n");
        }
        else if(x==3)
        {
            dequeuefront();
            printf("\n");
        }
        else if(x==4)
        {
            dequeuerear();
            printf("\n");
        }
        else if(x==5)
        {
            display();
            printf("\n");
        }
        else
        {
            break;
        }
    }
}
