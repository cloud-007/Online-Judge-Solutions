/*One touch and i IGNITE*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define F first
#define S second
#define endl "\n"
#define Endl "\n"

const int N = 3e5 + 5;
int tc, n, k, casee = 1, a[N], pref[N][2];

int main() {
#ifdef cloud_007
    freopen("in.txt", "r", stdin);
#endif // cloud_007
    ios_base::sync_with_stdio(false);
    cin.tie(0); //cout.tie(0);
    cin >> n >> k;
    for(int i = 1; i <= n; i++) {
        int x; cin >> x;
        pref[i][1] = pref[i - 1][1] + (x == 1);
        pref[i][0] = pref[i - 1][0] + (x == 0);
        a[i] = x;
    }
    int Ans = k, startingIdx = -1;

    for(int i = 1; i <= n; i++) {
        int cur = pref[i][0], curK = k;
        if(k) {
            curK -= a[i] == 0;
        } else if(a[i] == 0) continue;
        int l = i, r = n;
        while(l <= r) {
            int mid = (l + r) >> 1;
            if(pref[mid][0] - cur <= curK)l = mid + 1;
            else r = mid - 1;
        }
        if(l - i > Ans) {
            Ans = l - i;
            startingIdx = i;
        }
    }

    if(startingIdx == -1)startingIdx = 1;

    for(int i = startingIdx; i < startingIdx + Ans; i++) {
        a[i] = 1;
    }

    cout << Ans << endl;
    for(int i = 1; i <= n; i++)cout << a[i] << " ";
    cout << endl;


    return 0;
}
