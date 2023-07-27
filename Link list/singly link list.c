#include<stdio.h>
typedef struct doubly_linklist
{
    int data;
    struct doubly_linklist *next;
} node;
node *newnode=NULL, * head=NULL, *tail=NULL, *temp=NULL, *temp1;
node *newnode1, *temp2, *temp3, *temp4;
void create()
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
            create();
            return;
        }
        else
        {
            temp->next=newnode;
            temp=newnode;
            tail=newnode;
            create();
            return;
        }
    }
    else if(x==2)
    {
        temp->next=NULL;
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
void insert()
{
    int x, x1, j;
    printf("\nWhich position do you want to insert?\n ");
    printf("\n1.Begining 2.End 3.Middle");
    scanf("%d", &x);
    if(x==1)
    {
        printf("Enter data: ");
        scanf("%d", &x1);
        newnode1=(node *)malloc(sizeof(node));
        if(head->next==NULL)
        {
            newnode1->data=x1;
            tail=newnode;
            head=newnode;
            temp=newnode;
        }
        else
        {
            newnode1->data=x1;
            newnode1->next=head;
            head=newnode1;
        }
    }
    else if(x==2)
    {
        printf("Enter data: ");
        scanf("%d", &x1);
        newnode1=(node *)malloc(sizeof(node));
        if(head->next==NULL)
        {
            newnode1->data=x1;
            tail=newnode1;
            head=newnode1;
            temp=newnode1;
        }
        else
        {
            newnode1->data=x1;
            newnode1->next=NULL;
            tail->next=newnode1;
            tail=newnode1;
        }
    }
    else if(x==3)
    {
        int l=0, x1;
        temp1=head;
        while(temp1!=NULL)
        {
            l++;
            temp1=temp1->next;
        }
        printf("Enter data: ");
        scanf("%d", &x1);
        newnode1=(node *)malloc(sizeof(node));
        if(head->next==NULL)
        {
            newnode1->data=x1;
            tail=newnode1;
            head=newnode1;
            temp=newnode1;
        }
        else
        {
            int pos;
            printf("Which position?");
            scanf("%d",&pos);
            if(pos>l || pos<=1)
            {
                printf("Invalid Position!");
            }
            else
            {
                int i=1;
                temp2=head;
                while(i<(pos-1))
                {
                    i++;
                    temp2=temp2->next;
                }
                newnode1->data=x1;
                newnode1->next=temp2->next;
                temp2->next=newnode1;
            }
        }
    }
}
void deletion()
{
    int x;
    printf("Do you want to delete? 1. Y 2. N ");
    scanf("%d",&x);
    if(x==1)
    {
        if(head==NULL)
        {
            printf("No data!");
        }
        else
        {
            int x1;
            printf("Which position?\n");
            printf("1. Begining 2. End 3. Middle ");
            scanf("%d",&x1);
            if(x1==1)
            {
                temp3=head;
                head=head->next;
                free(temp3);
            }
            else if(x1==2)
            {
                temp3=head;
                int l=0, i=1;
                temp1=head;
                while(temp1!=NULL)
                {
                    l++;
                    temp1=temp1->next;
                }
                printf("%d\n",l);
                while(i<(l-1))
                {
                    i++;
                    temp3=temp3->next;
                }
                tail=temp3;
                temp3=temp3->next;
                tail->next=NULL;
                free(temp3);
            }
            else if(x1==3)
            {
                temp3=head;
                int l=0, i=1, pos;
                temp1=head;
                while(temp1!=NULL)
                {
                    l++;
                    temp1=temp1->next;
                }
                printf("Enter Position: ");
                scanf("%d",&pos);
                if(pos<=1 || pos>l)
                {
                    printf("Invalid position");
                }
                else
                {
                    while(i<(pos-1))
                    {
                        i++;
                        temp3=temp3->next;
                    }
                    temp4=temp3;
                    temp3=temp3->next;
                    temp4->next=temp3->next;
                    free(temp3);
                }
            }
        }
    }
    else
    {
        return;
    }
}
int main()
{
    create();
    while(1)
    {
        int x;
        printf("1. Insert 2. Display 3. Delete 4. Break ");
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


