#include<stdio.h>
typedef struct binary_tree
{
    int data;
    struct binary_tree *left, *right;
} node;
node *newnode=NULL,  *route=NULL, *temp1;
node *insert(node *newnode)
{
    node *temp;
    int x, x1;
    printf("Do you want to insert 1. Y 2. N: ");
    scanf("%d",&x);
    if(x==1)
    {
        printf("Enter data: ");
        scanf("%d",&x1);
        newnode=(node *)malloc(sizeof(node));
        newnode->data=x1;
        newnode->left=NULL;
        newnode->right=NULL;
        if(route==NULL)
        {
            route=temp=newnode;
            printf("Enter left data: %d\n",newnode->data);
            temp->left=insert(newnode);
            printf("Enter right data: %d\n",newnode->data);
            temp->right=insert(newnode);
            return newnode;
        }
        else
        {
            printf("Enter left data: %d\n",newnode->data);
            temp=newnode;
            temp->left=insert(newnode);
            printf("Enter right data: %d\n",newnode->data);
            temp->right=insert(newnode);
            return newnode;
        }
    }
    else
    {
        return NULL;
    }
}
node *display(node *temp1)
{

    if(route==NULL)
    {
        printf("Empty\n");
    }
    else if(temp1!=NULL)
    {
        display(temp1->left);
        display(temp1->right);
            printf("%d ",temp1->data);
    }
    else
    {
        return;
    }
}
int main()
{
    int x;
    insert(newnode);
    printf("\n");
    while(1)
    {
        printf("Choose one: 1. Display 2. Break: " );
        scanf("%d",&x);
        if(x==1)
        {
            temp1=route;
            display(temp1);
            printf("\n");
        }
        else
        {
            break;
        }
    }
}
