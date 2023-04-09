#include<bits/stdc++.h>
#define ll long long int
#define F first
#define S second
#define pb push_back
#define FastRead ios_base::sync_with_stdio(false);cin.tie(0),cout.tie(0);cin.tie(0),cout.tie(0);
using namespace std;
ll cnt[1000005];
int main()
{
    FastRead;
    ll a,b,c=0,d,t,n,m,i,j,k=0;
    cin>>n>>b;
    for(i=0;i<n;i++){
        cin>>a;
        if(cnt[a]>=cnt[b]){
            cnt[a]++;
        }
        if(cnt[k]<cnt[a]){
            if(a==b)c++;
            else k=a;
        }
    }
    if(c==0){
        cout<<k<<endl;
    }
    else cout<<-1<<endl;
    return 0;

}
