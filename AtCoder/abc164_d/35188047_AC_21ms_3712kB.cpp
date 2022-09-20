/*One touch and i IGNITE*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define F first
#define S second
#define endl "\n"
#define Endl "\n"

const int N = 2e5 + 5, mod = 2019;
int tc, n, casee = 1, a[N];

int main() {
#ifdef cloud_007
    freopen("in.txt", "r", stdin);
#endif // cloud_007
    ios_base::sync_with_stdio(false);
    cin.tie(0); //cout.tie(0);
    string s; cin >> s;
    map <int, int> mp;
    mp[0] = 1;

    ll powerOfTen = 1, Ans = 0, sum = 0;

    for(int i = s.size() - 1; i >= 0; i--) {
        sum += (s[i] - '0') * powerOfTen;
        sum %= mod;
        Ans += mp[sum]++;
        powerOfTen *= 10;
        powerOfTen %= mod;
    }

    cout << Ans << endl;


    return 0;
}
