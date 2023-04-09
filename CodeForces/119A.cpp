/*One touch and i IGNITE*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define F first
#define S second
#define endl "\n"
#define Endl "\n"

const int N = 2e5 + 5;
int tc, n;

int main() {
#ifdef cloud_007
    freopen("in.txt", "r", stdin);
#endif // cloud_007
    ios_base::sync_with_stdio(false);
    cin.tie(0); //cout.tie(0);
    int a, b ;
    cin >> a >> b >> n;

    bool Ans = true;

    while(n > 0) {
        int cur ;
        if(Ans) {
            cur = __gcd(a, n);
        } else {
            cur = __gcd(b, n);
        }
        n -= cur;
        Ans ^= 1;
    }

    cout << (Ans ? 1 : 0) << endl;


    return 0;
}
