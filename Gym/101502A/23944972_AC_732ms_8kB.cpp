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
        int y,x;
        cin>>y>>x;
        long long tot=y*100;
        long long one=100+x;
        long long sum=one;
        int cnt=0;
        while(sum<=tot)
        {
            cnt++;
            sum+=one;
        }
        cout<<cnt<<endl;
    }
}
