#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long sum=0;
    cin.tie(0),cout.tie(0);
    set < int > st;
    map < int,deque < int > > mp;
    map < int, int > ans;
    st.clear(),mp.clear(),ans.clear();
    int n,k,a;
    cin>>n>>k;
    vector < int > v;
    for(int i=0; i<n; i++)
    {
        cin>>a;
        v.push_back(a);
        mp[a].push_back(i);
    }
    sort(v.rbegin(),v.rend());
    for(int i=0; i<k; i++)
    {
        sum+=v[i];
        int x=mp[v[i]].front();
        ans[x]=1;
        mp[v[i]].pop_front();
    }
    int cn=0,i,last=0;
    vector < int > vp;
    for(i=0; i<n; i++)
    {
        if(ans[i])
        {
            cn++;
            if(cn<k)
            {
              //  cout<<last<<" "<<i<<endl;
                vp.push_back(abs(i-last)+1),last=i+1;
            }
            else
            {
               // cout<<last<<" "<<n<<endl;
                vp.push_back(abs(last-n));
            }
            last=i+1;
        }
    }
   // cout<<endl;
    cout<<sum<<endl;
    for(auto i : vp)
        cout<<i<<" ";
    cout<<endl;
}
