#include<bits/stdc++.h>
using namespace std;
int main()
{
    int tc;
    cin>>tc;
    stack < int > st,st1;
    tc*=2;
    deque < int > dq;
    int n=tc;
    while(tc--)
    {
        int a;
        cin>>a;
        dq.push_back(a);
    }
    int cnt=0,mx=0,d=0;
    bool fl=false;
    while(true)
    {
        if(dq.size() && st1.size() && dq.front()==st1.top())
        {
            d+=2;
            fl=true;
            cnt++;
            mx=max(mx,cnt);
            dq.pop_front(),st1.pop();
        }
        else if(dq.size())
            st1.push(dq.front()),dq.pop_front(),cnt++;
        else
            break;
    }
    if(d==n)printf("%d\n",mx);
    else printf("impossible\n");
}
