#include<bits/stdc++.h>
using namespace std;
int main()
{
    int p,e;
    scanf("%d%d",&p,&e);
    set < string > sp,se;
    deque < string > common;
    string s;
    while(p--)
    {
        cin>>s;
        sp.insert(s);
    }
    int a=sp.size();
    while(e--)
    {
        cin>>s;
        if(sp.count(s))
            a--,common.push_back(s);
        else
            se.insert(s);
    }
    bool fl;
    if(common.size()%2==0)fl=true;
    else fl=false;
    int b=se.size();
    if(fl)
    {
        if(a<=b)puts("NO");
        else puts("YES");
    }
    else
    {
        if(a>=b)puts("YES");
        else puts("NO");
    }
}
