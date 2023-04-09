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
    int k; cin >> n >> k;
    if(n == k)cout << -1 << endl;
    else if(n - k == 1)for(int i = 1; i <= n; i++)cout << i << " ";
    else {
        for(int i = 1; i < n; i++) {
            a[i] = i + 1;
        }
        a[n] = 1; int idx = 2;
        while(k > 1) {
            swap(a[idx], a[idx + 1]);
            k -= 2; idx += 2;
        }
        if(k)swap(a[1], a[n]);
        if(n & 1 && k) {
            swap(a[n], a[n - 1]);
            swap(a[1], a[n - 1]);
        }
        for(int i = 1; i <= n; i++)cout << a[i] << " ";
        cout << endl;
    }


    return 0;
}
