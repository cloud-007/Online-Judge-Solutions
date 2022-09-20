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
    string s; cin >> n >> s;
    int l = 0, r = 0, u = 0, d = 0, Ans = n, x = 0, y = 0;
    for(auto i : s) {
        if(i == 'L')--x, ++l;
        else if(i == 'R')++x, ++r;
        else if(i == 'U')++y, ++u;
        else --y, ++d;
    }

    if(x > 0 && r >= x)Ans -= x;
    else if(x < 0 && l >= x)Ans -= abs(x);
    else if(x) {
        cout << 0 << endl;
        exit(0);
    }
    if(y > 0 && u >= y)Ans -= y;
    else if(y < 0 && d >= y) Ans -= abs(y);
    else if(y) {
        cout << 0 << endl;
        exit(0);
    }

    cout << Ans << endl;



    return 0;
}
