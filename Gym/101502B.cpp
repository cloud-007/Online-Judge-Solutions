#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tc;
    cin>>tc;
    while(tc--)
    {
        int n;
        cin>>n;
        map < int , int > row, col;
        vector < int > vp;
        while(n--)
        {
            int u , v ;
            cin>>u>>v;
            row[u]++;
            vp.push_back(v);
        }
        long long cnt=0;
        for(auto i : vp)
        {
            cnt+=row[i];
        }
        cout<<cnt<<endl;
    }
}
