#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,k1,k2,cnt=0,a,b;
    queue < int > s1,s2;
    scanf("%d",&n);
    scanf("%d",&k1);
    for(int i=1;i<=k1;i++)
    {
        scanf("%d",&a);
        s1.push(a);
    }
    scanf("%d",&k2);
    for(int i=1;i<=k2;i++)
    {
        scanf("%d",&a);
        s2.push(a);
    }
    a=0,b=0;
    while(s1.size() && s2.size())
    {
        int x=s1.front();
        int y=s2.front();
        s1.pop(),s2.pop();
        if(x>y)
        {
            a++;
            cnt++;
            s1.push(y);
            s1.push(x);
        }
        else
        {
            b++,cnt++;
            s2.push(x);
            s2.push(y);
        }
        if(cnt>pow(n,5))
        {
            puts("-1");
            return 0;
        }
    }
    if(a>b)
        a=1;
    else
        a=2;
    printf("%d %d\n",cnt,a);
}
