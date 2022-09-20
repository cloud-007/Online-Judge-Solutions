#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    string s,temp="";
    cin>>s;
    vector < string > v,ans;
    for(auto i : s)
    {
        if(i=='.')
        {
            v.push_back(temp);
            temp="";
        }
        else
            temp+=i;
    }
    v.push_back(temp);
    if(v.size()==1 || v[0].size()>8 || v[v.size()-1].size()>3)
    {
        puts("NO");
        return 0;
    }
    ans.push_back(v[0]);
    if(v[0]=="" || v[v.size()-1]=="")
    {
        puts("NO");
        return 0;
    }
    for(int i=1; i<v.size()-1; i++)
    {
        string x,y;
        if(v[i].size()<=1)
        {
            puts("NO");
            return 0;
        }
        else
        {
            if(v[i].size()<=11)
            {
                int lim=min(3,(int)(v[i].size()-1));
                for(int j=0; j<v[i].size(); j++)
                {
                    if(j<lim)
                        x+=v[i][j];
                    else
                        y+=v[i][j];
                }
                ans.push_back(x);
                ans.push_back(y);
            }
            else
            {
                puts("NO");
                return 0;
            }
        }
    }
    ans.push_back(v[v.size()-1]);
    puts("YES");
    for(int i=0; i<ans.size(); i+=2)
    {
        cout<<ans[i]<<"."<<ans[i+1]<<"\n";
    }
}
