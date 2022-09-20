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
    ll a,b,c,d,t,n,m,i,j,sum=0,ans=0;
    string s;
    cin>>n;
    vector< ll >v;
    for(i=0;i<n;i++){
        cin>>a;
        v.pb(a);
    }
    cin>>s;
    for(i=0;i<n;i++){
        if(s[i]=='1'){
            ans+=v[i];
            ans=max(sum,ans);
            sum+=v[i];
        }
        else{
            sum+=v[i];
        }
    }
    cout<<ans<<endl;

    return 0;

}

