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
    cin >> tc;
    while(tc--) {
        cin >> n;
        for(int i = 1; i <= n; i++)cin >> a[i];
        for(int i = 1; i <= n; i++)cin >> b[i];

        sort(a + 1, a + n + 1);
        sort(b + 1, b + n + 1);

        for(int i = 1; i <= n; i++)cout << a[i] << " ";
        cout << endl;
        for(int i = 1; i <= n; i++)cout << b[i] << " ";
        cout << endl;

    }


    return 0;
}
