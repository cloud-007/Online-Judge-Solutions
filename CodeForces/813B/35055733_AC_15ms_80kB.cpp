/*One touch and i IGNITE*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define F first
#define S second
#define endl "\n"
#define Endl "\n"

const int N = 2e5 + 5;

int main() {
#ifdef cloud_007
    freopen("in.txt", "r", stdin);
#endif // cloud_007
    ios_base::sync_with_stdio(false);
    cin.tie(0); //cout.tie(0);
    int64_t x, y, l, r, a, b, __x = 1, __y = 1;
    cin >> x >> y >> l >> r;
    vector < int64_t > v, A, B;

    A.push_back(1);
    B.push_back(1);

    for(ll i = 1;; i++) {
        if(1e18 / x < __x)break;
        __x *= x;
        if(__x > 1e18)break;
        A.push_back(__x);
    }

    for(ll i = 1;; i++) {
        if(1e18 / y < __y)break;
        __y *= y;
        if(__y > 1e18)break;
        B.push_back(__y);
    }

    for(auto i : A) {
        for(auto j : B) {
            if(i + j >= l && i + j <= r)v.push_back(i + j);
        }
    }

    sort(v.begin(), v.end());

    int64_t Ans = 0;
    if(v.size()) {
        Ans = v[0] - l;
        for(int i = 0; i < v.size() - 1; i++) {
            Ans = max(Ans, v[i + 1] - v[i] - 1);
        }
        Ans = max(Ans, r - v[v.size() - 1]);
    } else Ans = r - l + 1;

    cout << Ans << endl;


    return 0;
}
