#include<bits/stdc++.h>
using namespace std;
int main()
{
    int x,y;
    scanf("%d%d",&x,&y);
    if(x<y-1)
    {
        puts("NO");
        return 0;
    }
    if(x-(y-1)==0)
        puts("YES");
    else if((x-(y-1))%2==0 && y-1>0)
        puts("YES");
    else
        puts("NO");
}
