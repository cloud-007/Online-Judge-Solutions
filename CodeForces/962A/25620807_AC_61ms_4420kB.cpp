#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,sum=0,to=0;
    scanf("%d",&n);
    int a[n+5];
    for(int i=1;i<=n;i++)scanf("%d",&a[i]),sum+=a[i];
    int x=sum;
    sum/=2;
    if(x%2)sum++;
    for(int i=1;i<=n;i++)
    {
        to+=a[i];
        if(to>=sum)
        {
            printf("%d\n",i);
            return 0;
        }
    }
}
