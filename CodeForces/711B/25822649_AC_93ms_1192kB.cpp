#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int sz=550;
ll row[sz],col[sz],di1=0,di2=0;

int main()
{
    //memset(row,0,sizeof row);
    //memset(col,0,sizeof col);
    int n,x,y;
    scanf("%d",&n);
    int a[n+5][n+5];
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            scanf("%d",&a[i][j]);
            row[i]+=a[i][j];
            col[j]+=a[i][j];
            if(!a[i][j])x=i,y=j;
        }
    }
    if(n==1)
    {
        puts("1");
        return 0;
    }
    set < ll > st,st1;
    int c=0;
    for(int i=1;i<=n;i++)
    {
        di1+=a[i][i];
        if(!a[i][i])
        {
            c=1;
        }
    }
    if(c)st1.insert(di1);
    else st.insert(di1);
    c=0;
    for(int i=1,j=n;i<=n,j>=1;i++,j--)
    {
        di2+=a[i][j];
        if(!a[i][j])c=1;
    }
    if(c)st1.insert(di2);
    else st.insert(di2);
    for(int i=1;i<=n;i++)
    {
        if(i==x)st1.insert(row[i]);
        else st.insert(row[i]);
        if(i==y)st1.insert(col[i]);
        else st.insert(col[i]);
    }
    if(st.size()==1 && st1.size()==1 && *st.begin()>*st1.begin())
    {
        ll x=abs(*st.begin()-*st1.begin());
        printf("%lld\n",x?x:-1);
    }
    else puts("-1");
}
