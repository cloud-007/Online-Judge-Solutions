/*One touch and i IGNITE*/
#include<bits/stdc++.h>
using namespace std;
#define cloud_007 ios_base::sync_with_stdio(false),cin.tie(0)
#define ll long long
#define F first
#define S second
#define endl "\n"
#define Endl "\n"

const int sz = 55;
ll n;

int check(ll x) {
    int cnt = 0;
    while(x) {
        cnt++;
        x /= 10;
    }
    return cnt;
}

int main() {
#ifdef cloud007
    freopen("in.txt", "r", stdin);
#endif // cloud007
    cloud_007;
    cin >> n;
    cout << (n < 1200 ? "ABC" : "ARC") << endl;

    return 0;
}
