#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,a;
    string s;
    scanf("%d",&n);
    cin>>s;
    map < int, int >mp;
    set < int > st;
    for(int i=1; i<=9; i++)
    {
        scanf("%d",&a);
        mp[i]=a;
    }
    for(int i=0; i<n; i++)
    {
        int now=s[i]-'0';
        if(mp[now]>now)
        {
            int j=i;
            while(j<n && mp[s[j]-'0']>=s[j]-'0')
            {
                st.insert(s[j]-'0');
                j++;
            }
            for(i; i<j; i++)
            {
                now=s[i]-'0';
                if(st.count(now))
                    s[i]=mp[now]+'0';
            }
            cout<<s<<endl;
            return 0;
        }
    }
    cout<<s<<endl;
}
