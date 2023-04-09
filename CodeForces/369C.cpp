#include<bits/stdc++.H>
using namespace std;

const int sz=1e5+50;
map < pair < int , int > , int > mp;
vector < int > x[sz],v;
int vis[sz];

int dfs(int u)
{
    vis[u]=1;
    int sum=0;
    for(auto i : x[u])
    {
        if(!vis[i])
        {
            int res=dfs(i);
            if(res==0 && mp[{u,i}]){sum++,v.push_back(i);}
            else sum+=res;
        }
    }
    return sum;
}

int main()
{
    int n;
    scanf("%d",&n);
    for(int i=1;i<n;i++)
    {
        int u,v,id;
        scanf("%d%d%d",&u,&v,&id);
        x[u].push_back(v);
        x[v].push_back(u);
        if(id==2)
        {
            mp[{u,v}]=1;
            mp[{v,u}]=1;
        }
    }
    dfs(1);
    printf("%d\n",v.size());
    for(auto i : v)
        printf("%d ",i);
    printf("\n");
}
