#include<stdio.h>

int main()
{
    int n, array[20];
    printf("Enter array size: ");
    scanf("%d",&n);
    for(int i=0; i<n; i++)
    {
        scanf("%d",&array[i]);
    }
    for(int j=1; j<n; j++)
    {
        for(int i=0; i<=(n-2); i++)
        {
            if(array[i]<array[i+1])
            {
                int temp=array[i+1];
                array[i+1]=array[i];
                array[i]=temp;
            }
        }
    }
    for(int i=0; i<n; i++)
    {
        printf("%d ",array[i]);
    }
}
