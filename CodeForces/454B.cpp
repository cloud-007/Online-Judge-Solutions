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
    for(int i = 1; i <= n; i++)cin >> a[i];
    bool flag = false;
    int Ans = 0;

    for(int i = 1; i < n; i++) {
        if(a[i] > a[i + 1]) {
            if(i + 2 <= n && a[i + 1] > a[i + 2])flag = true;
            if(!is_sorted(a + i + 1, a + n + 1) || a[n] > a[1])flag = true;
            Ans = n - i;
            break;
        }
    }

    if(flag)cout << -1 << endl;
    else cout << Ans << endl;


    return 0;
}
