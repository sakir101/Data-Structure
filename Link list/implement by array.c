#include<stdio.h>
int arr[20];
static int i=0;
 int n;
typedef struct link_list
{
    int data;
    struct link_list *next;
}node;
node *head=NULL, *temp=NULL, *newnode=NULL, *temp1;
void insert()
{
    newnode=(node *)malloc(sizeof(node));
    newnode->data=arr[i];
    newnode->next=NULL;
    if(head==NULL)
    {
        head=newnode;
        temp=newnode;
         i++;
        insert();

    }
    else if(i<n)
        {

            temp->next=newnode;
            temp=newnode;
            i++;
            insert();

        }


}
void display()
{
    temp1=head;
    while(temp1!=NULL)
        {
            printf("%d-> ",temp1->data);
            temp1=temp1->next;
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
}
