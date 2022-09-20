#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    int n;
    scanf("%d",&n);
    ll sum=0,now=0;
    int a[n+5];
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
        sum+=a[i];
    }
    for(int i=1;i<=n;i++)
    {
        now+=a[i];
        if(abs(sum-now) && now )
        {
            printf("YES\n2\n");
            printf("1 %d\n",i);
            printf("%d %d\n",i+1,n);
            return 0;
        }
    }
    if(sum)
    {
        printf("YES\n1\n");
        printf("1 %d\n",n);
        return 0;
    }
    puts("NO");
}
