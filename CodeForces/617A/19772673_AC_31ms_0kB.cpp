#include<stdio.h>
int main()
{
    int a,b=5;
    scanf("%d",&a);
    if(a%b==0){
        printf("%d\n",a/b);
    }
    else{
        printf("%d\n",(a/b)+1);
    }
    return 0;
}
