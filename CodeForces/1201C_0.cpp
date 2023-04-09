#include<bits/stdc++.h>
using namespace std;

#define ll long long

int main()
{
    int n,k;
    scanf("%d%d",&n,&k);
    int a[n];
    for(int i=0; i<n; i++)
        scanf("%d",&a[i]);
    sort(a,a+n);
    int mid=n/2;
    queue < int > q;
    for(int i=mid+1; i<n; i++)
        q.push(a[i]);
    int cnt=0,val=a[mid];
    while(!q.empty() && k>0)
    {
        cnt++;
        int now=q.front();
        q.pop();
        if(k>=cnt)
        {
            int dif=abs(val-now);
            int x=min(dif,(k/cnt));
            //printf("%d %d\n",(ll)dif*cnt,(ll)x*cnt);
            val+=min(dif,x);
            k-=min((ll)dif*cnt,(ll)x*cnt);
        }
        else break;
    }
    cnt++;
    if(k)
    {
        //printf("%d %d\n",cnt,k);
        val+=k/cnt;
    }
    printf("%d\n",val);
}
