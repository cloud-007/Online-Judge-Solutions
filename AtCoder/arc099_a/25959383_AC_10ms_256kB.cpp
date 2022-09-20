#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,op,a;
    scanf("%d%d",&n,&op);
    for(int i=1; i<=n; i++)
        scanf("%d",&a);
    int ans=1;
    n-=op;
    op--;
    ans+=(n/op);
    if(n%op)
        ans++;
    printf("%d\n",ans);
}
