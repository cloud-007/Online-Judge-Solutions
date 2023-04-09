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
int tc, n, x, a[sz], mp[sz];
set < int > st;

int main() {
#ifdef cloud007
    freopen("in.txt", "r", stdin);
#endif // cloud007
    cloud_007;
    cin >> n >> x;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        st.insert(a[i]);
        mp[a[i]]++;
    }


    ll Ans = 0;

    for(auto i : st) {
        int lagbe = x ^ i;
        if(lagbe == i) {
            Ans += ((ll)mp[lagbe] * (ll)(mp[lagbe] - 1)) / 2;
        } else Ans += (ll)mp[lagbe] * (ll)mp[i];
        mp[i] = 0;
    }

    cout << Ans << endl;

    return 0;
}
