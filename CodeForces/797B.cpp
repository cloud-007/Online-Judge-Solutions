/*One touch and i IGNITE*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define F first
#define S second
#define endl "\n"
#define Endl "\n"

const int N = 2e5 + 5;
int tc, n, casee = 1, a[N];

int main() {
#ifdef cloud_007
    freopen("in.txt", "r", stdin);
#endif // cloud_007
    ios_base::sync_with_stdio(false);
    cin.tie(0); //cout.tie(0);
    cin >> n;

    int mxNegativeOdd = -INT_MAX, sum = 0, mnOdd = INT_MAX, mnPosOdd = INT_MAX;

    while(n--) {
        int x; cin >> x;
        if(x >= 0)sum += x;
        else if(x & 1 && x < 0) mxNegativeOdd = max(mxNegativeOdd, x);
        if(x & 1)mnOdd = min(mnOdd, x);
        if(x & 1 && x > 0)mnPosOdd = min(mnPosOdd, x);
    }

    if(sum % 2 == 0) {
        if(mxNegativeOdd != -INT_MAX && mnPosOdd != INT_MAX) {
            if(abs(mxNegativeOdd) < mnPosOdd)sum += mxNegativeOdd;
            else sum -= mnPosOdd;
        } else if(mxNegativeOdd != -INT_MAX)sum += mxNegativeOdd;
        else sum -= mnOdd;
    }

    cout << sum << endl;


    return 0;
}
