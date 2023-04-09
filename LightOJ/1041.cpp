#include<bits/stdc++.h>
using namespace std;

set < string > st,vis;
map < string, string > p;
priority_queue < pair < int, pair < string, string > >> pq;
string find(string x)
{
    if(p[x]==x)
        return x;
    return p[x] = find( p[x]);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    int tc,casee=1;
    cin>>tc;
    while(tc--)
    {
        string u, v;
        int n,c,tot=0;
        cin>>n;
        while(!pq.empty())
            pq.pop();
        st.clear(),vis.clear(),p.clear();
        for(int i=0; i<n; i++)
        {
            cin>>u>>v>>c;
            st.insert(u),st.insert(v);
            pq.push({-c,{u,v}});
        }
        for(auto i : st)
            p[i]=i;
        while(!pq.empty())
        {
            string x=find(pq.top().second.first);
            string y=find(pq.top().second.second);
            if(x!=y)
            {
                tot+=abs(pq.top().first);
                p[y]=x;
            }
            pq.pop();
        }
        int cnt=0;
        for(auto i : st)
        {
            if(find(i)==i)cnt++;
        }
        cout<<"Case "<<casee++<<": ";
        if(cnt==1)
        cout<<tot<<endl;
        else
            cout<<"Impossible"<<endl;
    }
}
