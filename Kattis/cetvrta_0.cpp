#include<bits/stdc++.h>
#define S second
#define FastRead ios_base::sync_with_stdio(false);cin.tie(0),cout.tie(0);cin.tie(0),cout.tie(0);
#define ll long long int
using namespace std;
int main()
{
    FastRead;
    ll i,j,a,b,a1,b1,a2,b2,n,m,k,t,x,y;
    map< ll,ll >mp,mp1;
    cin>>a>>b>>a1>>b1>>a2>>b2;
    mp[a]++;mp[a1]++;mp[a2]++;
    mp1[b]++;mp1[b1]++;mp1[b2]++;
    for(auto i:mp){
        if(i.S==1){
            cout<<i.first<<" ";
            break;
        }
    }
    for(auto i:mp1){
        if(i.S==1){
            cout<<i.first<<endl;
            break;
        }
    }

    return 0;
}