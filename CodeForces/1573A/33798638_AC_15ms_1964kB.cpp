/*One touch and i IGNITE*/
#include<bits/stdc++.h>
using namespace std;
#define To_Infinity_And_Beyond ios_base::sync_with_stdio(false),cin.tie(0)
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
    To_Infinity_And_Beyond;
    cin >> tc;
    while(tc--) {
        string s; cin >> n >> s;
        int i = 0, j = n - 1, Ans = 0, cnt = 0, zero = 0;
        for(auto i : s) {
            if(i == '0') continue;
            Ans += i - '0'; ++cnt;
        }
        if(s[n - 1] - '0')--cnt;
        Ans += cnt;
        cout << Ans << endl;
    }


    return 0;
}
