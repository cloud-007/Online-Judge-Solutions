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
map < int, int > mp;

int main() {
#ifdef cloud_007
    freopen("in.txt", "r", stdin);
#endif // cloud_007
    ios_base::sync_with_stdio(false);
    cin.tie(0); //cout.tie(0);
    cin >> n;
    while(n--) {
        int l, r; cin >> l >> r;
        mp[l]++, mp[r + 1]--;
    }

    int sum = 0, ok = 1;

    for(auto i : mp) {
        sum += i.S;
        if(sum > 2) {
            ok = false;
        }
    }

    cout << (ok ? "YES" : "NO") << endl;


    return 0;
}
