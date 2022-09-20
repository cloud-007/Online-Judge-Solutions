#include<bits/stdc++.h>
using namespace std;
int main()
{
    int tc,a,b,c;
    scanf("%d",&tc);
    while(tc--)
    {
        scanf("%d%d%d",&a,&b,&c);
        b-=c;
        if(a>b)
            printf("do not advertise\n");
        else if(a==b)
            printf("does not matter\n");
        else
            printf("advertise\n");
    }
}
