#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    cin.tie(0),cout.tie(0);
    ll n,q;
    cin>>n>>q;
    ll c=n/2;
    if(n%2)
    {
        c++;
    }
    ll fx[]= {c,n-c},fy[]= {fx[1],fx[0]};
    ll st=0,nx;
    nx=n*n;
    if(nx%2)
    {
        nx/=2;
        nx++;
    }
    else
        nx/=2;
    while(q--)
    {
        ll x,y;
        cin>>x>>y;
        if((x+y)%2==0)
        {
            ll add=0;
            ll z=x-1;
            if(z%2)
            {
                add+=fx[0]*((z/2)+1);
                add+=fx[1]*(z/2);
            }
            else
            {
                add+=fx[0]*(z/2);
                add+=fx[1]*(z/2);
            }
            add+=(y+1)/2;
            cout<<st+add<<endl;
        }
        else
        {
            ll add=0,j=0;
            ll z=x-1;
            if(z%2)
            {
                if(n%2==0)
                {
                    add+=fx[0]*((z/2)+1);
                    add+=fx[1]*(z/2);
                }
                else
                {
                    add+=fy[0]*((z/2)+1);
                    add+=fy[1]*(z/2);
                }
            }
            else
            {
                if(n%2==0)
                {
                    add+=fx[0]*(z/2);
                    add+=fx[1]*(z/2);
                }
                else
                {
                    add+=fy[0]*(z/2);
                    add+=fy[1]*(z/2);
                }
            }
            add+=(y+1)/2;
            cout<<nx+add<<endl;
        }
    }
}
