#include<bits/stdc++.h>
using namespace std;
int main()
{
    int tc;
    scanf("%d",&tc);
    while(tc--)
    {
        int n,p;
        scanf("%d%d",&n,&p);
        int tot=n*2;
        tot+=p;
        bool fl=false;
        for(int i=1;i<n;i++)
        {
            for(int j=i+1;j<=n;j++)
            {
                printf("%d %d\n",i,j);
                tot--;
                if(!tot)
                {
                    fl=true;
                    break;
                }
            }
            if(fl)break;
        }
    }
}
