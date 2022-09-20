#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    scanf("%d",&n);
    vector < char > v;
    string s;
    cin>>s;
    for(auto c : s)
    {
        if(v.empty())
        {
            v.push_back(c);
        }
        else if(((int)(v.size())%2))
        {
            if(c!=v.back())
                v.push_back(c);
        }
        else
        {
            v.push_back(c);
        }
    }
    if((int)v.size()&1)
        v.pop_back();
    printf("%d\n",n-(int)v.size());
    for(auto i : v)printf("%c",i);
}
