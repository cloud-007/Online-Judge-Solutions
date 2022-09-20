#include<bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(0)

int fact(int n)
{
    int ans=1;
    if(n==1)
    return 1;
    else
        return n*fact(n-1);

}

main()
{
    fast;
    int a,b;
    cin>>a>>b;
    int ans=0;
    cout<<fact(min(a,b))<<endl;
}
