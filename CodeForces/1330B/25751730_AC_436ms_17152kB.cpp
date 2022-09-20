#include<bits/stdc++.h>
using namespace std;
int main()
{
    int tc;
    scanf("%d",&tc);
    while(tc--)
    {
        set < int > s1,s2;
        map < int, int > mp;
        int n,cnt1=0,cnt2;
        scanf("%d",&n);
        cnt2=n;
        int a[n+5],fl=0;
        for(int i=1; i<=n; i++)
        {
            scanf("%d",&a[i]);
            mp[a[i]]++;
            if(mp[a[i]]>2)
                fl=1;
            s2.insert(a[i]);
        }
        if(fl)
        {
            puts("0");
            continue;
        }
        vector < pair < int, int >> vp;
        for(int i=1; i<n; i++)
        {
            cnt1++,cnt2--;
            mp[a[i]]--;
            if(mp[a[i]]==0)
                s2.erase(a[i]);
            s1.insert(a[i]);
            if(*s1.rbegin()==cnt1 && cnt1==s1.size() && cnt2==s2.size() && *s2.rbegin()==cnt2)
            {
                vp.push_back({i,abs(n-i)});
            }
        }
        printf("%d\n",vp.size());
        for(auto i : vp)
            printf("%d %d\n",i.first,i.second);
    }
}
