/*One touch and i IGNITE*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define F first
#define S second
#define endl "\n"
#define Endl "\n"

const int N = 2e5 + 5;
int tc, n, casee = 1, a[N], b[N];

int main() {
#ifdef cloud_007
    freopen("in.txt", "r", stdin);
#endif // cloud_007
    ios_base::sync_with_stdio(false);
    cin.tie(0); //cout.tie(0);
    cin >> n;
    for(int i = 1; i <= n; i++)cin >> a[i];
    sort(a + 1, a + n + 1);
    int i = (n + 1) / 2, j = n, cnt = 1, k = 1;

    while(cnt <= n) {
        b[k++] = a[i--]; ++cnt;
        if(cnt > n)break;
        b[k++] = a[j--]; ++cnt;
    }

    bool ok = true;

    for(int i = 2; i <= n; i += 2) {
        if(b[i] <= b[i - 1] || b[i] <= b[i + 1]) {
            ok = false;
            break;
        }
    }

    if(!ok)cout << -1 << endl;
    else {
        for(int i = 1; i <= n; i++)cout << b[i] << " ";
        cout << endl;
    }


    return 0;
}
