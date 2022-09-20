/*One touch and i IGNITE*/
#include<bits/stdc++.h>
using namespace std;
#define cloud_007 ios_base::sync_with_stdio(false),cin.tie(0)
#define ll long long
#define F first
#define S second
#define endl "\n"
#define Endl "\n"

const int sz = 1e5 + 5;
int n, a[sz];

int main() {
#ifdef cloud007
    freopen("in.txt", "r", stdin);
#endif // cloud007
    cloud_007;
    cin >> n;

    for(int i = 1; i <= n; i++)cin >> a[i];
    int mx = 0, cnt = 0;
    a[0] = INT_MAX;

    for(int i = 1; i <= n; i++) {
        if(a[i] <= a[i - 1])cnt++;
        else mx = max(mx, cnt), cnt = 1;
    }

    mx = max(mx, cnt);

    cout << mx-1 << endl;

    return 0;
}
