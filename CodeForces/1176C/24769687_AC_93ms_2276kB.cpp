#include<bits/stdc++.h>
using namespace std;

deque < int > x[50];
int fx[]= {4,8,15,16,23,42};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    int n,a;
    cin>>n;
    for(int i=0; i<n; i++)
    {
        cin>>a;
        x[a].push_back(i);
    }
    for(int i=0; i<6; i++)
        sort(x[i].begin(),x[i].end());
    int pos,sum=0,cnt;
    while(true)
    {
        bool fl=true;
        if(x[4].size())
            pos=x[4][0],cnt=1;
        else
            break;
        x[4].pop_front();
        for(int i=1; i<6; i++)
        {
            if(x[fx[i]].size())
            {
                bool ok=true;
                int j=0;
                while(x[fx[i]].size())
                {
                    if(x[fx[i]].front()>pos)
                    {
                        cnt++;
                        pos=x[fx[i]].front();
                        x[fx[i]].pop_front();
                        ok=false;
                        break;
                    }
                    x[fx[i]].pop_front();
                }
                if(ok)
                {
                    fl=false;
                    break;
                }
            }
        }
        if(!fl)
            break;
        if(cnt==6)
            sum+=6;
    }
    cout<<n-sum<<endl;
}
