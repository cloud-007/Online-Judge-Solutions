#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    if(m<n)swap(n,m);
    n++,m++;
    for(int i=n;i<=m;i++)
        printf("%d\n",i);
}
