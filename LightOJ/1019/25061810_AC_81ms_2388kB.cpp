#include<bits/stdc++.h>
using namespace std;

const int sz=150;
vector < int > x[sz];
map < pair < int, int >, int > cost;
map < int, int > dis;

void djk(int u)
{
    priority_queue < pair < int, int >> pq;
    pq.push({0,u});
    dis[u]=0;
    while(!pq.empty())
    {
        u=pq.top().second;
        pq.pop();
        for(auto i : x[u])
        {
            if(dis[u]+cost[ {u,i}]<dis[i])
            {
                dis[i]=dis[u]+cost[ {u,i}];
                pq.push({-dis[i],i});
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    int tc,casee=1;
    cin>>tc;
    while(tc--)
    {
        int n,m;
        cin>>n>>m;
        for(int i=0; i<=sz; i++)
            x[i].clear();
        dis.clear(),cost.clear();
        while(m--)
        {
            int u, v, c;
            cin>>u>>v>>c;
            x[u].push_back(v);
            x[v].push_back(u);
            if(cost[ {u,v}] || cost[ {v,u}])
            {
                cost[ {u,v}]=min(cost[ {u,v}],c);
                cost[ {v,u}]=min(cost[ {v,u}],c);
            }
            else
            {
                cost[ {u,v}]=c;
                cost[ {v,u}]=c;
            }
        }
        for(int i=0;i<=sz;i++)dis[i]=INT_MAX;
        djk(1);
        if(dis[n]!=INT_MAX)
            cout<<"Case "<<casee++<<": "<<dis[n]<<endl;
        else
            cout<<"Case "<<casee++<<": Impossible\n";
    }
}
