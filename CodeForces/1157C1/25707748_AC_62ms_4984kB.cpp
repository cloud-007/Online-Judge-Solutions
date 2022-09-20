#include<bits/stdc++.h>
using namespace std;
deque < int > dq;

int main()
{
    int n,a,pr=0;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d",&a),dq.push_back(a);
    string s="";
    while(!dq.empty())
    {
        int x=dq.front(),y=dq.back();
        int c=min(x,y),d=max(x,y);
        if(c>pr && c==x){pr=c ; s+='L'; dq.pop_front();}
        else if(c>pr && c==y){pr=c ; s+='R'; dq.pop_back();}
        else if(d>pr && d==y){pr=d; s+='R'; dq.pop_back();}
        else if(d>pr && d==x){pr=d; s+='L'; dq.pop_front(); }
        else if(x==y && x>pr){s+='L'; break;}
        else break;
    }
    printf("%d\n",(int)s.size());
    cout<<s<<endl;
}
