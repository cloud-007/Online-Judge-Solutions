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
    cin >> tc;
    while(tc--) {
        int x; cin >> n >> x;
        int sum = 0; bool flag = true;
        for(int i = 1; i <= n; i++) {
            cin >> a[i];
            sum += a[i];
            if(a[i] % x)flag = false;
        }
        if(flag) {
            cout << -1 << endl;
            continue;
        }
        if(sum % x) {
            cout << n << endl;
            continue;
        }
        int Ans = -1;
        for(int i = 1; i <= n; i++) {
            if(a[i] % x) {
                Ans = max(Ans, n - i);
                break;
            }
        }
        for(int i = n; i >= 1; i--) {
            if(a[i] % x) {
                Ans = max(Ans, i - 1);
                break;
            }
        }

        cout << Ans << endl;
    }


    return 0;
}
