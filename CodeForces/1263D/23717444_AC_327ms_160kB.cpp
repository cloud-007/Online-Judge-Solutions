#include<bits/stdc++.h>
using namespace std;
 
const int sz=30;
int par[sz];
 
int find(int u)
{
    if(par[u]==u)
        return u;
    return par[u]=find(par[u]);
}
 
void union_s(int u,int v)
{
    int x=find(u),y=find(v);
    if(x!=y)
    {
        par[y]=x;
    }
}
 
int main()
{
    int n;
    cin>>n;
    set < int > st,temp;
    for(int i=0;i<=26;i++)
        par[i]=i;
    while(n--)
    {
        string s;
        cin>>s;
        vector < int > v;
        for(auto i : s)
        {
            st.insert(i-'a');
            temp.insert(i-'a');
        }
        for(auto i : temp)
            v.push_back(i);
        temp.clear();
        for(int i=0;i<v.size()-1;i++)
        {
            union_s(v[i],v[i+1]);
        }
        v.clear();
    }
    int res=0;
    for(auto i : st)
    {
        if(i==find(i))
        {
            res++;
        }
    }
    cout<<res<<endl;
 
}