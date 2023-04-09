#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    int n,a;
    scanf("%d",&n);
    set < int > st;
    map < int,int > mp;
    for(int i=1; i<=n; i++)
    {
        scanf("%d",&a);
        mp[a]++;
            st.insert(a);
    }
    int cnt=0;
    while(st.size())
    {
        ll last=0,tot=0;
        cnt++;
        queue < int > q;
        bool fl=true;
        for(auto i : st)
        {
            if(i>=tot)
            {
                int av=mp[i];
                int add=abs(tot-i)+1;
                tot+=min(add,mp[i]);
                mp[i]-=add;
            }
            if(mp[i]<=0)
                q.push(i);
        }
        while(!q.empty())
        {
            //printf("%d ",q.front());
            st.erase(q.front()),q.pop();
        }
        //puts("");
    }
    printf("%d\n",cnt);
}
