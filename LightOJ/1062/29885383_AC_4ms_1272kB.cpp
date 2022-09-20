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
int tc, n, casee = 1;
double x, y, c;

double f(double mid) {
    double a = sqrt((x * x) - (mid * mid));
    double b = sqrt((y * y) - (mid * mid));
    return ((a * b) / (a + b));
}

int main() {
#ifdef cloud007
    freopen("in.txt", "r", stdin);
#endif // cloud007
    cloud_007;
    cin >> tc;
    cout << fixed << setprecision(10);
    while(tc--) {
        cin >> x >> y >> c;
        double lo = 0, hi = min(x, y), mid, eps = 1e-7;
        while(hi - lo > eps) {
            mid = (lo + hi)/2;
            if(f(mid) <= c)hi = mid;
            else lo = mid;
        }
        cout << "Case " << casee++ << ": " << hi << endl;
    }


    return 0;
}
