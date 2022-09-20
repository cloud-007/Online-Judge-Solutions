#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define pfn(a) printf("%d\n",a)
int main()
{
    int tc;
    cin>>tc;
    while(tc--)
    {
        string a,b;
        cin>>a>>b;
        map< char , int > mp;
        for(auto i : b)
            mp[i]++;
        int c=0;
        for(auto i : a)
        {
            if(mp[i])
            {
                c++;
                mp[i]--;
            }
            else
                break;
        }
        cout<<c<<endl;

    }
}
