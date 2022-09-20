#include<bits/stdc++.h>
using namespace std;
int main()
{
    int tc;
    cin>>tc;
    while(tc--)
    {
        string s;
        bool o=false,z=false;
        cin>>s;
        string x="01";
        for(auto i : s)
        {
            if(i=='0')o=true;
            else z=true;
        }
        if(o && z)
        {
            for(int i=1;i<=s.size();i++)
                cout<<x;
            cout<<endl;
        }
        else
            cout<<s<<endl;
    }
}
