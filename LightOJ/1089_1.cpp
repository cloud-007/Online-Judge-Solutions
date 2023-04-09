#include<bits/stdc++.h>
using namespace std;
int main()
{
    int tc,casee=1;
    scanf("%d",&tc);
    while(tc--)
    {
        int n,q;
        scanf("%d%d",&n,&q);
        vector < int > a,b;
        for(int i=0;i<n;i++)
        {
            int l,r;
            scanf("%d%d",&l,&r);
            if(l>r)swap(l,r);
            a.push_back(l);
            b.push_back(r);
        }
        sort(a.begin(),a.end());
        sort(b.begin(),b.end());
        printf("Case %d:\n",casee++);
        while(q--)
        {
            int p;
            scanf("%d",&p);
            int x=upper_bound(a.begin(),a.end(),p)-a.begin();
            int y=lower_bound(b.begin(),b.end(),p)-b.begin();
            printf("%d\n",abs(x-y));
        }
    }
}
