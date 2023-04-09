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
ll tc, n, a[sz], p[sz];

int main() {
#ifdef cloud007
    freopen("in.txt", "r", stdin);
#endif // cloud007
    cloud_007;
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> a[i] >> p[i];
    }

    ll Ans = 0, pre = 0, mn = 0, sum = 0;
    for(int i = 1; i <= n; i++) {
        if(i == 1) {
            mn = p[i], pre = i, sum = a[i];
        } else {
            if(p[i] >= mn) {
                sum += a[i];
            } else {
                Ans += sum * mn;
                mn = p[i], sum = a[i];
            }
        }
    }

    Ans += sum * mn;

    cout << Ans << endl;


    return 0;
}
