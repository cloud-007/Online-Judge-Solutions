#include<bits/stdc++.h>
using namespace std;
int main()
{
    int tc;
    scanf("%d",&tc);
    while(tc--)
    {
        int n,x,mn=INT_MAX;
        scanf("%d%d",&n,&x);
        int dis=(x+1)/2,i;
        while(n--)
        {
            scanf("%d",&i);
            if(i>x)
                mn=min(mn,2);
            else if(x%i==0)
                mn=min(mn,x/i);
            else
            {
                int b=x/i;
                if(x%i<=dis)
                    b++;
                else
                    b+=2;
                mn=min(mn,b);
            }
        }
        printf("%d\n",mn);
    }
}
