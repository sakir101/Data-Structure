#include<stdio.h>
typedef struct binary_tree
{
    int data;
    struct binary_tree *left, *right;
} node;

node *newnode=NULL,  *root=NULL, *temp1, *temp, *temp2;
void create()
{
    int x, data;
    printf("Do you want to insert 1. Y 2. N: ");
    scanf("%d",&x);
    if(x==1)
    {
        printf("Enter data: ");
        scanf("%d",&data);
        newnode=(node *)malloc(sizeof(node));
        newnode->data=data;
        newnode->left=NULL;
        newnode->right=NULL;
        if(root==NULL)
        {
            root=temp=newnode;
            create();
            return;
        }
        else
        {
            while(temp!=NULL)
            {
                if(data<temp->data)
                {
                    if(temp->left==NULL)
                    {
                        temp->left=newnode;
                        temp=root;
                        create();
                        return;
                    }
                    else
                    {
                        temp=temp->left;
                    }
                }
                else if(data>temp->data)
                {
                    if(temp->right==NULL)
                    {
                        temp->right=newnode;
                        temp=root;
                        create();
                        return;
                    }
                    else
                    {
                        temp=temp->right;
                    }
                }
            }
        }
    }
    else
    {
        return;
    }
}
node *display_preorder(node *temp1)
{
    if(root==NULL)
    {
        printf("Empty\n");
    }
    else
    {
        if(temp1==NULL)
        {
            return;
        }
        else
        {
            printf("%d ",temp1->data);
        }
        display_preorder(temp1->left);
        display_preorder(temp1->right);
    }
}

node *display_inorder(node *temp1)
{

    if(root==NULL)
    {
        printf("Empty\n");
    }
    else if(temp1!=NULL)
    {
        display_inorder(temp1->left);

        printf("%d ",temp1->data);
        display_inorder(temp1->right);
    }
    else
    {
        return;
    }
}

node *display_postorder(node *temp1)
{

    if(root==NULL)
    {
        printf("Empty\n");
    }
    else if(temp1!=NULL)
    {
        display_postorder(temp1->left);
        display_postorder(temp1->right);
        printf("%d ",temp1->data);
    }
    else
    {
        return;
    }
}

void search()
{
    temp2=root;
    int data;
    printf("\nEnter Data: ");
    scanf("%d",&data);
    while(temp2!=NULL)
    {
        if(data<temp2->data)
        {
            temp2=temp2->left;
        }
        else if(data>temp2->data)
        {
            temp2=temp2->right;
        }
        else if(data==temp2->data)
        {
            printf("Data Found");
            return;
        }
    }
    printf("Data not found");
    return;
}

int main()
{
    int x;
    create();
    while(1)
    {
        printf("\n Choose one: 1. Insert Data 2. Preorder 3. Postorder 4. Inorder 5. Search 6. Break");
        scanf("%d",&x);
        if(x==1)
        {
            create();
        }
        else if(x==2)
        {
            temp1=root;
            display_preorder(temp1);
        }
        else if(x==3)
        {
            temp1=root;
            display_postorder(temp1);
        }
        else if(x==4)
        {
            temp1=root;
            display_inorder(temp1);
        }
        else if(x==5)
        {
            search();
        }
        else
        {
            break;
        }
    }

}
