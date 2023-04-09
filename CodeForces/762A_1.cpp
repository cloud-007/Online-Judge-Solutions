/*One touch and i IGNITE*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define F first
#define S second
#define endl "\n"
#define Endl "\n"

const int N = 2e5 + 5;
ll tc, n, k;

int main() {
#ifdef cloud_007
    freopen("in.txt", "r", stdin);
#endif // cloud_007
    ios_base::sync_with_stdio(false);
    cin.tie(0); //cout.tie(0);
    vector < ll > v;
    cin >> n >> k;
    for(ll i = 1; i * i <= n; i++) {
        if(n % i == 0) {
            v.push_back(i);
            if(n / i != i)v.push_back(n / i);
        }
    }
    sort(v.begin(), v.end());
    if(v.size() < k)cout << -1 << endl;
    else {
        cout << v[k - 1] << endl;
    }


    return 0;
}
