#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    int tc;
    scanf("%d",&tc);
    while(tc--)
    {
        string s;
        cin>>s;
        s+="aa";
        vector < int > v;
        for(int i=0; i<s.size()-2; i++)
        {
            if(s[i]=='o' && s[i+1]=='n' && s[i+2]=='e')
            {
                s[i+1]='a';
                v.push_back(i+2);
            }
            else if(s[i]=='t' && s[i+1]=='w' && s[i+2]=='o')
            {
                if(s[i+3]=='n' && s[i+4]=='e')
                {
                    s[i+2]='a';
                    v.push_back(i+3);
                }
                else
                    v.push_back(i+2);
            }
        }
        printf("%d\n",v.size());
        if(!v.size())
            puts("");
        else
        {
            for(auto i : v)
                printf("%d ",i);
            puts("");
        }
    }
}
