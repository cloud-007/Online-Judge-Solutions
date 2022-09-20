/*One touch and i IGNITE*/
#include<bits/stdc++.h>
using namespace std;
#define To_Infinity_And_Beyond ios_base::sync_with_stdio(false),cin.tie(0)
#define ll long long
#define F first
#define S second
#define endl "\n"
#define Endl "\n"

const int N = 2e6 + 5;
int tc, n, casee = 1, a[N], mp[10];

int main() {
#ifdef cloud_007
    freopen("in.txt", "r", stdin);
#endif // cloud_007
    To_Infinity_And_Beyond;
    cin >> tc;
    while(tc--) {
        memset(mp, -1, sizeof mp);
        cin >> n;
        for(int i = 1; i <= n; i++)cin >> a[i];
        int x = -1, y = -1, xId = -1, yId = -1;
        for(int i = 1; i < n; i++) {
            if(a[i] >= a[i + 1])continue;
            x = 0;
        }
        if(x == -1) {
            cout << x << endl;
            continue;
        }
        for(int i = 1; i <= n; i++) {

            int cur = mp[a[i]];
            if(cur != -1) {
                if(xId < cur) {
                    xId = cur, yId = i;
                } else if(cur >= xId && a[i] <= a[yId]) {
                    yId = i;
                }
            }

            for(int j = a[i] + 1; j <= 9; j++)mp[j] = i;
        }
        swap(a[xId], a[yId]);
        sort(a + xId + 1, a + n + 1);
        for(int i = 1; i <= n; i++)cout << a[i];
        cout << endl;
    }


    return 0;
}
