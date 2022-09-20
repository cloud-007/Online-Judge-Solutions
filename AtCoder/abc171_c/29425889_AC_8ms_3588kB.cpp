/*One touch and i IGNITE*/
#include<bits/stdc++.h>
using namespace std;
#define cloud_007 ios_base::sync_with_stdio(false),cin.tie(0)
#define ll long long
#define F first
#define S second
#define endl "\n"
#define Endl "\n"

const int sz = 2e5 + 5;
ll n;

int main() {
#ifdef cloud007
    freopen("in.txt", "r", stdin);
#endif // cloud007
    cloud_007;
    cin >> n;
    string ans = "";
    while(n) {
        --n;
        int now = n % 26;
        char c = now + 97;
        ans += c;
        n /= 26;
    }
    reverse(ans.begin(), ans.end());
    cout << ans << endl;


    return 0;
}
