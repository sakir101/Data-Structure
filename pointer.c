#include<stdio.h>
int main()
{
    /*char ch = 'a';
    char **x;
    x=&ch;
    printf("%c",*x);*/
    int x =5;
    int *p ;
    p=&x;
    int **q;
    q = &p;
    int ***r = &q;
    printf("%d\n",&x);
    printf("%d\n",*p);
    printf("%d\n",*q);
    printf("%d\n",**q);
    printf("%d\n",**r);
    printf("%d\n",***r);
    ***r = 10;
    **q = *p+2;
    printf("%d",x);


}
