#include<stdio.h>
int n;
int top=-1, temp;
int stack[20];
void push()
{
    int x;
    printf("Do you want to insert data? 1. Y 2. N");
    scanf("%d",&x);
    if(x==1)
    {
        if(top>=(n-1))
        {
            printf("Overflowed!");
            return;
        }
        else if(top<(n-1))
        {
            top++;
            int x1;
            printf("Enter data: ");
            scanf("%d",&x1);
            stack[top]=x1;
            push();
            return;
        }
    }
    else
    {
        return;
    }
}
void pop()
{
    if(top==-1)
    {
        printf("Underflow!");
    }
    else
    {
        temp=stack[top];
        top--;
    }
}
void display()
{
    for(int i=top;i>=0; i--)
    {
        printf("%d\n",stack[i]);
    }
}
void peek()
{
    printf("Peek =%d",stack[top]);
}
int main()
{
    printf("Enter stack size: ");
    scanf("%d",&n);
    while(1)
    {
        int x;
        printf("Select one: 1. Push 2. Pop 3. Display 4. Peek 5. Break");
        scanf("%d", &x);
        if(x==1)
        {
            push();
            printf("\n");
        }
        else if(x==2)
        {
            pop();
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
        else
        {
            break;
        }
    }
}
