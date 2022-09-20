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
        float m;
        cin>>n>>m;
        int x= ceil(n*m);
        int cnt=0;
        while(n--)
        {
            int a;
            cin>>a;
            if(a>=50)cnt++;
        }
        puts(cnt>=x?"YES":"NO");
    }
}
