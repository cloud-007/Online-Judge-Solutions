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
    map < int, int > mp;
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        mp[a[i]]++;
    }
    sort(a + 1, a + n + 1);
    ll Ans = 0;
    for(int i = 1; i <= n; i++) {
        mp[a[i]]--;
        for(int j = 0; j < 31; j++) {
            int cur = 1 << j;
            if(cur <= a[i])continue;
            int req = cur - a[i];
            Ans += mp[req];
        }
    }

    cout << Ans << endl;


    return 0;
}
