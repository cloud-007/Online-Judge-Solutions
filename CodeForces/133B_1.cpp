/*One touch and i IGNITE*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define F first
#define S second
#define endl "\n"
#define Endl "\n"

const int N = 2e5 + 5, mod = 1e6 + 3 ;
int tc, n, casee = 1, a[N];

int main() {
#ifdef cloud_007
    freopen("in.txt", "r", stdin);
#endif // cloud_007
    ios_base::sync_with_stdio(false);
    cin.tie(0); //cout.tie(0);
    map < char, string > mp;
    mp['>'] = "1000";
    mp['<'] = "1001";
    mp['+'] = "1010";
    mp['-'] = "1011";
    mp['.'] = "1100";
    mp[','] = "1101";
    mp['['] = "1110";
    mp[']'] = "1111";
    string s, Ans = "";

    cin >> s;

    for(auto i : s)Ans += mp[i];

    reverse(Ans.begin(), Ans.end());

    ll cur = 1, tot = 0;

    for(auto i : Ans) {
        if(i == '1') {
            tot += cur;
            tot %= mod;
        }

        cur *= 2;
        cur %= mod;
    }

    cout << tot << endl;



    return 0;
}
