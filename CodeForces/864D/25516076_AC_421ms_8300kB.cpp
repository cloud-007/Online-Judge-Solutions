#include<bits/stdc++.h>
using namespace std;
int main()
{
    cin.tie(0),cout.tie(0);
    int n;
    cin>>n;
    deque < int > dq;
    int a[n+5];
    map < int, int > mp;
    mp.clear();
    for(int i=1; i<=n; i++)
    {
        cin>>a[i];
        mp[a[i]]++;
    }
    for(int i=1; i<=n; i++)
    {
        if(!mp[i])
            dq.push_back(i);
    }
    int cnt=0;
    bool fl[n];
    memset(fl, false, sizeof fl);
    for(int i=1; i<=n; i++)
    {
        if(mp[a[i]]>1)
        {
            if(dq.front()<a[i] || fl[a[i]])
            {
                if(dq.size())
                {
                    mp[a[i]]--;
                    a[i]=dq.front();
                    cnt++;
                    dq.pop_front();
                    fl[a[i]]=false;
                }
            }
            else
            {
                fl[a[i]]=true;
            }
        }
    }
    cout<<cnt<<endl;
    for(int i=1; i<=n; i++)
        cout<<a[i]<<" ";
    cout<<endl;
}
