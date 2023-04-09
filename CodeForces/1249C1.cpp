#include<bits/stdc++.h>
using namespace std;

deque < int > dq;
void call()
{
    for(int i=0;;i++)
    {
        int now=pow(3,i);
        dq.push_back(now);
        if(now>1e4)
        {
            break;
        }
        while(dq.front()!=now)
        {
            int x=dq.front();
            dq.pop_front();
            dq.push_back(now+x);
            dq.push_back(x);
        }
    }
}

int main()
{
    call();
    sort(dq.begin(),dq.end());
    int tc,n;
    scanf("%d",&tc);
    while(tc--)
    {
        scanf("%d",&n);
        int pos=lower_bound(dq.begin(),dq.end(),n)-dq.begin();
        printf("%d\n",dq[pos]);
    }
}
