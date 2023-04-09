#include<bits/stdc++.h>
#define S second
#define FastRead ios_base::sync_with_stdio(false);cin.tie(0),cout.tie(0);cin.tie(0),cout.tie(0);
#define ll long long int
using namespace std;
int main()
{
    FastRead;
    ll i,j,a,b,a1,b1,a2,b2,n,m,k,t,x,y,c=0,cnt=0;
    vector< ll >v,u(1000005);
    cin>>n>>k;
    for(i=2;i<=n;i++){
        for(j=2;j*j<=i;j++){
            if(i%j==0)c++;
        }
        if(c>0)c=0;
        v.push_back(i);
    }
    for(i=0;i<v.size();i++){
        for(j=v[i];j<=n;j+=v[i]){
            if(u[j]==0){
                u[j]=1;
                cnt++;
                if(cnt==k){
                    cout<<j<<endl;
                    return 0;
                }
            }
        }
    }

    return 0;
}
