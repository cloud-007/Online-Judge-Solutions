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
ll Ans = 0;

int main() {
#ifdef cloud_007
    freopen("in.txt", "r", stdin);
#endif // cloud_007
    ios_base::sync_with_stdio(false);
    cin.tie(0); //cout.tie(0);
    cin >> n;
    for(int i = 1; i <= n; i++)cin >> a[i];
    int last = INT_MAX;
    for(int i = n; i >= 1 && last > 0; i--) {
        int cur = min(a[i], last - 1);
        Ans += cur;
        last = cur;
    }

    cout << Ans << endl;


    return 0;
}
