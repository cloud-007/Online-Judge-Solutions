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
        bool allZero = false;
        int negativeSum = 0, positiveSum = 0;
        cin >> n;
        for(int i = 1; i <= n; i++) {
            cin >> a[i];
            allZero |= (a[i] != 0);
            if(a[i] < 0)negativeSum += abs(a[i]);
            else positiveSum += a[i];
        }
        if(!allZero || negativeSum == positiveSum) {
            cout << "NO" << endl;
            continue;
        }
        sort(a + 1, a + n + 1);
        bool ok = true;
        int sum = 0;
        for(int i = 1; i <= n; i++) {
            sum += a[i];
            if(!sum) {
                ok = false;
                break;
            }
        }
        if(ok) {
            cout << "YES" << endl;
            for(int i = 1; i <= n; i++)cout << a[i] << " ";
            cout << endl;
            continue;
        }
        reverse(a + 1, a + n + 1);
        cout << "YES" << endl;
        for(int i = 1; i <= n; i++)cout << a[i] << " ";
        cout << endl;
    }


    return 0;
}
