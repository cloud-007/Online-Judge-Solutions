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
ll tc, n, k, a[sz];

int main() {
#ifdef cloud007
    freopen("in.txt", "r", stdin);
#endif // cloud007
    cloud_007;
    cin >> n >> k;
    for(int i = 1; i <= n; i++)cin >> a[i];
    int med = (n + 1) / 2;
    sort(a + 1, a + n + 1);
    reverse(a + 1, a + n + 1);
    int pre = med - 1;
    while(pre >= 1) {
        ll lagbe = (a[pre] - a[med]) * (med - pre);
        if(k >= lagbe) {
            a[med] = a[pre], k -= lagbe;
            pre--;
        } else {
            int tot = k / (med - pre);
            a[med] += tot;
            k -= (tot) * (med - pre);
            break;
        }
    }

    ll possible = k / med;

    cout << a[med] + possible << endl;


    return 0;
}
