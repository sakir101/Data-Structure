#include<stdio.h>
int arr[20];
static int i=0;
 int n;
typedef struct link_list
{
    int data;
    struct link_list *next;
    struct link_list *prev;
}node;
node *head=NULL, *temp=NULL, *newnode=NULL, *temp1, *tail=NULL;
node *temp2, *temp3, *temp4;
void insert()
{
    newnode=(node *)malloc(sizeof(node));
    newnode->data=arr[i];
    newnode->next=NULL;
    newnode->prev=NULL;
    if(head==NULL)
    {
        head=newnode;
        temp=newnode;
        tail=newnode;
         i++;
        insert();

    }
    else if(i<n)
        {
            newnode->prev=temp;
            temp->next=newnode;
            temp=newnode;
            tail=newnode;
            i++;
            insert();
        }
}
void display()
{
    temp1=tail;
    while(temp1!=NULL)
        {
            printf("%d-> ",temp1->data);
            temp1=temp1->prev;
        }
}
void deletion()
{
    int x;
    printf("1.Data delete 2.Return");
    scanf("%d",&x);
    if(x==1)
    {
        int x1;
        printf("which data you want to delete?");
        scanf("%d",&x1);
        temp2=head;
        while(temp2!=NULL)
        {
            if(x1==head->data)
            {
                head=head->next;
                head->prev=NULL;
                free(temp2);
                deletion();
                return;
            }
            else if(x1==tail->data)
            {
                temp2=tail;
                tail=tail->prev;
                tail->next=NULL;
                free(temp2);
                deletion();
                return;
            }
            else if(x1==temp2->data)
            {
                temp3=temp4=temp2;
                temp4=temp4->next;
                temp3=temp3->prev;
                temp3->next=temp4;
                temp4->prev=temp3;
                free(temp2);
                deletion();
                return;
            }
            temp2=temp2->next;
        }
    }
    else if(x==2)
    {
        return;
    }
}
int main()
{
    printf("Enter size: ");
    scanf("%d",&n);
    for(int i=0; i<n; i++)
    {
        scanf("%d",&arr[i]);
    }
    insert();
    display();
    printf("\n");
    deletion();
    display();
}

