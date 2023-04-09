#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,x,a;
    scanf("%d%d",&n,&x);
    long long sum=0;
    while(n--)
    {
        scanf("%d",&a);
        sum+=a;
    }
    sum=abs(sum);
    int tot=0;
    tot+=sum/x;
    if(sum%x)tot++;
    printf("%d\n",tot);
}
