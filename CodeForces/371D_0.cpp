#include<bits/stdc++.h>
using namespace std;
const int sz=2e5+50;
int a[sz];

map < int, int > mp,go;

int main()
{
    int n;
    scanf("%d",&n);
    vector < int > temp;
    for(int i=1; i<=n; i++)
    {
        scanf("%d",&a[i]);
        mp[i]=a[i];
    }
    int m;
    scanf("%d",&m);
    while(m--)
    {
        int id,op;
        scanf("%d%d",&id,&op);
        if(id==1)
        {
            temp.clear();
            int add;
            scanf("%d",&add);
            int x=op;
            while(op<=n && add>0 && mp[op]<=add)
            {
                if(go[op])
                {
                    op=go[op];
                }
                if(op!=x)
                {
                    temp.push_back(x);
                }
                add-=mp[op];
                mp[op]=0;
                op++;
            }
            if(x!=op-1 && x< op)
            {
                go[x]=op-1;
                for(auto i : temp)
                {
                    go[i]=op-1;
                }
            }
            if(op <=n && add>0)
                mp[op]-=add;
        }
        else
        {
            if(!mp[op])
                printf("%d\n",a[op]);
            else
                printf("%d\n",a[op]-mp[op]);
        }
    }
}
