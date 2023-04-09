#include<bits/stdc++.h>
using namespace std;
int main()
{
    int tc;
    scanf("%d",&tc);
    while(tc--)
    {
        int n,r,a;
        scanf("%d%d",&n,&r);
        set < int > st;
        deque < int > dq;
        for(int i=0;i<n;i++)
        {
            scanf("%d",&a);
            st.insert(a);
        }
        for(auto i : st)dq.push_back(i);
        int cnt=0,sum=0;
        while(dq.size())
        {
            int now=dq.back();
            dq.pop_back();
            cnt++;
            sum+=r;
            while(dq.size() && dq.front()-sum<=0)
            {
                dq.pop_front();
            }
        }
        printf("%d\n",cnt);
    }
}
