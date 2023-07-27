#include<stdio.h>
int top1=-1, top2=-1, n, i=0;
int stack1[20], stack2[20];
void enqueue()
{
    int  x, x1;
    printf("Do you want to insert: 1.Y 2.N");
    scanf("%d",&x);
    if(x==1)
    {
        if(i>(n-1))
        {
            printf("Queue is overflowed");
        }
        else
        {
            i++;
            printf("Enter value: ");
            scanf("%d",&x1);
            push1(x1);
            enqueue();
            return;
        }
    }
    else
    {
        return;
    }
}
void push1(int value)
{
    top1++;
    stack1[top1]=value;
}
void dequeue()
{
    int x;
    printf("Do you want to dequeue: 1.Y 2.N");
    scanf("%d",&x);
    if(x==1)
    {
        if(i==0)
        {
            printf("Underflow");
        }
        else
        {
            i--;
            pop1();
            dequeue();
            return;
        }
    }
}
void pop1()
{
    push2();
    return;
}
void push2()
{
    int temp1=top1;
    while(temp1!=-1)
    {
        top2++;
        stack2[top2]=stack1[temp1];
        temp1--;
    }
    pop2();
    return;
}
void pop2()
{
    int data;
    printf("\n Data deleted: %d\n",stack2[top2]);
    data=stack2[top2];
    top2--;
    push3();
    return;
}
void push3()
{
    int temp2=-1;
    while(top2!=-1)
    {
        temp2++;
        stack1[temp2]=stack2[top2];
        top2--;
    }
    top1=temp2;
    return;
}
void display()
{
    int temp=top1;
    while(temp!=-1)
    {
        printf("%d ",stack1[temp]);
        temp--;
    }
}
void peek()
{
    printf("%d",stack1[top1]);
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
