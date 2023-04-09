/*One touch and i IGNITE*/
#include<bits/stdc++.h>
using namespace std;
#define To_Infinity_And_Beyond ios_base::sync_with_stdio(false),cin.tie(0)
#define ll long long
#define F first
#define S second
#define endl "\n"
#define Endl "\n"

const int N = 2e5 + 5;
ll tc, n, k, a[N];

int main() {
#ifdef cloud_007
    freopen("in.txt", "r", stdin);
#endif // cloud_007
    To_Infinity_And_Beyond;
    map < ll, ll > mp, boro, chuto, done;
    cin >> n >> k;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        mp[a[i]]++;
    }

    ll Ans = 0;
    for(int i = 1; i <= n; i++) {
        if(done[a[i]])continue;
        done[a[i]] = true;
        ll lagbe = a[i] + k;
        if(!boro[lagbe])Ans += mp[a[i]] * mp[lagbe], boro[lagbe] = true;
        lagbe = a[i] - k;
        if(!chuto[lagbe])Ans += mp[a[i]] * mp[lagbe], chuto[lagbe] = true;
    }

    Ans/=2;

    cout << Ans << endl;


    return 0;
}
