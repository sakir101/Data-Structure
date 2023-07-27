#include<stdio.h>
int main()
{
    int n;
    int array[20][20], array1[20], array2[20], array3[20];
    int count=0;
    printf("Enter total number of vertax: ");
    scanf("%d",&n);
    for(int i=0; i<n; i++)
    {
        scanf("%d",&array1[i]);
    }
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            printf("%d is linked to %d: ",array1[i], array1[j]);
            scanf("%d",&array[i][j]);
        }
    }
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            count= count+array[i][j];
        }
        array2[i]=count;
        count=0;
    }
    count=0;
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            count=count+array[j][i];
        }
        array3[i]=count;
        count=0;
    }
    for(int i=0; i<n; i++)
    {
        printf("Outdegree of %d: %d\n",array1[i],array2[i]);
        printf("Indegree of %d: %d\n",array1[i], array3[i]);
    }
}
