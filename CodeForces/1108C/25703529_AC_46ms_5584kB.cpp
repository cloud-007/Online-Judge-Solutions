#include<bits/stdc++.h>
using namespace std;
int main()
{
    string  a="RGB",b="BRG",c="GBR",d="RBG",e="BGR",f="GRB";
    int mn=INT_MAX;
    int n;
    scanf("%d",&n);
    string s;
    cin>>s;
    string x="",y="",z="",p="",q="",r="",ans;
    for(int i=0;i<n/3;i++)
        x+=a;
    if(n%3)x+=a;
    for(int i=0;i<n/3;i++)
        y+=b;
    if(n%3)y+=b;
    for(int i=0;i<n/3;i++)
        z+=c;
    if(n%3)z+=c;
    for(int i=0;i<n/3;i++)
        p+=d;
    if(n%3)p+=d;
    for(int i=0;i<n/3;i++)
        q+=e;
    if(n%3)q+=e;
    for(int i=0;i<n/3;i++)
        r+=f;
    if(n%3)r+=f;
    int cnt=0;
    for(int i=0;i<n;i++)
    {
        if(s[i]!=x[i])cnt++;
    }
    if(cnt<mn)
    {
        mn=cnt;
        ans=x;
    }
    cnt=0;
    for(int i=0;i<n;i++)
    {
        if(s[i]!=y[i])cnt++;
    }
    if(cnt<mn)
    {
        mn=cnt;
        ans=y;
    }
    cnt=0;
    for(int i=0;i<n;i++)
    {
        if(s[i]!=z[i])cnt++;
    }
    if(cnt<mn)
    {
        mn=cnt;
        ans=z;
    }
    cnt=0;
    for(int i=0;i<n;i++)
    {
        if(s[i]!=p[i])cnt++;
    }
    if(cnt<mn)
    {
        mn=cnt;
        ans=p;
    }
    cnt=0;
    for(int i=0;i<n;i++)
    {
        if(s[i]!=q[i])cnt++;
    }
    if(cnt<mn)
    {
        mn=cnt;
        ans=q;
    }
    cnt=0;
    for(int i=0;i<n;i++)
    {
        if(s[i]!=r[i])cnt++;
    }
    if(cnt<mn)
    {
        mn=cnt;
        ans=r;
    }
    printf("%d\n",mn);
    for(int i=0;i<n;i++)printf("%c",ans[i]);
}
