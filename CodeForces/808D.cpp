/*One touch and i IGNITE*/
#include<bits/stdc++.h>
using namespace std;
#define cloud_007 ios_base::sync_with_stdio(false),cin.tie(0)
#define ll long long
#define F first
#define S second
#define endl "\n"
#define Endl "\n"

const int sz = 2e5 + 5;
ll tc, n, a[sz], sum, cur;
map < ll, int > mp, pref;

int main() {
#ifdef cloud007
    freopen("in.txt", "r", stdin);
#endif // cloud007
    cloud_007;
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        sum += a[i];
        mp[a[i]]++;
    }

    if(sum & 1) {
        cout << "NO" << endl;
        exit(0);
    }

    bool ok = false;

    for(int i = 1; i <= n; i++) {
        mp[a[i]]--;
        pref[a[i]]++;
        cur += a[i], sum -= a[i];
        if(sum == cur)ok = true;
        else if(sum > cur) {
            ll dif = sum - cur;
            if(dif & 1)continue;
            dif /= 2;
            if(mp[dif])ok = true;
        } else {
            ll dif = cur - sum;
            if(dif & 1)continue;
            dif /= 2;
            if(pref[dif])ok = true;
        }
    }


    cout << (ok ? "YES" : "NO") << endl;


    return 0;
}
