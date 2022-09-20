#include<iostream>
#include<map>
#include<algorithm>
#include<vector>
#include<utility>
using namespace std;
int main()
{
    int n;
    cin>>n;
    vector<string>r,cw,m,c;
    while(n--)
    {
        string a,b;
        cin>>a>>b;

       // mp1[b]=a;
        if(b=="rat")
            r.push_back(a);
        else if(b=="child"|| b=="woman")
            cw.push_back(a);
        else if(b=="man")
            m.push_back(a);
        else if(b=="captain")
            c.push_back(a);
    }
    for(int i=0;i<r.size();i++)
        cout<<r[i]<<endl;
    for(int i=0;i<cw.size();i++)
        cout<<cw[i]<<endl;
    for(int i=0;i<m.size();i++)
        cout<<m[i]<<endl;
    for(int i=0;i<c.size();i++)
        cout<<c[i]<<endl;
}
