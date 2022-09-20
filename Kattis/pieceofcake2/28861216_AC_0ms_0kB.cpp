/*One touch and i IGNITE*/
#include<bits/stdc++.h>
using namespace std;
#define cloud_007 ios_base::sync_with_stdio(false),cin.tie(0)
#define ll long long
#define F first
#define S second
#define endl "\n"
#define Endl "\n"

const int sz = 1e5 + 5;
int tc, n, h, b;

int main() {
#ifdef cloud007
    freopen("in.txt", "r", stdin);
#endif // cloud007
    cloud_007;
    cin >> n >> h >> b;
    int rem_h = n - h, rem_l = n - b;
    int a = h * b, bb = h * rem_l, c = b * rem_h, d = rem_h * rem_l;
    cout << max({a, bb, c, d})*4 << endl;
    //cout << rem_l << " " << rem_h << endl;

    return 0;
}
