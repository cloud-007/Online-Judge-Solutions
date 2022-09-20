#include<bits/stdc++.h>
#define ll long long int
#define F first
#define S second
#define pb push_back
#define FastRead ios_base::sync_with_stdio(false);cin.tie(0),cout.tie(0);cin.tie(0),cout.tie(0);
using namespace std;
int main()
{
    FastRead;
    ll a,b,c,d,t,n,m,i,j,k;
    cin>>n>>k;
    if(k==0 || n==k){
        cout<<0<<" "<<0<<endl;
        return 0;
    }
    cout<<1<<" "<<min(2*k,n-k)<<endl;
    return 0;

}
