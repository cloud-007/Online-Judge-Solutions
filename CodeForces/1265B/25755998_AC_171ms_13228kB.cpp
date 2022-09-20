#include<bits/stdc++.h>
using namespace std;

const int sz=2e5+50;
int mp[sz],a[sz],ans[sz],done[sz];
set < int > st;

int main()
{
    int tc;
    scanf("%d",&tc);
    while(tc--)
    {
        st.clear();
        memset(mp, 0, sizeof mp);
        memset(a, 0 , sizeof a);
        memset(ans, 0 , sizeof ans);
        memset(done,0,sizeof done);
        int n,l,r;
        scanf("%d",&n);
        for(int i=1;i<=n;i++)
        {
            scanf("%d",&a[i]);
            mp[a[i]]=i;
            if(a[i]==1)
                l=i,r=i;
        }
        st.insert(a[l]);
        for(int i=1;i<=n;i++)
        {
            if(done[i])
            {
                if(st.size()==*st.rbegin() && st.size()==i)
                {
                    int id=abs(l-r)+1;
                    ans[id]=1;
                }
                continue;
            }
            int id=mp[i];
            if(id>r)
            {
                while(r<=id)
                {
                    done[a[r]]=1;
                    st.insert(a[r]);
                    r++;
                }
                r--;
            }
            else if(id<l)
            {
                while(l>=id)
                {
                    done[a[l]]=1;
                    st.insert(a[l]);
                    l--;
                }
                l++;
            }
            if(st.size()==*st.rbegin() && st.size()==i)
            {
                id=abs(l-r)+1;
                ans[id]=1;
            }
        }
        for(int i=1;i<=n;i++)
            printf("%d",ans[i]);
        printf("\n");
    }
}
