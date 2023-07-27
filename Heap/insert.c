#include<stdio.h>
int n, array[20];
typedef struct binary_tree
{
    int data;
    struct binary_tree *left, *right;
} node;
node *newnode=NULL, *route=NULL, *temp1;
node *create_tree(int i,node *newnode)
{
    if(i<=n)
    {
        node *temp;
        newnode=(node *)malloc(sizeof(node));
        newnode->data=array[i];
        newnode->left=NULL;
        newnode->right=NULL;
        if(route==NULL)
        {
            route=temp=newnode;
            i=2*i;
            temp->left=create_tree(i, newnode);
            i=i+1;
            temp->right=create_tree(i, newnode);
            return newnode;
        }
        else
        {
            temp=newnode;
            i=2*i;
            temp->left=create_tree(i, newnode);
            i=i+1;
            temp->right=create_tree(i, newnode);
            return newnode;
        }
    }
    else
    {
        return NULL;
    }

}
void display(node *temp1)
{
    if(temp1==NULL)
    {
        return;
    }
    else
    {
        printf("%d ",temp1->data);
        display(temp1->left);
        display(temp1->right);
        return;
    }

}
void Max_heapify(int i)
{
    int largest=i;
    int l= 2*i;
    int r= (2*i)+1;
    if(l<=n && array[largest]<array[l])
    {
        largest=l;
    }
    if(r<=n && array[largest]<array[r])
    {
        largest=r;
    }
    if(largest!=i)
    {
        int temp2=array[i];
        array[i]=array[largest];
        array[largest]=temp2;
        Max_heapify(largest);
    }
}
void insert()
{
        int value, x;
        printf("\n Want to insert: 1.Y 2.N: ");
        scanf("%d",&x);
        if(x==1)
        {
            printf("Enter data: ");
            scanf("%d",&value);
            n=n+1;
            array[n]=value;
            for(int i=n/2; i>=1; i--)
            {
                Max_heapify(i);
            }
            insert();
            return;
        }
        else
        {
            int i=1;
            newnode=NULL;
            route=NULL;
            create_tree(i, newnode);
            temp1=route;
            display(temp1);
            return;
        }
}
int main()
{
    printf("Enter array size: ");
    scanf("%d",&n);
    for(int i=1; i<=n; i++)
    {
        scanf("%d",&array[i]);
    }
    int i=1;
    create_tree(i, newnode);
    temp1=route;
    printf("Before Max Heapify\n");
    display(temp1);
    printf("After Max Heapify\n");
    for(int i=n/2; i>=1; i--)
    {
        Max_heapify(i);
    }
    i=1;
    newnode=NULL;
    route=NULL;
    create_tree(i, newnode);
    temp1=route;
    printf("\n After Max Heapify\n");
    display(temp1);
   insert();
}
