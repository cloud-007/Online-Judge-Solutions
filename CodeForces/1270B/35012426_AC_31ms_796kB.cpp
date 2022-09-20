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
        cin >> n;
        for(int i = 1; i <= n; i++)cin >> a[i];
        int Ans = -1;
        for(int i = 2; i <= n; i++) {
            if(abs(a[i] - a[i - 1]) >= 2) {
                Ans = i - 1;
                break;
            }
        }
        if(~Ans) {
            cout << "YES" << endl;
            cout << Ans << " " << Ans + 1 << endl;
        } else {
            cout << "NO" << endl;
        }
    }


    return 0;
}
