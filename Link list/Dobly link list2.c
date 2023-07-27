#include<stdio.h>
typedef struct doubly_linklist
{
    int data;
    struct doubly_linklist *next, *previous;
} node;
node *newnode=NULL, * head=NULL, *tail=NULL, *temp=NULL, *temp1;
node *temp2, *temp3, *temp4;
void insert()
{
    int x;
    printf("Want to insert data 1.YES 2.NO ");
    scanf("%d",&x);
    if(x==1)
    {
        int x1;
         printf("Insert Data: ");
        scanf("%d",&x1);
        newnode=(node *)malloc(sizeof(node));
        newnode->data=x1;
        newnode->next=NULL;
        if(head==NULL)
        {
            head=newnode;
            temp=newnode;
            tail=newnode;
            insert();
            return;
        }
        else
        {
            newnode->previous=temp;
            temp->next=newnode;
            temp=newnode;
            tail=newnode;
             insert();
            return;
        }
    }
    else if(x==2)
    {
        return;
    }

}
void display()
{
    temp1=head;
    while(temp1!=NULL)
    {
        printf("%d ->",temp1->data);
        temp1=temp1->next;
    }
}
void deletion()
{
    int x;
    printf("Do you want to delete? 1. y 2. n ");
    scanf("%d",&x);
    if(x==1)
    {
        int x1;
        printf("Enter a data: ");
        scanf("%d", &x1);
        temp2=head;
       for(temp2=head;temp2!=NULL;temp2=temp2->next)
       {
           if(x1==head->data)
           {
               head=head->next;
               head->previous=NULL;
               free(temp2);
               deletion();
               return;
           }
           else if(x1==tail->data)
           {
               temp2=tail;
               tail=tail->previous;
               tail->next=NULL;
               free(temp2);
               deletion();
               return;
           }
           else if(x1==temp2->data)
           {
               temp3=temp4=temp2;
               temp4=temp4->next;
               temp3=temp3->previous;
               temp3->next=temp4;
               temp4->previous=temp3;
               free(temp2);
               deletion();
               return;
           }
       }
        printf("\nData not found\n");
               deletion();
               return;
    }
    else if(x==2)
    {
        return;
    }
}

int main()
{
    insert();
    while(1)
    {
        int x;
        printf("1. Insert 2. Display 3. Deletion 4. Break ");
        scanf("%d",&x);
        if(x==1)
        {
             insert();
        }
        else if(x==2)
        {
             display();
             printf("\n");
        }
        else if(x==3)
        {
             deletion();
             printf("\n");
        }
        else if(x==4)
        {
            break;
        }
    }
}
