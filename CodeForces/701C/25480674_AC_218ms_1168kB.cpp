#include<bits/stdc++.h>
using namespace std;

vector < int > x[100];

int main()
{
    int n,mn=INT_MAX;
    cin>>n;
    char a[n+5];
    set < int > st;
    for(int i=0; i<n; i++)
    {
        cin>>a[i];
        x[a[i]-'A'].push_back(i);
        st.insert(a[i]-'A');
    }
    for(auto i : st)
    {
        for(auto j : x[i])
        {
            int now=j,mx=0;
            bool fl=true;
            for(auto k :st)
            {
                if(k!=i)
                {
                    int lo=0,hi=x[k].size()-1,ans=INT_MAX;
                    while(lo<=hi)
                    {
                        int mid=(lo+hi)/2;
                        if(x[k][mid]<=now)
                            lo=mid+1;
                        else
                        {
                            ans=x[k][mid];
                            hi=mid-1;
                        }
                    }
                    if(ans==INT_MAX)
                    {
                        fl=false;
                        break;
                    }
                    else
                        mx=max(mx,ans);
                }
            }
            if(fl)
            {
                int tot=abs(now-mx)+1;
                if(tot)
                    mn=min(mn,tot);
            }
        }
    }
    cout<<mn<<endl;
}
