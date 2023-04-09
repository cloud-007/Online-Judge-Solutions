#include<bits/stdc++.h>
using namespace std;
#define pb push_back

int check(char a)
{
    if(a=='a')
        return 1;
    else if(a=='b')
        return 2;
    else if(a=='c')
        return 3;
    else if(a=='d')
        return 4;
    else if(a=='e')
        return 5;
    else if(a=='f')
        return 6;
    else if(a=='g')
        return 7;
    else if(a=='h')
        return 8;
}

const int sz=100;
vector < int > x[sz];
int mp[sz][sz],dis[sz],visited[sz];

int bfs(int b, int e)
{
    queue< int > q;
    q.push(b);
    visited[b]=1;
    dis[b]=0;
    while(!q.empty())
    {
        int u=q.front();
        for(auto i : x[u])
        {
            if(!visited[i])
            {
                visited[i]=1;
                q.push(i);
                dis[i]=dis[u]+1;
            }
            if(i==e)
                return dis[i];
        }
        q.pop();
    }
    return 0;
}
int main()
{
    int tc;
    cin>>tc;
    while(tc--)
    {
        string a,b;
        cin>>a>>b;
        int c=1;
        for(int i=1; i<=8; i++)
            for(int j=1; j<=8; j++)
                mp[i][j]=c++;
        int st,des;
        int u=check(a[0]),v=a[1]-'0';
        st=mp[u][v];
        int t=check(b[0]);
        des=mp[t][b[1]-'0'];
        queue < pair < int, int > > q;
        q.push({u,v});
        map < int, int > vis;
        vis[st]=1;
        while(!q.empty())
        {
            u=q.front().first,v=q.front().second;
            if(u+2<=8 && v+1<=8)
            {
                int temp=mp[u+2][v+1];
                if(!vis[temp])
                {
                    q.push({u+2,v+1});
                    x[temp].pb(mp[u][v]);
                    x[mp[u][v]].pb(temp);
                }
                vis[temp]=1;
            }
            if(u+2<=8 && v-1>=1)
            {
                int temp=mp[u+2][v-1];
                if(!vis[temp])
                {
                    q.push({u+2,v-1});
                    x[temp].pb(mp[u][v]);
                    x[mp[u][v]].pb(temp);
                }
                vis[temp]=1;
            }
            if(u-2>=1 && v+1<=8)
            {
                int temp=mp[u-2][v+1];
                if(!vis[temp])
                {
                    q.push({u-2,v+1});
                    x[temp].pb(mp[u][v]);
                    x[mp[u][v]].pb(temp);
                }
                vis[temp]=1;
            }
            if(u-2>=1 && v-1>=1)
            {
                int temp=mp[u-2][v-1];
                if(!vis[temp])
                {
                    q.push({u-2,v-1});
                    x[temp].pb(mp[u][v]);
                    x[mp[u][v]].pb(temp);
                }
                vis[temp]=1;
            }
            if(u+1<=8 && v+2<=8)
            {
                int temp=mp[u+1][v+2];
                if(!vis[temp])
                {
                    q.push({u+1,v+2});
                    x[temp].pb(mp[u][v]);
                    x[mp[u][v]].pb(temp);
                }
                vis[temp]=1;
            }
            if(u-1>=1 && v+2<=8)
            {
                int temp=mp[u-1][v+2];
                if(!vis[temp])
                {
                    q.push({u-1,v+2});
                    x[temp].pb(mp[u][v]);
                    x[mp[u][v]].pb(temp);
                }
                vis[temp]=1;
            }
            if(u+1<=8 && v-2>=1)
            {
                int temp=mp[u+1][v-2];
                if(!vis[temp])
                {
                    q.push({u+1,v-2});
                    x[temp].pb(mp[u][v]);
                    x[mp[u][v]].pb(temp);
                }
                vis[temp]=1;
            }
            if(u-1>=1 && v-2>=1)
            {
                int temp=mp[u-1][v-2];
                if(!vis[temp])
                {
                    q.push({u-1,v-2});
                    x[temp].pb(mp[u][v]);
                    x[mp[u][v]].pb(temp);
                }
                vis[temp]=1;
            }
            q.pop();
        }
        c=0;
        memset(visited , 0 , sizeof visited);
        memset(dis , 0 , sizeof dis);
        c=bfs(st,des);
        cout<<c<<endl;
    }
}
