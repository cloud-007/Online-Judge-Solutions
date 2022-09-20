#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,x,y;
    scanf("%d%d%d",&n,&x,&y);
    int a;
    priority_queue < int > pq;
    for(int i=0;i<n;i++)
    {
        scanf("%d",&a);
        pq.push(-a);
    }
    if(x>y)
        printf("%d\n",n);
    else
    {
        bool fl=true;
        int cnt=0;
        while(pq.size())
        {
            a=-pq.top();
            if(fl)
            {
                if(a-x<=0)
                {
                    cnt++;
                    pq.pop();
                }
                else
                    break;
            }
            else
            {
                pq.pop();
                a+=y;
                pq.push(-a);
            }
            fl^=1;
        }
        printf("%d\n",cnt);
    }
}
