#include<bits/stdc++.h>
using namespace std;
typedef pair < int, int > pi;
typedef long long ll;
typedef pair< ll,ll > pll;
#define start() ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define sf(a) scanf("%d",&a)
#define sf2(x,y) scanf("%d%d",&x,&y)
#define sfl(b) scanf("%I64d",&b)
#define sfl2(g,h) scanf("%I64d%I64d",&g,&h)
#define pf(c) printf("%d ",c)
#define pfn(m) printf("%d\n",m)
#define pfl(d) printf("%I64d ",d)
#define pfln(o) printf("%I64d\n",o)
#define pb push_back
#define bug() puts("Debug here")
#define f(n) for(int i=0;i<n;i++)
#define tc() int t;sf(t);while(t--)
int main()
{
    int n;
    sf(n);
    vector < string > ans;
    f(n)
    {
        string a;
        cin>>a;
        ans.pb(a);
    }
    string x="";
    for(int i=0; i<n-1; i++)
    {
        x+=ans[i];
        x+=" ";
    }
    x+=ans[ans.size()-1];
    vector < char > check;
    bool caps=false;
    int m;
    sf(m);
    f(m)
    {
        string a;
        cin>>a;
        if(a=="CapsLock")
        {
            if(!caps)
                caps=true;
            else
                caps=false;
            continue;
        }
        else if(a=="Backspace")
        {
            if(check.size()>0)
            {
                check.erase(check.begin()+check.size()-1);
            }
            continue;
        }
        else if(a=="Space")
        {
            check.pb(' ');
            continue;
        }

        if(caps)
        {
            for(auto i : a)
                check.pb(toupper(i));
        }
        else if(!caps)
        {
            for(auto i : a)
                check.pb(i);
        }
    }
    int cnt=0;
    if(check.size()<x.size())
    {
        for(int i=check.size();i<x.size();i++)
            check.pb('o');
    }
    for(int i=0;i<x.size();i++)
        if(x[i]==check[i])
        cnt++;
    //cout<<x<<' '<<cnt<<endl;
    printf(cnt==x.size()?"Correct":"Incorrect");
    return 0;
}

