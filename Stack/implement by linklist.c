#include<stdio.h>
typedef struct link_list
{
    int data;
    struct link_list *link;
} node;
node *newnode=NULL, *top=NULL, *temp;
void push()
{
    int x;
    printf("Do you want to insert data? 1. Y 2. N");
    scanf("%d", &x);
    if(x==1)
    {
        newnode=(node *)malloc(sizeof(node));
        int x1;
        printf("Insert data: ");
        scanf("%d",&x1);
        newnode->data=x1;
        newnode->link=top;
        top=newnode;
        push();
        return;
    }
    else if(x==2)
    {
        return;
    }
}
void pop()
{
    if(top==NULL)
    {
        printf("Underflow!");
        return;
    }
    else
    {
        temp=top;
        top=top->link;
        free(temp);
        return;
    }
}
void display()
{
    temp=top;
    while(temp!=NULL)
    {
        printf("%d ->",temp->data);
        temp=temp->link;
    }
}
void peek()
{
    printf("%d",top->data);
}
int main()
{
    while(1)
    {
        int x;
        printf("Select one: 1. Push 2. Pop 3. Display 4. Peek 5. Break");
        scanf("%d",&x);
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
