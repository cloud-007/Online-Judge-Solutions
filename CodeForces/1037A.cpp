#include<bits/stdc++.h>
using namespace std;
int main()
{
    int sum=0,n,cnt=0;
    scanf("%d",&n);
    for(int i=1;;i*=2)
    {
        sum+=i;
        if(sum>n)
        {
            sum-=i;
            break;
        }
        cnt++;
    }
    if(sum<n)cnt++;
    printf("%d\n",cnt);
}
