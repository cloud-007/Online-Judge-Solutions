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
map < int, int > mp, freq;

int main() {
#ifdef cloud_007
    freopen("in.txt", "r", stdin);
#endif // cloud_007
    ios_base::sync_with_stdio(false);
    cin.tie(0); //cout.tie(0);
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        mp[a[i]]++;
    }

    sort(a + 1, a + n + 1);

    ll Ans = 0;

    freq[a[1]]++; mp[a[1]]--;

    for(int i = 2; i < n; i++) {
        mp[a[i]]--;
        if(a[i] == a[2] && a[i + 1] == a[3]) {
            Ans += (ll)freq[a[1]] * (ll)mp[a[i + 1]];
        }
        freq[a[i]]++;
    }

    cout << Ans << endl;


    return 0;
}
