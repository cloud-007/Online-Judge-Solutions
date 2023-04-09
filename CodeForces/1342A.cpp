#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    int tc;
    cin>>tc;
    while(tc--)
    {
        ll a,b,x,y,sum=0;
        cin>>x>>y>>a>>b;
        if(a*2<=b)
        {
            sum+=(x*a);
            sum+=(y*a);
        }
        else
        {
            if(x>y)
                swap(x,y);
            sum+=x*b;
            y-=x;
            sum+=y*a;
        }
        cout<<sum<<endl;
    }
}
