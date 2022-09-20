#include<bits/stdc++.h>
using namespace std;
int main()
{
    int tc;
    scanf("%d",&tc);
    while(tc--)
    {
        int n,k;
        scanf("%d%d",&n,&k);
        set < int > st;
        int a[n+5];
        map < int , int > mp;
        for(int i=0;i<n;i++)
        {
            cin>>a[i];
            st.insert(a[i]);
            mp[a[i]]++;
        }
        if(k<st.size())
        {
            puts("-1");
            continue;
        }
        vector < int > v, ans;

        int x=st.size();
        x=abs(x-k)+1;
        for(auto i : st)
        {
            if(x>0)
            while(x>0)
            {
                x--;
                v.push_back(i);
            }
            else
                v.push_back(i);
        }
        for(int i=0;i<n;i++)
        {
            for(auto j : v)ans.push_back(j);
        }
        printf("%d\n",ans.size());
        for(auto i : ans)printf("%d ",i);
        printf("\n");
    }
}